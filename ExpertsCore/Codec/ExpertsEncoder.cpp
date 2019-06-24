#include "stable.h"
#include "ExpertsEncoder.h"


ExpertsEncoder::ExpertsEncoder()
{
}


ExpertsEncoder::~ExpertsEncoder()
{
}

msg_handler ExpertsEncoder::encode_start_service(std::string const& strMsg)
{
	DoctorBeginRequest const&& request = Core::unpack_binary<DoctorBeginRequest>(strMsg);
	boost::shared_ptr<message::DoctorBeginRequest> packreq(message::DoctorBeginRequest::default_instance().New());
	packreq->set_begin_type(Core::gbk_to_utf8(request.begin_type));
	packreq->set_doctor_id(Core::gbk_to_utf8(request.doctor_id));
	std::string strBody;
	packreq->SerializeToString(&strBody);
	return strBody;
}

msg_handler ExpertsEncoder::encode_call_next(std::string const& strMsg)
{
	DioctorCallRequest const&& request = Core::unpack_binary<DioctorCallRequest>(strMsg);
	boost::shared_ptr<message::DioctorCallRequest> packreq(message::DioctorCallRequest::default_instance().New());
	packreq->set_doctor_id(Core::gbk_to_utf8(request.doctor_id));
	std::string strBody;
	packreq->SerializeToString(&strBody);
	return strBody;
}

msg_handler ExpertsEncoder::encode_heartbeat(std::string const& s)
{
	return s;
}

msg_handler ExpertsEncoder::encode_pause(std::string const& strMsg)
{
	DoctorPauseRequest const&& request = Core::unpack_binary<DoctorPauseRequest>(strMsg);
	boost::shared_ptr<message::DoctorPauseRequest> packreq(message::DoctorPauseRequest::default_instance().New());
	packreq->set_doctor_id(Core::gbk_to_utf8(request.doctor_id));
	packreq->set_register_id(Core::gbk_to_utf8(request.register_id));
	packreq->set_diagnosis_id(Core::gbk_to_utf8(request.diagnosis_id));
	packreq->set_patient_id(Core::gbk_to_utf8(request.patient_id));
	std::string strBody;
	packreq->SerializeToString(&strBody);
	return strBody;
}

msg_handler ExpertsEncoder::encode_sure_pass(std::string const& strMsg)
{
	DoctorSurePassRequest const&& request = Core::unpack_binary<DoctorSurePassRequest>(strMsg);
	boost::shared_ptr<message::DoctorSurePassRequest> packreq(message::DoctorSurePassRequest::default_instance().New());
	packreq->set_doctor_id(request.doctor_id);
	packreq->set_register_id(request.register_id);
	packreq->set_wait_time(request.wait_time);
	std::string strBody;
	packreq->SerializePartialToString(&strBody);
	return strBody;
}

msg_handler ExpertsEncoder::encode_stop(std::string const& strMsg)
{
	DoctorStopRequest  const&& request = Core::unpack_binary<DoctorStopRequest>(strMsg);
	boost::shared_ptr<message::DoctorStopRequest> packreq(message::DoctorStopRequest::default_instance().New());
	packreq->set_doctor_id(Core::gbk_to_utf8(request.doctor_id));
	packreq->set_register_id(Core::gbk_to_utf8(request.register_id));
	packreq->set_patient_id(Core::gbk_to_utf8(request.patient_id));
	packreq->set_diagnosis_id(Core::gbk_to_utf8(request.diagnosis_id));
	packreq->set_datetime(Core::gbk_to_utf8(request.datetime));
	packreq->set_treat_main(Core::gbk_to_utf8(request.treat_main));
	packreq->set_treat_propose(Core::gbk_to_utf8(request.treat_propose));
	packreq->set_deal_propose(Core::gbk_to_utf8(request.deal_propose));
	packreq->set_prescript_propose(Core::gbk_to_utf8(request.prescript_propose));
	std::string strBody;
	packreq->SerializeToString(&strBody);
	return strBody;
}

msg_handler ExpertsEncoder::encode_leave(std::string const& strMsg)
{
	DoctorLeaveRequest const&& request = Core::unpack_binary<DoctorLeaveRequest>(strMsg);
	boost::shared_ptr<message::DoctorLeaveRequest> packreq(message::DoctorLeaveRequest::default_instance().New());
	packreq->set_doctor_id(request.doctor_id);
	std::string strBody;
	packreq->SerializeToString(&strBody);
	return strBody;
}

msg_handler ExpertsEncoder::encode_leave_recover(std::string const& strMsg)
{
	DoctorLeaveRecoverRequest const&& request = Core::unpack_binary<DoctorLeaveRecoverRequest>(strMsg);
	boost::shared_ptr<message::DoctorLeaveRecoverRequest> packreq(message::DoctorLeaveRecoverRequest::default_instance().New());
	packreq->set_doctor_id(request.doctor_id);
	std::string strBody;
	packreq->SerializeToString(&strBody);
	return strBody;
}

msg_handler ExpertsEncoder::encode_complete(std::string const& strMsg)
{
	DoctorCompleteRequest const&& request = Core::unpack_binary<DoctorCompleteRequest>(strMsg);
	boost::shared_ptr<message::DoctorCompleteRequest> packreq(message::DoctorCompleteRequest::default_instance().New());
	packreq->set_datetime(Core::gbk_to_utf8(request.datetime));
	packreq->set_doctor_id(Core::gbk_to_utf8(request.doctor_id));
	std::string strBody;
	packreq->SerializeToString(&strBody);
	return strBody;
}

msg_handler ExpertsEncoder::encode_history(std::string const& strMsg)
{
	IllHistoryRequest const&& request = Core::unpack_binary<IllHistoryRequest>(strMsg);
	boost::shared_ptr<message::IllHistoryRequest> packreq(message::IllHistoryRequest::default_instance().New());
	packreq->set_patient_id(Core::gbk_to_utf8(request.patient_id));
	std::string strBody;
	packreq->SerializeToString(&strBody);
	return strBody;
}

msg_handler ExpertsEncoder::encode_add_history(std::string const& strMsg)
{
	IllHistoryAddRequest const&& request = Core::unpack_binary<IllHistoryAddRequest>(strMsg);
	boost::shared_ptr<message::IllHistoryAddRequest> packreq(message::IllHistoryAddRequest::default_instance().New());
	packreq->set_patient_id(Core::gbk_to_utf8(request.patient_id));
	packreq->set_doctor_id(Core::gbk_to_utf8(request.doctor_id));
	packreq->set_content(Core::gbk_to_utf8(request.content));
	packreq->set_ill_type(request.ill_type);
	std::string strBody;
	packreq->SerializeToString(&strBody);
	return strBody;
}

