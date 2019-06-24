#include "stable.h"
#include "AssistManager.h"
#include "Codec/AssistDecoder.h"
#include "DataManager.h"


AssistManager::AssistManager()
	:  m_decoder(boost::make_shared<decode_ptr::element_type>())
{
	EventWarp::registerFactory(0, boost::bind(&EventManger::eventMangerFactory));
}


AssistManager::~AssistManager()
{
}


 
void AssistManager::initOthers()
{
	if (!m_decoder)
	{
		m_decoder = boost::make_shared<decode_ptr::element_type>();
	}
	if (!m_dataptr)
	{
		m_dataptr = boost::make_shared<data_ptr::element_type>();
	}
	REG_AREA_EVENT(message::AC_COMMAND_DIAGNOSIS_BASE_RESPONSE);						//基本信息事件
	REG_AREA_EVENT(message::AC_COMMAND_DIAGNOSIS_BEGIN_RESPONSE);						//开始门诊事件
	REG_AREA_EVENT(message::AC_COMMAND_DIAGNOSIS_LIST_PUSH);							//状态消息队列事件
	REG_AREA_EVENT(message::AC_COMMAND_DIAGNOSIS_ACCEPT_CALL_PUSH);						//专家叫号事件
	REG_AREA_EVENT(message::AC_COMMAND_DIAGNOSIS_HEARTBEAT_RESPONSE);					//服务端心跳
	REG_AREA_EVENT(message::AC_COMMAND_DIAGNOSIS_RESPONSE_CALL_RESPONSE);				//助诊回复专家叫号响应
	REG_AREA_EVENT(message::AC_COMMAND_DOCTOR_SURE_PASS_PUSH);							//助诊回复专家暂停响应
	REG_AREA_EVENT(message::AC_COMMAND_DIAGNOSIS_PAUSE_PUSH);							//助诊暂停下发
	REG_AREA_EVENT(message::AC_COMMAND_DIAGNOSIS_LEAVE_RESPONSE);						//助诊离开
	REG_AREA_EVENT(message::AC_COMMAND_DIAGNOSIS_LEAVE_RECOVER_RESPONSE);				//助诊离开恢复
	REG_AREA_EVENT(message::AC_COMMAND_DIAGNOSIS_SPARE_RESPONSE);						//助诊备注响应
	REG_AREA_EVENT(message::AC_COMMAND_DIAGNOSIS_COMPLETE_PUSH);						//专家完成响应的下发
	REG_AREA_EVENT(message::AC_COMMAND_DOCTOR_COMPLETE_RESPONSE);						//专家结束门诊
	REG_AREA_EVENT(message::AC_COMMAND_DIAGNOSIS_HISTORY_RESPONSE);						//助诊请求病史回应

	REG_DEC(message::AC_COMMAND_DIAGNOSIS_BEGIN_RESPONSE, decode_diagnosis);			//开始门诊回执
	REG_DEC(message::AC_COMMAND_DIAGNOSIS_BASE_RESPONSE, decode_diagnosis_info);		//基本信息回执
	REG_DEC(message::AC_COMMAND_DIAGNOSIS_LIST_PUSH, decode_diagnosis_list);			//状态消息队列回执
	REG_DEC(message::AC_COMMAND_DIAGNOSIS_ACCEPT_CALL_PUSH, decode_next);				//专家叫号回执
	REG_DEC(message::AC_COMMAND_DIAGNOSIS_HEARTBEAT_RESPONSE, decode_heartbeat);		//专家叫号回执
	REG_DEC(message::AC_COMMAND_DIAGNOSIS_RESPONSE_CALL_RESPONSE, decode_response_call);//助诊回应专家叫号后响应
	REG_DEC(message::AC_COMMAND_DOCTOR_SURE_PASS_PUSH, decode_sure_pass_push);			//助诊回应专家暂停
	REG_DEC(message::AC_COMMAND_DIAGNOSIS_PAUSE_PUSH, decode_pause_push);				//助诊的暂停下发
	REG_DEC(message::AC_COMMAND_DIAGNOSIS_LEAVE_RESPONSE, decode_leave);				//助诊的离开响应
	REG_DEC(message::AC_COMMAND_DIAGNOSIS_LEAVE_RECOVER_RESPONSE, decode_leave_recover);//助诊的离开恢复响应
	REG_DEC(message::AC_COMMAND_DIAGNOSIS_COMPLETE_PUSH, decode_complte_push);			//专家完成结果下发
	REG_DEC(message::AC_COMMAND_DIAGNOSIS_SPARE_RESPONSE, decode_spare);				//助诊备注上传结果
	REG_DEC(message::AC_COMMAND_DOCTOR_COMPLETE_RESPONSE, decode_doctro_complete);		//助诊结束门诊
	REG_DEC(message::AC_COMMAND_DIAGNOSIS_HISTORY_RESPONSE, decode_history);			//助诊请求病史解码
	__super::initOthers();
}

app_ptr AssistManager::creatAppManager()
{
	return boost::make_shared<AssistManager>();
}

data_ptr AssistManager::dataManager() const
{
	return m_dataptr;
}


