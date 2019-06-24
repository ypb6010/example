#include "stable.h"
#include "AssistDecoder.h"

AssistDecoder::AssistDecoder()
{
}


AssistDecoder::~AssistDecoder()
{
}

event_handler AssistDecoder::decode_diagnosis(std::string const& strBody)
{
	DiagnosisBeginResponse respon;
	boost::shared_ptr<message::DiagnosisBeginResponse> req(message::DiagnosisBeginResponse::default_instance().New());
	req->ParseFromString(strBody);
	respon.datetime = req->datetime();
	event_handler const&& strLocalser = Core::pack_binary(respon);
	return strLocalser;
}

event_handler AssistDecoder::decode_diagnosis_info(std::string const& strBody)
{
	DiagnosisInfoResponse respon;
	boost::shared_ptr<message::DiagnosisInfoResponse> req(message::DiagnosisInfoResponse::default_instance().New());
	req->ParseFromString(strBody);
	respon.organize_id = Core::gbk_from_utf8(req->organize_id());
	respon.organize_name = Core::gbk_from_utf8(req->organize_name());
	respon.username = Core::gbk_from_utf8(req->username());
	respon.owner = Core::gbk_from_utf8(req->owner());
	respon.phone = Core::gbk_from_utf8(req->phone());
	respon.address = Core::gbk_from_utf8(req->address());
	respon.detail_address = Core::gbk_from_utf8(req->detail_address());
	respon.longitude = req->longitude();
	respon.latitude = req->latitude();
	respon.head_image = req->head_image();
	event_handler const&& strLocalser = Core::pack_binary(respon);
	return strLocalser;
}

event_handler AssistDecoder::decode_diagnosis_list(std::string const& strBody)
{
	DiagnosisListPush respon;
	boost::shared_ptr<message::DiagnosisListPush> req(message::DiagnosisListPush::default_instance().New());
	req->ParseFromString(strBody);
	auto everyList = [](decltype(respon.wait)& data,decltype(req->wait_force())&& range)
	{
		for (auto&& elem : range)
		{
			ListProperty info;
			info.rank = elem.rank();
			info.patient_id = Core::gbk_from_utf8(elem.patient_id());
			info.register_id = Core::gbk_from_utf8(elem.register_id());
			info.doctor_id = Core::gbk_from_utf8(elem.doctor_id());
			info.doctor_name = Core::gbk_from_utf8(elem.doctor_name());
			info.patient_name = Core::gbk_from_utf8(elem.patient_name());
			info.code = Core::gbk_from_utf8(elem.code());
			info.state = Core::gbk_from_utf8(elem.state());
			info.wait_num = elem.wait_num();
			info.sex = elem.sex();
			data.push_back(info);
		}
	};
	everyList(respon.wait_force, req->wait_force());
	everyList(respon.wait, req->wait());
	everyList(respon.pause, req->pause());
	everyList(respon.pass, req->pass_());
	everyList(respon.complete, req->complete());
	event_handler const&& strLocalser = Core::pack_binary(respon);
	return strLocalser;
}

event_handler AssistDecoder::decode_next(std::string const& strBody)
{
	DiagnosisAcceptCallPush result;
	boost::shared_ptr<message::DiagnosisAcceptCallPush> respon(message::DiagnosisAcceptCallPush::default_instance().New());
	respon->ParseFromString(strBody);
	result.register_id = Core::gbk_from_utf8(respon->register_id());
	result.now_id = Core::gbk_from_utf8(respon->now_id());
	result.next_id = Core::gbk_from_utf8(respon->next_id());
	result.now = Core::gbk_from_utf8(respon->now());
	result.next = Core::gbk_from_utf8(respon->next());
	result.doctor_id = Core::gbk_from_utf8(respon->doctor_id());
	result.doctor_name = Core::gbk_from_utf8(respon->doctor_name());
	auto&& pat = respon->patient_info();
	result.patient_info.patient_id = Core::gbk_from_utf8(pat.patient_id());
	result.patient_info.code = Core::gbk_from_utf8(pat.code());
	result.patient_info.name = Core::gbk_from_utf8(pat.name());
	result.patient_info.sex = Core::gbk_from_utf8(pat.sex());
	result.patient_info.id_card = Core::gbk_from_utf8(pat.id_card());
	result.patient_info.phone = Core::gbk_from_utf8(pat.phone());
	result.patient_info.birthday = Core::gbk_from_utf8(pat.birthday());
	result.patient_info.address = Core::gbk_from_utf8(pat.address());
	result.patient_info.avatar = pat.avatar();
	auto&& doctor = respon->doctor_info();
	result.doctor_info.doctor_id = Core::gbk_from_utf8(doctor.doctor_id());
	result.doctor_info.doctor_name = Core::gbk_from_utf8(doctor.doctor_name());
	result.doctor_info.username = Core::gbk_from_utf8(doctor.username());
	result.doctor_info.sex = Core::gbk_from_utf8(doctor.sex());
	result.doctor_info.hospital_uuid = Core::gbk_from_utf8(doctor.hospital_uuid());
	result.doctor_info.hospital_name = Core::gbk_from_utf8(doctor.hospital_name());
	result.doctor_info.office_uuid = Core::gbk_from_utf8(doctor.office_uuid());
	result.doctor_info.office_name = Core::gbk_from_utf8(doctor.office_name());
	result.doctor_info.duty_name = Core::gbk_from_utf8(doctor.duty_name());
	result.doctor_info.phone = Core::gbk_from_utf8(doctor.phone());
	result.doctor_info.head_image = doctor.head_image();
	event_handler const&& strLocalser = Core::pack_binary(result);
	return strLocalser;
}

event_handler AssistDecoder::decode_response_call(std::string const& strBody)
{
	DiagnosisResponseCallResponse result;
	boost::shared_ptr<message::DiagnosisResponseCallResponse> respon(message::DiagnosisResponseCallResponse::default_instance().New());
	respon->ParseFromString(strBody);
	result.register_id = Core::gbk_from_utf8(respon->register_id());
	result.response = Core::gbk_from_utf8(respon->response());
	result.room = Core::gbk_from_utf8(respon->room());
	result.result = Core::gbk_from_utf8(respon->result());
	result.reason = Core::gbk_from_utf8(respon->reason());
	event_handler const&& strLocalser = Core::pack_binary(result);
	return strLocalser;
}

event_handler AssistDecoder::decode_sure_pass_push(std::string const& strBody)
{
	DoctorSurePassPush result;
	boost::shared_ptr<message::DoctorSurePassPush> respon(message::DoctorSurePassPush::default_instance().New());
	respon->ParseFromString(strBody);
	result.datetime = Core::gbk_from_utf8(respon->datetime());
	result.register_id = Core::gbk_from_utf8(respon->register_id());
	result.doctor_id = Core::gbk_from_utf8(respon->doctor_id());
	result.patient_id = Core::gbk_from_utf8(respon->patient_id());
	event_handler const&& strLocalser = Core::pack_binary(result);
	return strLocalser;
}

event_handler AssistDecoder::decode_pause_push(std::string const& strBody)
{
	DiagnosisPausePush result;
	boost::shared_ptr<message::DiagnosisPausePush> respon(message::DiagnosisPausePush::default_instance().New());
	respon->ParseFromString(strBody);
	result.diagnosis_id = Core::gbk_from_utf8(respon->diagnosis_id());
	result.doctor_id = Core::gbk_from_utf8(respon->doctor_id());
	result.patient_id = Core::gbk_from_utf8(respon->patient_id());
	result.register_id = Core::gbk_from_utf8(respon->register_id());
	event_handler const&& strLocalser = Core::pack_binary(result);
	return strLocalser;
}

event_handler AssistDecoder::decode_leave(std::string const& strBody)
{
	DiagnosisLeaveResponse result;
	boost::shared_ptr<message::DiagnosisLeaveResponse> respon(message::DiagnosisLeaveResponse::default_instance().New());
	respon->ParseFromString(strBody);
	result.diagnosis_id = Core::gbk_from_utf8(respon->diagnosis_id());
	result.datetime = Core::gbk_from_utf8(respon->datetime());
	event_handler const&& strLocalser = Core::pack_binary(result);
	return strLocalser;
}

event_handler AssistDecoder::decode_leave_recover(std::string const& strBody)
{
	DiagnosisLeaveRecoverResponse result;
	boost::shared_ptr<message::DiagnosisLeaveRecoverResponse> respon(message::DiagnosisLeaveRecoverResponse::default_instance().New());
	respon->ParseFromString(strBody);
	result.diagnosis_id = Core::gbk_from_utf8(respon->diagnosis_id());
	result.datetime = Core::gbk_from_utf8(respon->datetime());
	event_handler const&& strLocalser = Core::pack_binary(result);
	return strLocalser;
}

event_handler AssistDecoder::decode_complte_push(std::string const& strBody)
{
	DoctorCompletePush result;
	boost::shared_ptr<message::DoctorCompletePush> respon(message::DoctorCompletePush::default_instance().New());
	respon->ParseFromString(strBody);
	result.doctor_id = Core::gbk_from_utf8(respon->doctor_id());
	result.treat_main = Core::gbk_from_utf8(respon->treat_main());
	result.treat_propose = Core::gbk_from_utf8(respon->treat_propose());
	result.deal_propose = Core::gbk_from_utf8(respon->deal_propose());
	result.prescript_propose = Core::gbk_from_utf8(respon->prescript_propose());
	event_handler const&& strLocalSer = Core::pack_binary(result);
	return strLocalSer;
}

event_handler AssistDecoder::decode_spare(std::string const& strBody)
{
	DiagnosisSpareResponse result;
	boost::shared_ptr<message::DiagnosisSpareResponse> respon(message::DiagnosisSpareResponse::default_instance().New());
	respon->ParseFromString(strBody);
	result.diagnosis_id = Core::gbk_from_utf8(respon->diagnosis_id());
	result.datetime = Core::gbk_from_utf8(respon->datetime());
	event_handler const&& strLocalSer = Core::pack_binary(result);
	return strLocalSer;
}

event_handler AssistDecoder::decode_doctro_complete(std::string const& strBody)
{
	DiagnosisCompleteResponse result;
	boost::shared_ptr<message::DiagnosisCompleteResponse> respon(message::DiagnosisCompleteResponse::default_instance().New());
	respon->ParseFromString(strBody);
	result.datetime = Core::gbk_from_utf8(respon->datetime());
	result.diagnosis = Core::gbk_from_utf8(respon->diagnosis_id());
	event_handler const&& strLocalSer = Core::pack_binary(result);
	return strLocalSer;
}

event_handler AssistDecoder::decode_history(std::string const& strBody)
{
	IllHistoryResponse result;
	boost::shared_ptr<message::IllHistoryResponse> respon(message::IllHistoryResponse::default_instance().New());
	respon->ParseFromString(strBody);
	auto everyHistory = [](std::list<ListContent>& list, auto rang)
	{
		for (auto&& value : rang)
		{
			ListContent v{ Core::gbk_from_utf8(value.content()),Core::gbk_from_utf8(value.patient_id()),Core::gbk_from_utf8(value.doctor_id()),Core::gbk_from_utf8(value.datetime()) };
			list.push_back(v);
		}
	};
	everyHistory(result.drug, respon->drug());
	everyHistory(result.past, respon->past());
	everyHistory(result.family, respon->family());
	everyHistory(result.genetic, respon->genetic());
	event_handler const&& strLocalSer = Core::pack_binary(result);
	return strLocalSer;
	
}

