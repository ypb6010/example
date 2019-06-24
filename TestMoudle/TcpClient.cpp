#include "stable.h"
#include "TcpClient.h"
#include "IMsgCall.h"

const uint32_t BUFFER_SIZE = 1024 * 1024 * 10;
static boost::array<unsigned char,4> const g_head	= { 0x01,0x17,0x17,0x01 };
static boost::array<unsigned char,4> const g_end	= { 0x04,0x17,0x17,0x04 };
std::string const TcpClient::s_end(reinterpret_cast<char const*>(g_end.data()), g_end.size());
std::string const TcpClient::s_head(reinterpret_cast<char const *>(g_head.data()), g_head.size());


TcpClient::TcpClient(std::string& host, uint16_t port)
	: m_rbuf(BUFFER_SIZE, 0)
	, m_ep(address_type::from_string(host), port)
	, m_isFinished(true)
{
	start();
	lasttime = std::chrono::system_clock::now();
}

TcpClient::~TcpClient()
{
	m_sock->close();
}

void TcpClient::run()
{
	m_io.run();
}

void TcpClient::pushMsg(msg_type const& msg)
{
	debug_out << std::string(msg.data()) << std::endl;
	(*m_unpack)(boost::cref(msg));
}

void TcpClient::start()
{
	if (!m_sock)
	{
		m_sock = sock_ptr(new socket_type(m_io));
	}

	if (!m_unpack)
	{
		m_unpack = boost::make_shared<msg_signal_t>();
	}

	if (!m_errSignal)
	{
		m_errSignal = boost::make_shared<net_err_signal_t>();
	}

	m_sock->async_connect(m_ep, bind(&this_type::conn_handler, this, boost::asio::placeholders::error));
}

void TcpClient::close()
{
	m_sock->close();
}

void TcpClient::sendMsg(std::string const& strMsg)
{
	int32_t nSize = 0;					///报文大小

	//___________________________________________________________
	//|	包头验证字	|	报文大小	|报文内容		|包尾验证字	|
	//|	"begin"		|	int nsize	|body			|"end"		|
	//-----------------------------------------------------------
	m_sbuf.resize(g_head.size() + sizeof(int32_t) + strMsg.size()  + g_end.size());
	nSize = strMsg.size();
	memcpy_s(m_sbuf.data(), m_sbuf.size(), g_head.data(), g_head.size());												///写入begin
	memcpy_s(m_sbuf.data() + g_head.size(), m_sbuf.size() - g_head.size(), &nSize, sizeof(int32_t));					///写入报文大小
	memcpy_s(m_sbuf.data() + g_head.size() + sizeof(int32_t),
		m_sbuf.size() - g_head.size() - sizeof(int32_t), strMsg.c_str(), strMsg.size());								///写入报文体

	memcpy_s(m_sbuf.data() + g_head.size() + sizeof(int32_t) + strMsg.size(),
		m_sbuf.size() - g_head.size() - sizeof(int32_t) - strMsg.size(),
		g_end.data(), g_end.size());																					///写入报文尾
	m_sock->async_write_some(boost::asio::buffer(m_sbuf), boost::bind(&this_type::write_handler, this, boost::asio::placeholders::error));
}

bool TcpClient::isRun() const
{
	return !m_io.stopped();
}

void TcpClient::attch(msg_slot_t fun)
{
	m_unpack->connect(fun);
}

void TcpClient::registerErrorCallBack(net_err_slot_t fun)
{
	m_errSignal->connect(fun);
}

void TcpClient::conn_handler(const boost::system::error_code& ec)
{
	if (ec)
	{
		(*m_errSignal)(std::string(ec.message()));
		debug_out << "连接超时或未找到服务器" << std::endl;
		return;
	}
	m_sock->async_read_some(boost::asio::buffer(m_rbuf), bind(&this_type::read_handler, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
}

void TcpClient::read_handler(const boost::system::error_code& ec, std::size_t bytes_transferred)
{
	if (ec)
	{
		(*m_errSignal)(std::string(ec.message()));
		return;
	}
	debug_out << BOOST_CURRENT_FUNCTION << std::endl;
	debug_out << "bytes_transferred：" << bytes_transferred << std::endl;

	///记录上次连接
	lasttime = std::chrono::system_clock::now();
	//___________________________________________________________
	//|	包头验证字	|	报文大小	|报文内容		|包尾验证字	|
	//|	"begin"		|	int nsize	|body			|"end"		|
	//-----------------------------------------------------------
	// 1. 数据包过来先查看报文头，找不到视为废包
	// 2. 数据包其次查看报文大小，报文大小指定向后读取字节数
	// 3. 报文大小值小于接收到的数据报文大小（要把报文头，报文尾，报文大小本身除外计算字节数），没有接收完整，继续接收
	//    下次接收完成后，进行记录处理报文，并且向后查找是否存在第二个数据包
	// 4. 向后未找到第二个或第三个数据包的视为冗余数据，进行丢弃。


	buffer_type buf(bytes_transferred);													///拷贝出本次接收到的缓存
	buf.assign(std::move(m_rbuf.begin()), std::move(m_rbuf.begin() + bytes_transferred));
	m_isFinished = goon_recv(buf);
	flush();
}

void TcpClient::write_handler(const boost::system::error_code& ec)
{
	if (ec)
	{
		(*m_errSignal)(std::string(ec.message()));
		debug_out << std::string(m_sbuf.data()) << '\t' << ec.message() << std::endl;
	}
	std::fill(m_sbuf.begin(), m_sbuf.end(), 0);
}

void TcpClient::flush()
{
	std::fill(m_rbuf.begin(), m_rbuf.end(), 0);
	m_sock->async_read_some(boost::asio::buffer(m_rbuf), boost::bind(&this_type::read_handler, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
}

bool TcpClient::validation(std::string const& strBuf, std::string const& strCode)
{
	std::size_t index = strBuf.find(strCode);
	if (index == std::string::npos)
	{
		//没找到包头视为不正确的数据
		return false;
	}
	auto i = strCode.length();
	std::string pkHead = strBuf.substr(index, strCode.length());
	if(pkHead != strCode)
	{
		//包头错误
		return false;
	}
	return true;
}

bool TcpClient::goon_recv(buffer_type const& buf)
{		
	std::string cvtString;							///数据包的字符串格式

	///已经接收完上一个包，本次包开头是begin
	if (m_isFinished)
	{
		cvtString.assign(buf.begin(), buf.end());
		return parse_pkt(cvtString, buf);
	}
	///没有接收完上一个包，本次包开头是上一次接收结尾
	else
	{
		m_finishedbuf.insert(m_finishedbuf.end(),buf.begin(),buf.end());
		cvtString.assign(m_finishedbuf.begin(), m_finishedbuf.end());		
		//当剩余长度不够读取一个头和一个int32_t整形时候直接返回false,因为int32_t带有整个数据包大小，锁定了报文的位置，读取错误的位置将会引发错误
		//读取到int32_t的位置上确保可以完整读取到整个报文的大小，否则进行继续接收。
		return m_finishedbuf.size() < s_head.size() + sizeof(int32_t) ? m_isFinished = false: parse_pkt(cvtString, m_finishedbuf);
	}
	return true;
}

bool TcpClient::parse_pkt(std::string &cvtString, buffer_type const &buf)
{
	int32_t nsize = 0;
	msg_type msg;
	buffer_type_const_it begin = buf.cbegin();
	buffer_type_const_it end = buf.cend();

	if (!validation(cvtString, s_head))
	{
		///验证包头失败
		giveup();
		return false;
	}
	memcpy_s(&nsize, sizeof(int32_t), buf.data() + s_head.length(), sizeof(int32_t));
	if (nsize <= 0)
	{
		//验证报文长度失败
		giveup();
		return false;
	}
	int32_t remsize = buf.size() - s_head.size() - sizeof(int32_t) - nsize - s_end.size();
	///没有足够的剩余长度
	if (remsize >= 0)
	{
		begin = buf.begin() + s_head.length() + sizeof(int32_t);				//取得报文最开始位置，非缓存最开始位置
		end = buf.begin() + s_head.length() + sizeof(int32_t) + nsize;			//取得报文最终位置，不是缓存最终位置
		cvtString.assign(end, end + s_end.length());
		if (!validation(cvtString, s_end))
		{
			//验证包尾
			giveup();
			return false;
		}
		msg.assign(begin, end);
		msg.push_back(0);
		pushMsg(msg);

		///查看是否有黏包
		if (remsize > 0)
		{
			buffer_type tempbuf(remsize);
			tempbuf.assign(buf.begin() + s_head.size() + sizeof(int32_t) + nsize + s_end.size(), buf.end());
			m_isFinished = true;
			return goon_recv(tempbuf);
		}
		giveup();
	}
	else
	{
		m_isFinished = false;
		m_finishedbuf.insert(m_finishedbuf.end(), begin, end);
		return false;
	}
	return true;
}

void TcpClient::giveup()
{
	m_isFinished = true;
	m_finishedbuf.clear();
}
