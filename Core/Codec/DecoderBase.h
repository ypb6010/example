#pragma once
#include "core_global.h"

// 客户端发出包 1.nCommand	2.登录凭证	3.datatime
typedef std::tuple<int32_t, std::string, std::string>				client_header_t;
// 解析完后的服务端包头：1.状态码，2.错误信息，3.发包时间
typedef client_header_t												msg_header_t;


/**
 * 类名称：	DecoderBase
 * 类简介：	本类主要是解析网络中的protobuf序列化后的字符串
 * ******	解析后转换为本地序列化的字符串格式，以event_handler
 * ******	形式进行存储，最后放入消息队列
 */
class CORE_EXPORT DecoderBase
{
protected:
	typedef std::string													event_handler;	///本地序列化的字符串
public:
	DecoderBase() = default;
	virtual ~DecoderBase() = default;

	event_handler decode_heatbeat(std::string const& strBody);

	event_handler decode_version(std::string const& strBody);

	event_handler decode_login(std::string const& strBody);

	event_handler decode_heartbeat(std::string const& strBody);

	event_handler last_handler(std::string const& strMsg) const;
protected:
	event_handler m_last;
};