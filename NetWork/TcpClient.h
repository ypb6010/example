#pragma once

#include "ITcpCall.h"

/**
 * 类名称：TcpClient
 * 类简介：本类主要实现网络的接口，使用的是boost中的tcp
 * 如果使用其他方式实现网络服务，那么重新继承ITcpCall进行实现即可
 */
class TcpClient : public ITcpCall
{
	typedef TcpClient										this_type;
	typedef boost::asio::ip::tcp::endpoint					endpoint_type;
	typedef boost::asio::ip::address						address_type;
	typedef boost::asio::ip::tcp::socket					socket_type;
	typedef boost::shared_ptr<socket_type>					sock_ptr;
	typedef boost::asio::io_service							io_type;
	typedef std::vector<char>								buffer_type;
	typedef buffer_type::iterator							buffer_type_it;
	typedef buffer_type::const_iterator						buffer_type_const_it;
public:
	TcpClient();
	~TcpClient();
	virtual void run() override;
	virtual void close() override;
	virtual void sendMsg(std::string const& strMsg) override;
	virtual bool isRun() const override;

	//*********************************************************
	// 函数：   attch
	// 全称：  	TcpClient::attch
	// 说明：	连接的这个函数指针，等解包消息发生后，回调这个函数指针
	// 权限：   virtual public 
	// 返回值： void
	// 限定词：
	// 参数： 	msg_function				解释：函数指针
	//*********************************************************
	virtual void attch(msg_slot_t) override;

	virtual void registerErrorCallBack(net_err_slot_t fun) override;

	virtual void registerConnected(net_conn_slot_t fun) override;

	virtual void connectToHost(std::string const& host, uint16_t port) override;

protected:
	//*********************************************************
	// 函数：   pushMsg
	// 全称：  	TcpClient::pushMsg
	// 说明：	发送解包完成的信号
	// 权限：   virtual protected 
	// 返回值： void
	// 限定词：
	// 参数： 	msg_type const & strMsg		解释：消息完整包
	//*********************************************************
	virtual void pushMsg(msg_type const& strMsg) override;

protected:	
	//*********************************************************
	// 函数：   start
	// 全称：  	TcpClient::start
	// 说明：	开启网络连接
	// 权限：   protected 
	// 返回值： void
	// 限定词：
	//*********************************************************
	void start();

	//*********************************************************
	// 函数：   conn_handler
	// 全称：  	TcpClient::conn_handler
	// 说明：	连接完成，ec为错误值
	// 权限：   protected 
	// 返回值： void
	// 限定词：
	// 参数： 	const boost::system::error_code & ec 解释：有值为出错
	//*********************************************************
	void conn_handler(const boost::system::error_code& ec);

	//*********************************************************
	// 函数：   read_handler
	// 全称：  	TcpClient::read_handler
	// 说明：	读取一次消息出错
	// 权限：   protected 
	// 返回值： void
	// 限定词：
	// 参数： 	const boost::system::error_code & ec		解释：有值为出错
	// 参数： 	std::size_t bytes_transferred				解释：读取到的字节数
	//*********************************************************
	void read_handler(const boost::system::error_code& ec, std::size_t bytes_transferred);

	//*********************************************************
	// 函数：   write_handler
	// 全称：  	TcpClient::write_handler
	// 说明：	发送完成后的处理函数
	// 权限：   protected 
	// 返回值： void
	// 限定词：
	// 参数： 	const boost::system::error_code & ec		解释：有值出错
	//*********************************************************
	void write_handler(const boost::system::error_code& ec);

	//*********************************************************
	// 函数：   flush
	// 全称：  	TcpClient::flush
	// 说明：	清空接收缓存，并等待下一次接收
	// 权限：   protected 
	// 返回值： void
	// 限定词：
	//*********************************************************
	void flush();
private:
	//*********************************************************
	// 函数：   validation
	// 全称：  	TcpClient::validation
	// 说明：	数据包验证器，验证帧头帧尾是否通过
	// 权限：   private 
	// 返回值： bool									验证通过返回true，否则false
	// 限定词：
	// 参数： 	std::string const & strBuf				解释：要验证的缓冲区	
	// 参数： 	std::string const & strCode				解释：验证的字符串
	//*********************************************************
	inline bool validation(std::string const& strBuf, std::string const& strCode);

	//*********************************************************
	// 函数：   goon_recv
	// 全称：  	TcpClient::goon_recv
	// 说明：	进入到接收数据包状态，查看数据包的完整，此函数会调用parse_pkt
	// *****	区分在上一次包是否已经接收完成，本次是续接上次包还是本次收完整包策略
	// 权限：   private 
	// 返回值： bool								不完整的数据包返回false,下次继续接收
	// 限定词：
	// 参数： 	buffer_type const & buf				解释：本次到来的数据包缓冲区
	//*********************************************************
	bool goon_recv(buffer_type const& buf);

	//*********************************************************
	// 函数：   parse_pkt
	// 全称：  	TcpClient::parse_pkt
	// 说明：	解析数据包，解释失败返回false,假如解析到一半，缓冲区没有多余数据了，
	// *****	会将本次的数据进行保存，等待续接。如果出现黏包，会处理了本次完整包后
	// *****	继续调用goon_recv进行接黏住的包，在进行解析，如果有验证失败，弃包视为已经接收完成状态。
	// 权限：   private 
	// 返回值： bool
	// 限定词：
	// 参数： 	std::string & cvtString				解释：缓冲区的字符串格式，便于查找
	// 参数： 	buffer_type const & buf				解释：缓冲区
	//*********************************************************
	bool parse_pkt(std::string const& cvtString, buffer_type const &buf);

	//*********************************************************
	// 函数：   giveup
	// 全称：  	TcpClient::giveup
	// 说明：	对包进行丢弃，针对上次接收没收完的，或者黏包中，解析失败的
	// 权限：   private 
	// 返回值： void
	// 限定词：
	//*********************************************************
	inline void giveup();

	void set_error(std::string const& mes);
private:
	static std::string const s_head;
	static std::string const s_end;
	bool									m_isFinished;			///是否为断点续传状态，false等待下次接收，true没有断点续传，接收新的包
	buffer_type								m_finishedbuf;			///处理未接收完的缓冲区

	io_type									m_io;					///io_service对象
	buffer_type								m_rbuf;					///接收缓冲区
	buffer_type								m_sbuf;					///发送缓冲区，由于异步发送，局部变量会报nullptr
	endpoint_type							m_ep;					///TCP端点
	sock_ptr								m_sock;					///网络连接
	msg_signal_ptr							m_unpack;				///解封装完成信号
	net_err_signal_ptr						m_err;					///连接中错误的信号
	connect_signal_ptr						m_conn;					///连接成功信号
};
