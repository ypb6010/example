/******************************************************************************
*过滤器（分发、封包）
********************************************************************************/
#pragma once
#define GOOGLE_RUNTIME_LITE 1

class NetGoogleFilter
{
public:
	NetGoogleFilter();
	~NetGoogleFilter();

	//通过包的序列化字符串得到包主体 发给协议分发机制去处理
	//static bool Get_MSG_BODY_WithPresonSerializeString(Recv_struct SerializeString);

	//通过主题生成一个序列化字符串 添加到发送列表
	//static bool Creater__MSG_PERSON__With__MSG_BODY_( int Socket, ::google::protobuf::Message* bodyMessage);

	

#if GOOGLE_RUNTIME_LITE
	static ::google::protobuf::Message* CreateMessage(int ID);
#else
	static ::google::protobuf::Message* CreateMessage(const std::string& typeName);
#endif
	
	static unsigned long long Adler32(unsigned char* buf, int len);

};
