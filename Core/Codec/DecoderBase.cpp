#include "stable.h"
#include "DecoderBase.h"
#include "Core.h"

///0处理消息，出现错误
event_handler DecoderBase::decode_heatbeat(std::string const& strBody)
{
	if (strBody.empty())
	{
		return event_handler();
	}
	//一下都为测试代码
	UserLoginResponse respon;
	boost::shared_ptr<message::UserLoginResponse> req(message::UserLoginResponse::default_instance().New());
	req->ParseFromString(strBody);
	respon.server_address = Core::gbk_from_utf8(req->server_address());
	respon.server_uuid = Core::gbk_from_utf8(req->server_uuid());
	respon.server_port = Core::gbk_from_utf8(req->server_port());
	respon.access_token = Core::gbk_from_utf8(req->access_token());
	event_handler const&& strLocalser = Core::pack_binary(respon);
	return strLocalser;
}

event_handler DecoderBase::decode_version(std::string const& strBody)
{
	VersionResponse respon;	
	boost::shared_ptr<message::VersionResponse> req(message::VersionResponse::default_instance().New());
	req->ParseFromString(strBody);
	auto&& l = req->version_list();
	for (auto&& v : l)
	{
		VersionList		vList;
		vList.version_uuid = Core::gbk_from_utf8(v.version_uuid());
		vList.version_description = Core::gbk_from_utf8(v.version_description());
		vList.version_value = Core::gbk_from_utf8(v.version_value());
		vList.url = Core::gbk_from_utf8(v.url());
		respon.version_list.push_back(vList);
	}
	event_handler const&& strLocalser = Core::pack_binary(respon);
	return strLocalser;
}

event_handler DecoderBase::decode_login(std::string const& strBody)
{
	UserLoginResponse respon;
	boost::shared_ptr<message::UserLoginResponse> req(message::UserLoginResponse::default_instance().New());
	req->ParseFromString(strBody);
	respon.server_address = Core::gbk_from_utf8(req->server_address());
	respon.server_uuid = Core::gbk_from_utf8(req->server_uuid());
	respon.server_port = Core::gbk_from_utf8(req->server_port());
	respon.access_token = Core::gbk_from_utf8(req->access_token());
	event_handler const&& strLocalser = Core::pack_binary(respon);
	return strLocalser;
}

event_handler DecoderBase::decode_heartbeat(std::string const& strBody)
{
	return event_handler();
}

event_handler DecoderBase::last_handler(std::string const& strMsg) const
{
	if (strMsg == "error_lose")
		return m_last;
	return event_handler();
}
