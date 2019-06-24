#pragma once
#include "core_global.h"

typedef std::tuple<int32_t, std::string, std::string>				client_header_t;
// 解析完后的服务端包头：1.状态码，2.错误信息，3.发包时间
typedef client_header_t												msg_header_t;
typedef std::tuple<client_header_t, std::string>					request_t;
typedef std::string													msg_handler;

class CORE_EXPORT EncoderBase
{
protected:

public:
	EncoderBase() = default;
	virtual ~EncoderBase() = default;
	msg_handler encode_userLogin(std::string const& s);

	msg_handler encode_none(std::string const& s);

	msg_handler encode_userbase(std::string const& s);

	msg_handler last_msg(std::string const& str) const;

	client_header_t last_header(std::string const& str) const;

	request_t last_reques(std::string const& str ) const;
protected:
	request_t m_last;
};