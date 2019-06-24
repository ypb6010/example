#include "stable.h"
#include "AssistEncoder.h"


AssistEncoder::AssistEncoder()
{
}


AssistEncoder::~AssistEncoder()
{
}

std::string AssistEncoder::encode_diagnosis(std::string const& s)
{
	DiagnosisBeginRequest const&& request = Core::unpack_binary<DiagnosisBeginRequest>(s);
	boost::shared_ptr<message::DiagnosisBeginRequest> packreq(message::DiagnosisBeginRequest::default_instance().New());
	packreq->set_diagnosis_id(Core::gbk_to_utf8(request.diagnosis_id));
	std::string strMsg;
	packreq->SerializeToString(&strMsg);
	return strMsg;
}

std::string AssistEncoder::encode_password_modify(std::string const & s)
{
	return std::string();
}

std::string AssistEncoder::encode_avatar_modify(std::string const & s)
{
	return std::string();
}

std::string AssistEncoder::encode_call_response(std::string const & s)
{
	DiagnosisResponseCallRequest const&& request = Core::unpack_binary<DiagnosisResponseCallRequest>(s);
	boost::shared_ptr<message::DiagnosisResponseCallRequest> packreq(message::DiagnosisResponseCallRequest::default_instance().New());
	packreq->set_response(Core::gbk_to_utf8(request.response));
	packreq->set_doctor_id(Core::gbk_to_utf8(request.doctor_id));
	packreq->set_register_id(Core::gbk_to_utf8(request.register_id));
	std::string strMsg;
	packreq->SerializeToString(&strMsg);
	return strMsg;
}

msg_handler AssistEncoder::encode_heartbeat(std::string const& s)
{
	return s;
}

msg_handler AssistEncoder::encode_pause_recover(std::string const& s)
{
	DiagnosisPauseRecoverRequest const&& request = Core::unpack_binary <DiagnosisPauseRecoverRequest>(s);
	boost::shared_ptr<message::DiagnosisPauseRecoverRequest> packreq(message::DiagnosisPauseRecoverRequest::default_instance().New());
	packreq->set_diagnosis_id(Core::gbk_to_utf8(request.diagnosis_id));
	packreq->set_register_id(Core::gbk_to_utf8(request.register_id));
	packreq->set_patient_id(Core::gbk_to_utf8(request.patient_id));
	std::string strMsg;
	packreq->SerializeToString(&strMsg);
	return strMsg;
}

msg_handler AssistEncoder::encode_pass_recover(std::string const& s)
{
	DiagnosisPassRecoverRequest const&& request = Core::unpack_binary<DiagnosisPassRecoverRequest>(s);
	boost::shared_ptr<message::DiagnosisPassRecoverRequest> packreq(message::DiagnosisPassRecoverRequest::default_instance().New());
	packreq->set_diagnosis_id(Core::gbk_to_utf8(request.diagnosis_id));
	packreq->set_patient_id(Core::gbk_to_utf8(request.patient_id));
	packreq->set_register_id(Core::gbk_to_utf8(request.register_id));
	std::string strMsg;
	packreq->SerializeToString(&strMsg);
	return strMsg;
}

msg_handler AssistEncoder::encode_leave(std::string const& s)
{
	DiagnosisLeaveRequest const&& request = Core::unpack_binary<DiagnosisLeaveRequest>(s);
	boost::shared_ptr<message::DiagnosisLeaveRequest> packreq(message::DiagnosisLeaveRequest::default_instance().New());
	packreq->set_diagnosis_id(Core::gbk_to_utf8(request.diagnosis_id));
	std::string strBody;
	packreq->SerializeToString(&strBody);
	return strBody;
}

msg_handler AssistEncoder::encode_leave_recover(std::string const& s)
{
	DiagnosisLeaveRecoverRequest const&& request = Core::unpack_binary<DiagnosisLeaveRecoverRequest>(s);
	boost::shared_ptr<message::DiagnosisLeaveRecoverRequest> packreq(message::DiagnosisLeaveRecoverRequest::default_instance().New());
	packreq->set_diagnosis_id(Core::gbk_to_utf8(request.diagnosis_id));
	std::string strBody;
	packreq->SerializeToString(&strBody);
	return strBody;
}

msg_handler AssistEncoder::encode_spare(std::string const& s)
{
	DiagnosisSpareRequest const&& request = Core::unpack_binary<DiagnosisSpareRequest>(s);
	boost::shared_ptr<message::DiagnosisSpareRequest> packreq(message::DiagnosisSpareRequest::default_instance().New());
	packreq->set_diagnosis_id(Core::gbk_to_utf8(request.diagnosis_id));
	packreq->set_content(Core::gbk_to_utf8(request.content));
	std::string strBody;
	packreq->SerializeToString(&strBody);
	return strBody;
}

msg_handler AssistEncoder::encode_complete(std::string const& s)
{
	DoctorCompleteRequest const&& request = Core::unpack_binary<DoctorCompleteRequest>(s);
	boost::shared_ptr<message::DoctorCompleteRequest> packreq(message::DoctorCompleteRequest::default_instance().New());
	packreq->set_datetime(Core::gbk_to_utf8(request.datetime));
	packreq->set_doctor_id(Core::gbk_to_utf8(request.doctor_id));
	std::string strBody;
	packreq->SerializeToString(&strBody);
	return strBody;
}

msg_handler AssistEncoder::encode_history(std::string const& s)
{
	IllHistoryRequest const&& request = Core::unpack_binary<IllHistoryRequest>(s);
	boost::shared_ptr<message::IllHistoryRequest> packreq(message::IllHistoryRequest::default_instance().New());
	packreq->set_patient_id(Core::gbk_to_utf8(request.patient_id));
	std::string strBody;
	packreq->SerializeToString(&strBody);
	return strBody;
}

