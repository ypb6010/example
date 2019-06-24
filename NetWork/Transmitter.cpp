#include "stable.h"
#include "Transmitter.h"
#include "TcpClient.h"
#include "IMsgCall.h"
#include "NetGoogleFilter.h"



Transmitter::Transmitter(tcp_ptr pTcp)
	: m_pClientSock(pTcp)
	, m_pTcpThread(nullptr)
	, m_isStopDispath(false)
{
	//绑定给TCP网络端向消息队列生产消息接口，参数为NetWork的成员函数指针
	//绑定解析完成完整的protobuf数据包的信号，得到了新数据便会产生此信号

	net_err_slot_t fun = [this](std::string const& strErr)->void
	{
		if (m_errPtr)
			(*m_errPtr)(strErr);
	};
	net_conn_slot_t conn_slot = [this](std::string const& strMsg)->void
	{
		if (m_connSignal)
			(*m_connSignal)(strMsg);
	};

	if (m_pClientSock)
	{
		debug_out << "网络服务正在运行，正在终止当前连接" << std::endl;
		stop();
	}
	m_isStopDispath = false;
	m_pClientSock = boost::make_shared<TcpClient>();
	m_pClientSock->registerErrorCallBack(boost::bind(fun, _1));
	m_pClientSock->registerConnected(boost::bind(conn_slot, _1));
	m_pClientSock->attch(boost::bind(&this_type::pushMsg, this, _1));
}


Transmitter::~Transmitter()
{
	if (m_pClientSock)
	{
		m_pClientSock->close();
	}
	if (m_pTcpThread && m_pTcpThread->joinable())
	{
		m_pTcpThread->join();
	}
	m_isStopDispath = true;
}

void Transmitter::registerNetError(net_err_slot_t fun)
{
	if(!m_errPtr)
		m_errPtr = boost::make_shared<net_err_signal_t>();
	m_errPtr->connect(fun);
}

void Transmitter::registerConnected(net_conn_slot_t fun)
{
	if (!m_connSignal)
	{
		m_connSignal = boost::make_shared<net_conn_signal_t>();
	}
	m_connSignal->connect(fun);
}

void Transmitter::start(std::string addr, uint16_t port)
{
	if (!m_pClientSock)
	{
		m_pClientSock = boost::make_shared<TcpClient>();
	}
	if (m_pClientSock->isRun())
	{
		m_pClientSock->close();
		if (m_pTcpThread && m_pTcpThread->joinable())
		{
			m_pTcpThread->join();
			m_pTcpThread.reset();
		}
	}
	m_pClientSock->connectToHost(addr, port);
	m_pTcpThread = boost::make_shared<thread_type>(boost::bind(&this_type::run, this));
}

void Transmitter::stop()
{
	m_pClientSock->close();

	if (m_pTcpThread && m_pTcpThread->joinable())
	{
		m_pTcpThread->join();
	}
	if (m_pTcpThread && m_pTcpThread.unique())
	{
		m_pClientSock.reset();	//释放网络线程资源
	}	
}

void Transmitter::launchMsg(client_header_t const& hd, std::string const& bodySerializeStr)
{
	if (!m_pClientSock || !m_pClientSock->isRun())
	{
		debug_out << "网络服务没有开启，不能发送" << std::endl;
		debug_out << BOOST_CURRENT_FUNCTION << std::endl;
		return;
	}	
	
	auto&&[nCommand, access_token, datetime] = hd;
	boost::shared_ptr<client_msg_head> head(client_msg_head::default_instance().New());
	head->set_commandid(nCommand);
	head->set_checksum(NetWork::adler32(bodySerializeStr.data(), bodySerializeStr.size()));
	head->set_access_token(access_token);
	head->set_datetime(datetime);
	std::string headSerializeStr = head->SerializeAsString();

	boost::shared_ptr<msg_data_t> person(msg_data_t::default_instance().New());
	person->set_msghead(headSerializeStr);
	person->set_msgbody(bodySerializeStr);

	std::string personSerializeStr = person->SerializeAsString();
	m_pClientSock->sendMsg(personSerializeStr);
}

void Transmitter::addCbSrvToClient(int nCommand, net_cb_t fn)
{
	auto it = m_callbackMap.find(nCommand);
	if (it != m_callbackMap.end())
	{
		debug_out << BOOST_CURRENT_FUNCTION << std::endl;
		debug_out << "对象已经存在，重复添加" << std::endl;
		return;
	}
	m_callbackMap.insert(std::make_pair(nCommand, fn));
}

void Transmitter::pushMsg(msg_type const& msg)
{
	int64_t			checksum = 0;
	boost::shared_ptr<msg_data_t> person(msg_data_t::default_instance().New());					///具体消息体
	boost::shared_ptr<server_msg_head> header(server_msg_head::default_instance().New());		///消息头	
	person->ParseFromArray(msg.data(), msg.size());
	std::string strHead = person->msghead();
	std::string strBody = person->msgbody();
	header->ParseFromString(strHead);
	server_header_t&& head = std::make_tuple(std::move(header->commandid()), std::move(header->code()), std::move(header->msg()), std::move(header->datetime()));
	checksum = header->checksum();				///校验字

	if (!checkError(checksum, std::make_tuple(strBody.data(), strBody.size()), std::get<1>(head)))
	{
		debug_out << "出现错误数据包，待处理" << std::endl;
		debug_out << "checksum	=  " << checksum << std::endl;
		debug_out << "code		= " << std::get<1>(head) << std::endl;
		debug_out << "msg		= " << boost::locale::conv::from_utf<char>(std::get<2>(head),"GBK") << std::endl;
		debug_out << "datetime  = " << std::get<3>(head) << std::endl;
	}

	auto it = m_callbackMap.find(std::get<0>(head));
	if (it != m_callbackMap.end())
	{
		//调用回调函数
		boost::bind(it->second, _1, _2)(boost::cref(strBody), std::make_tuple(std::get<1>(head), std::get<2>(head), std::get<3>(head)));
	}
	else
	{
		debug_out << "没有找到对应的解析报文函数:" << std::get<0>(head) << std::endl;
		debug_out << BOOST_CURRENT_FUNCTION << std::endl;
	}
	flush(std::get<0>(head), person.get(), header.get());
}


void Transmitter::flush(int& nCommand, msg_data_t* const& person, server_msg_head* const& header)
{
	nCommand = -1;
	person->Clear();
	header->Clear();
}

bool Transmitter::checkError(int64_t const& checksum, std::tuple<char const*&&, std::size_t&&>&& data, int32_t const& stateCode)
{
	if (stateCode > 1000 && stateCode < 5000)
	{
		return false;
	}
	else if (stateCode > 5000)
	{
		return false;
	}
	return stateCode == 0 && checksum == NetWork::adler32(std::get<0>(data), std::get<1>(data));
}

void Transmitter::run()
{
	m_pClientSock->run();
}
