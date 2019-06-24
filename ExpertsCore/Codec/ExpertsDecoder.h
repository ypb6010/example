#pragma once


class ExpertsDecoder : public DecoderBase
{
public:
	ExpertsDecoder();
	virtual ~ExpertsDecoder();
	//医生基本信息
	event_handler decode_doctor_info(std::string const& strBody);
	//状态列表信息
	event_handler decode_list_push(std::string const& strBody);
	//开始门诊回执信息
	event_handler decode_begin(std::string const& strBody);
	//叫号响应信息
	event_handler decode_call_next_result(std::string const& strBody);
	//助诊响应叫号请求结果
	event_handler decode_call_result(std::string const& strBody);
	//专家暂停后的响应
	event_handler decode_pause(std::string const& strBody);
	//专家房间下发
	event_handler decode_room_id_push(std::string const& strBody);
	//专家过号确认响应
	event_handler decode_sure_pass(std::string const& strBody);
	//专家完成响应
	event_handler decode_stop(std::string const& strBody);
	//专家离开响应
	event_handler decode_leave(std::string const& strBody);
	//专家离开后恢复响应
	event_handler decode_leave_recover(std::string const& strBody);
	//专家结束门诊后的响应
	event_handler decode_complete(std::string const& strBody);
	//专家病史后响应
	event_handler decode_history(std::string const& strBody);
	//专家添加病史后响应
	event_handler decode_add_history(std::string const& strBody);

};

