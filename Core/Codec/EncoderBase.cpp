#include "stable.h"
#include "EncoderBase.h"
#include "Core.h"
#include "Message/AreaBase.pb.h"

msg_handler EncoderBase::encode_userLogin(std::string const& s)
{
	UserLoginRequest const&& req = Core::unpack_binary<UserLoginRequest>(s);
	boost::shared_ptr<message::UserLoginRequest> reques = boost::make_shared<message::UserLoginRequest>();
	reques->set_account(req.accoct);
	reques->set_password(req.passwd);
	reques->set_user_type(req.user_type);
	reques->set_public_key(req.public_key);
	std::string strMsg;
	reques->SerializeToString(&strMsg);
	return strMsg;
}

msg_handler EncoderBase::encode_none(std::string const& s)
{
	s;
	return std::string();
}

msg_handler EncoderBase::encode_userbase(std::string const& s)
{
	UserBaseRequest const&& req = Core::unpack_binary<UserBaseRequest>(s);
	boost::shared_ptr<message::UserBaseRequest> reques = boost::make_shared<message::UserBaseRequest>();
	reques->set_public_key(req.public_key);
	std::string strMsg;
	reques->SerializePartialToString(&strMsg);
	return strMsg;
}

msg_handler EncoderBase::last_msg(std::string const& str) const
{
	if (str == "error_lose")
	{
		return std::get<1>(m_last);
	}
	return std::string();
}

msg_header_t EncoderBase::last_header(std::string const& str) const
{
	return std::get<0>(m_last);
}

request_t EncoderBase::last_reques(std::string const& str) const
{
	return m_last;
}
