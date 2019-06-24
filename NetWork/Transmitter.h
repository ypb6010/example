#pragma once
#include "NetWork.h"
#include "EventListener.h"



template<typename T>class IMsgCall;
class ITcpCall;
class NetMessageQueue;
namespace google {
	namespace protobuf {
		class Message;
	};
};
typedef message::HeadClient	 client_msg_head;
typedef message::HeadServer  server_msg_head;
typedef message::PNPCMessage msg_data_t;

/**
 * 类名称：Transmitter
 * 类简介：网络信号发射器包含了网络消息队列接口
 * 包含了tcp网络服务的接口，对网络中的消息进行解析到消息处理器中
 * 具体的操作由消息处理器来完成，不需要本类执行
 * 其中网络服务和解析网络数据包是两个单独的线程，默认创建成功后开启
 * 如需要停止调用close(),重新开始则调用start()函数
 * 消息分类：
 * 服务器====》消息处理器 回调函数存放在回调集合中的视图
 * 消息采用生产消费模式，生产者：TCP网络服务；消费者：消息处理器
 */
class Transmitter : public NetWork
{
	typedef Transmitter														this_type;
	typedef boost::scoped_thread<>											thread_type;
	typedef boost::shared_ptr<thread_type>									thread_ptr;
public:
	//************************************
	// 函数：   Transmitter
	// 全称：  	Transmitter::Transmitter
	// 说明：	构造函数构造一个发射部件对象
	// ****		网络事件==》事件处理器
	// ****		事件处理器==》服务端处理
	// 权限：   public 
	// 返回值：  
	// 限定词： 
	// 参数： 	ITcpCall * pTcp					解释：tcp网络的处理器的接口，默认nullptr创建接口对象
	//************************************
	Transmitter(tcp_ptr pTcp = 0);


	~Transmitter();
	virtual void registerNetError(net_err_slot_t fun) override;

	virtual void registerConnected(net_conn_slot_t fun) override;

	virtual void start(std::string addr, uint16_t port) override;

	virtual void stop() override;
	
	virtual void launchMsg(client_header_t const& hd, std::string const& bodySerializeStr) override;

	virtual void addCbSrvToClient(int nCommand, net_cb_t fn) override;
protected:
	//*********************************************************
	// 函数：   run
	// 全称：  	Transmitter::run
	// 说明：	网络服务启动代码，调用start时候run 自动运行单独线程
	// 权限：   protected 
	// 返回值： void
	// 限定词：
	//*********************************************************
	void run();

	//*********************************************************
	// 函数：   pushMsg
	// 全称：  	Transmitter::pushMsg
	// 说明：	网络中接收到的消息（生产消费中的生产者）由异步信号调用
	// ******	通过解封装后，得到报文类型，和报文体。通过报文类型去查找
	// ******	commandID，如果有注册此ID的解析报文体的函数，并进行回调。
	// 权限：   protected 
	// 返回值： void
	// 限定词：
	// 参数： 	msg_type const & strMsg				解释：完整数据包
	//*********************************************************
	void pushMsg(msg_type const& msg);

	inline void flush(int& nCommand, msg_data_t* const& person, server_msg_head* const& header);

	inline bool checkError(int64_t	const& checksum, std::tuple<char const*&&, std::size_t&&>&& data, int32_t const& stateCode);
private:
	bool				m_isStopDispath;
	thread_ptr			m_pTcpThread;		///网络服务线程
	cb_map_type			m_callbackMap;		///视图的回调函数集合
	tcp_ptr				m_pClientSock;		///网络服务的接口
	net_err_signal_ptr	m_errPtr;			///网络出错观察者
	connect_signal_ptr  m_connSignal;		///网络连接成功观察者
};
