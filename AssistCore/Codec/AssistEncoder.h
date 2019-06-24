#pragma once
#include "../Core/Codec/EncoderBase.h"


class AssistEncoder :public EncoderBase
{
public:
	AssistEncoder();
	~AssistEncoder();

	///开始门诊CA_COMMAND_DIAGNOSIS_REQUEST = 3003;
	msg_handler encode_diagnosis(std::string const& s);

	///CA_COMMAND_PASSWORD_MODIFY_REQUEST = 3005;//修改密码请求
	msg_handler encode_password_modify(std::string const& s);

	///CA_COMMAND_AVATAR_MODIFY_REQUEST = 3006;//修改头像请求
	msg_handler encode_avatar_modify(std::string const& s);

	///CA_COMMAND_CALL_RESPONSE_REQUEST = 3007;	//助诊端叫号回复请求
	msg_handler encode_call_response(std::string const& s);

	///CA_COMMAND_DIAGNOSIS_HEARTBEAT_REQUEST=3002	//助诊心跳
	msg_handler encode_heartbeat(std::string const& s);
	
	///助诊端暂停恢复
	msg_handler encode_pause_recover(std::string const& s);

	///助诊过号恢复请求
	msg_handler encode_pass_recover(std::string const& s);

	///助诊离开
	msg_handler encode_leave(std::string const& s);

	///助诊离开继续
	msg_handler encode_leave_recover(std::string const& s);

	///助诊备注
	msg_handler encode_spare(std::string const& s);

	///助诊结束门诊
	msg_handler encode_complete(std::string const& s);

	///助诊请求病史
	msg_handler encode_history(std::string const& s);

};

