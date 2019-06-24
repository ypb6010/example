#include "stable.h"
#include "ExpertsManager.h"
#include "DataManager.h"


ExpertsManager::ExpertsManager()
	:  m_decoder(boost::make_shared<Decoder>())
{
	EventWarp::registerFactory(0, boost::bind(&EventManger::eventMangerFactory));
}


ExpertsManager::~ExpertsManager()
{
}



void ExpertsManager::initOthers()
{
	if (!m_decoder)
	{
		m_decoder = boost::make_shared<Decoder>();
	}
	if (!m_dataptr)
	{
		m_dataptr = boost::make_shared<data_ptr::element_type>();
	}
	//REG_AREA_EVENT(message::AC_COMMAND_DOCTOR_NONE);									//出错信息
	REG_AREA_EVENT(message::AC_COMMAND_DOCTOR_HEARTBEAT_RESPONSE);						//注册心跳响应
	REG_AREA_EVENT(message::AC_COMMAND_DOCTOR_BASE_RESPONSE);							//基本信息事件
	REG_AREA_EVENT(message::AC_COMMAND_DOCTOR_LIST_PUSH);								//注册状态队列信息下发
	REG_AREA_EVENT(message::AC_COMMAND_DOCTOR_BEGIN_RESPONSE);							//医生开始门诊回执
	REG_AREA_EVENT(message::AC_COMMAND_DOCTOR_CALL_RESPONSE);							//专家叫号后响应
	REG_AREA_EVENT(message::AC_COMMAND_DOCTOR_ACCEPT_CALL_RESULT_PUSH);					//专家叫号后助诊响应的回执
	REG_AREA_EVENT(message::AC_COMMAND_DOCTOR_PAUSE_RESPONSE);							//专家暂停后的回执
	REG_AREA_EVENT(message::AC_COMMAND_DOCTOR_ROOM_ID_PUSH);							//专家的视讯房间号
	REG_AREA_EVENT(message::AC_COMMAND_DOCTOR_SURE_PASS_RESPONSE);						//专家过号确认响应
	REG_AREA_EVENT(message::AC_COMMAND_DOCTOR_STOP_RESPONSE);							//专家完成确认响应
	REG_AREA_EVENT(message::AC_COMMAND_DOCTOR_LEAVE_RESPONSE);							//专家离开响应
	REG_AREA_EVENT(message::AC_COMMAND_DOCTOR_LEAVE_RECOVER_RESPONSE);					//专家离开恢复响应
	REG_AREA_EVENT(message::AC_COMMAND_DOCTOR_HISTORY_RESPONSE);						//请求病史响应
	REG_AREA_EVENT(message::AC_COMMAND_DOCTOR_HISTORY_ADD_RESPONSE);					//请求添加病史
	

	//REG_DEC(message::AC_COMMAND_DOCTOR_NONE, decode_heartbeat);						//心跳信息的解码（特殊消息包，直接返回即可）
	REG_DEC(message::AC_COMMAND_DOCTOR_HEARTBEAT_RESPONSE, decode_heartbeat);			//错误信息包和心跳信息暂时视为同一类
	REG_DEC(message::AC_COMMAND_DOCTOR_BASE_RESPONSE, decode_doctor_info);				//给基本信息解码
	REG_DEC(message::AC_COMMAND_DOCTOR_LIST_PUSH, decode_list_push);					//给状态队列解码
	REG_DEC(message::AC_COMMAND_DOCTOR_BEGIN_RESPONSE, decode_begin);					//给回执开始门诊解码
	REG_DEC(message::AC_COMMAND_DOCTOR_CALL_RESPONSE, decode_call_next_result);			//给叫号的回执解码
	REG_DEC(message::AC_COMMAND_DOCTOR_ACCEPT_CALL_RESULT_PUSH, decode_call_result);	//给叫号后助诊回应的回执解码
	REG_DEC(message::AC_COMMAND_DOCTOR_PAUSE_RESPONSE, decode_pause);					//专家暂停后的回执解码
	REG_DEC(message::AC_COMMAND_DOCTOR_ROOM_ID_PUSH, decode_room_id_push);				//给下发的房间消息解码
	REG_DEC(message::AC_COMMAND_DOCTOR_SURE_PASS_RESPONSE, decode_sure_pass);			//给下发的房间消息解码
	REG_DEC(message::AC_COMMAND_DOCTOR_STOP_RESPONSE, decode_stop);						//给专家完成确认消息解码
	REG_DEC(message::AC_COMMAND_DOCTOR_LEAVE_RESPONSE, decode_leave);					//给专家离开消息响应解码
	REG_DEC(message::AC_COMMAND_DOCTOR_LEAVE_RECOVER_RESPONSE, decode_leave_recover);	//给专家离开恢复响应解码
	REG_DEC(message::AC_COMMAND_DOCTOR_COMPLETE_RESPONSE, decode_complete);				//给专家离开恢复响应解码
	REG_DEC(message::AC_COMMAND_DOCTOR_HISTORY_RESPONSE, decode_history);				//给专家请求病史响应解码
	REG_DEC(message::AC_COMMAND_DOCTOR_HISTORY_ADD_RESPONSE, decode_add_history);		//给专家请求添加病史响应解码

	__super::initOthers();
}

app_ptr ExpertsManager::creatAppManager()
{
	return boost::make_shared <this_type> ();
}

data_ptr ExpertsManager::dataManager() const
{
	return m_dataptr;
}


