#pragma once
#include "assistcore_global.h"

class AssistDecoder;
/**
 * 类名称：AssistManager
 * 类简介：本类中进行从消息队列中取出消息来进行解析出二进制来。
 * ******  AssistManager会出现两条线程，第一条：调用AssistManager
 * ******  的线程，就是AssistManager在哪个线程创建，归属的线程，
 * ******  第二条线程：创建出来的派发消息的线程，单独的在子类中进行的绑定
 * ******  异步操作在dispachMsg中进行。AssistManager中应实现网络中的protobuf
 * ******  的各种数据包，在本类中进行解析，等待网络放入消息队列。
 * ******  所有的函数绑定操作应当放入initOthers，因为initOthers会确保
 * ******  所有对象已经创建完成
 */
class ASSISTCORE_EXPORT AssistManager :public AppManager
{
	typedef AssistManager this_type;
public:
	AssistManager();
	virtual ~AssistManager();
	static app_ptr creatAppManager();
public:
	data_ptr dataManager() const;
protected:

	virtual void initOthers() override;

private:	
	decode_ptr	m_decoder;
	data_ptr	m_dataptr;
};

