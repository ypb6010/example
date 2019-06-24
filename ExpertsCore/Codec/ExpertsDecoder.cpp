#include "stable.h"
#include "ExpertsDecoder.h"


ExpertsDecoder::ExpertsDecoder()
{
}


ExpertsDecoder::~ExpertsDecoder()
{
}

event_handler ExpertsDecoder::decode_doctor_info(std::string const& strBody)
{
	DoctorInfoResponse result;
	boost::shared_ptr<message::DoctorInfoResponse> respone(message::DoctorInfoResponse::default_instance().New());
	respone->ParseFromString(strBody);
	result.doctor_id = Core::gbk_from_utf8(respone->doctor_id());
	result.doctor_name = Core::gbk_from_utf8(respone->doctor_name());
	result.duty_name = Core::gbk_from_utf8(respone->duty_name());
	result.head_image = respone->head_image();
	result.hospital_name = Core::gbk_from_utf8(respone->hospital_name());
	result.hospital_uuid = Core::gbk_from_utf8(respone->hospital_uuid());
	result.office_name = Core::gbk_from_utf8(respone->office_name());
	result.office_uuid = Core::gbk_from_utf8(respone->office_uuid());
	result.phone = Core::gbk_from_utf8(respone->phone());
	result.sex = Core::gbk_from_utf8(respone->sex());
	result.username = Core::gbk_from_utf8(respone->username());
	event_handler const&& strLocalser = Core::pack_binary(result);
	return strLocalser;
}

event_handler ExpertsDecoder::decode_list_push(std::string const& strBody)
{
	DiagnosisListPush result;
	boost::shared_ptr<message::DiagnosisListPush> respon(message::DiagnosisListPush::default_instance().New());
	respon->ParseFromString(strBody);
	auto everyList = [](decltype(result.wait)& data, decltype(respon->wait_force()) && range)
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
	everyList(result.wait_force, respon->wait_force());
	everyList(result.wait, respon->wait());
	everyList(result.pause, respon->pause());
	everyList(result.pass, respon->pass_());
	everyList(result.complete, respon->complete());
	event_handler const&& strLocalser = Core::pack_binary(result);
	return strLocalser;
}

event_handler ExpertsDecoder::decode_begin(std::string const& strBody)
{
	DoctorBeginResponse result;
	boost::shared_ptr<message::DoctorBeginResponse> respon(message::DoctorBeginResponse::default_instance().New());
	respon->ParseFromString(strBody);
	result.reason = Core::gbk_from_utf8(respon->reason());
	result.result = Core::gbk_from_utf8(respon->result());
	event_handler const&& strLocalser = Core::pack_binary(result);
	return strLocalser;
}

event_handler ExpertsDecoder::decode_call_next_result(std::string const& strBody)
{
	DoctorCallResponse result;
	boost::shared_ptr<message::DoctorCallResponse> respon(message::DoctorCallResponse::default_instance().New());
	respon->ParseFromString(strBody);
	result.res = Core::gbk_from_utf8(respon->res());
	result.register_id = Core::gbk_from_utf8(respon->register_id());
	result.now_id = Core::gbk_from_utf8(respon->now_id());
	result.next_id = Core::gbk_from_utf8(respon->next_id());
	result.now = Core::gbk_from_utf8(respon->now());
	result.next = Core::gbk_from_utf8(respon->next());
	result.diagnosis_id = Core::gbk_from_utf8(respon->diagnosis_id());
	result.diagnosis_name = Core::gbk_from_utf8(respon->diagnosis_name());
	auto patInfo = respon->patient_info();
	result.patient_info.patient_id = Core::gbk_from_utf8(patInfo.patient_id());
	result.patient_info.code = Core::gbk_from_utf8(patInfo.code());
	result.patient_info.name = Core::gbk_from_utf8(patInfo.name());
	result.patient_info.sex = Core::gbk_from_utf8(patInfo.sex());
	result.patient_info.id_card = Core::gbk_from_utf8(patInfo.id_card());
	result.patient_info.phone = Core::gbk_from_utf8(patInfo.phone());
	result.patient_info.birthday = Core::gbk_from_utf8(patInfo.birthday());
	result.patient_info.address = Core::gbk_from_utf8(patInfo.address());
	result.patient_info.avatar = patInfo.avatar();
	auto diagnosisInfo = respon->diagnosis_info();
	result.diagnosis_info.organize_id = Core::gbk_from_utf8(diagnosisInfo.organize_id());
	result.diagnosis_info.organize_name = Core::gbk_from_utf8(diagnosisInfo.organize_name());
	result.diagnosis_info.username = Core::gbk_from_utf8(diagnosisInfo.username());
	result.diagnosis_info.owner = Core::gbk_from_utf8(diagnosisInfo.owner());
	result.diagnosis_info.phone = Core::gbk_from_utf8(diagnosisInfo.phone());
	result.diagnosis_info.address = Core::gbk_from_utf8(diagnosisInfo.address());
	result.diagnosis_info.detail_address = Core::gbk_from_utf8(diagnosisInfo.detail_address());
	result.diagnosis_info.longitude = diagnosisInfo.longitude();
	result.diagnosis_info.latitude = diagnosisInfo.latitude();
	result.diagnosis_info.head_image = diagnosisInfo.head_image();
	event_handler const&& strLocalser = Core::pack_binary(result);
	return strLocalser;
}

event_handler ExpertsDecoder::decode_call_result(std::string const& strBody)
{
	DoctorAcceptCallResultPush result;
	boost::shared_ptr<message::DoctorAcceptCallResultPush> respon(message::DoctorAcceptCallResultPush::default_instance().New());
	respon->ParseFromString(strBody);
	result.register_id = Core::gbk_from_utf8(respon->register_id());
	result.response = Core::gbk_from_utf8(respon->response());
	event_handler const&& strLocalSer = Core::pack_binary(result);
	return strLocalSer;
}

event_handler ExpertsDecoder::decode_pause(std::string const& strBody)
{
	DoctorPauseResponse result;
	boost::shared_ptr<message::DoctorPauseResponse> respon(message::DoctorPauseResponse::default_instance().New());
	respon->ParseFromString(strBody);
	result.diagnosis_id = Core::gbk_from_utf8(respon->diagnosis_id());
	result.register_id = Core::gbk_from_utf8(respon->register_id());
	result.doctor_id = Core::gbk_from_utf8(respon->doctor_id());
	result.patient_id = Core::gbk_from_utf8(respon->patient_id());
	event_handler const&& strLocalSer = Core::pack_binary(result);
	return strLocalSer;
}

event_handler ExpertsDecoder::decode_room_id_push(std::string const& strBody)
{
	DoctorRoomIDPush result;
	boost::shared_ptr<message::DoctorRoomIDPush> respon(message::DoctorRoomIDPush::default_instance().New());
	respon->ParseFromString(strBody);
	result.doctor_id = Core::gbk_from_utf8(respon->doctor_id());
	result.room_id = Core::gbk_from_utf8(respon->room_id());
	event_handler const&& strLocalSer = Core::pack_binary(result);
	return strLocalSer;
}

event_handler ExpertsDecoder::decode_sure_pass(std::string const& strBody)
{
	DoctorSurePassResponse result;
	boost::shared_ptr<message::DoctorSurePassResponse> respon(message::DoctorSurePassResponse::default_instance().New());
	respon->ParseFromString(strBody);
	result.datetime = Core::gbk_from_utf8(respon->datetime());
	result.register_id = Core::gbk_from_utf8(respon->register_id());
	result.doctor_id = Core::gbk_from_utf8(respon->doctor_id());
	result.result = Core::gbk_from_utf8(respon->result());
	result.reason = Core::gbk_from_utf8(respon->reason());
	event_handler const&& strLocalSer = Core::pack_binary(result);
	return strLocalSer;
}

event_handler ExpertsDecoder::decode_stop(std::string const& strBody)
{
	DoctorStopResponse result;
	boost::shared_ptr<message::DoctorStopResponse> respon(message::DoctorStopResponse::default_instance().New());
	respon->ParseFromString(strBody);
	result.result = Core::gbk_from_utf8(respon->result());
	result.reason = Core::gbk_from_utf8(respon->reason());
	event_handler const&& strLocalSer = Core::pack_binary(result);
	return strLocalSer;
}

event_handler ExpertsDecoder::decode_leave(std::string const& strBody)
{
	DoctorLeaveResponse result;
	boost::shared_ptr<message::DoctorLeaveResponse> respon(message::DoctorLeaveResponse::default_instance().New());
	respon->ParseFromString(strBody);
	result.doctor_id = Core::gbk_from_utf8(respon->doctor_id());
	result.datetime = Core::gbk_from_utf8(respon->datetime());
	event_handler const&& strLocalSer = Core::pack_binary(result);
	return strLocalSer;
}

event_handler ExpertsDecoder::decode_leave_recover(std::string const& strBody)
{
	DoctorLeaveRecoverResponse result;
	boost::shared_ptr<message::DoctorLeaveRecoverResponse> respon(message::DoctorLeaveRecoverResponse::default_instance().New());
	respon->ParseFromString(strBody);
	result.datetime = Core::gbk_from_utf8(respon->datetime());
	result.doctor_id = Core::gbk_from_utf8(respon->doctor_id());
	event_handler const&& strLocalSer = Core::pack_binary(result);
	return strLocalSer;
}

event_handler ExpertsDecoder::decode_complete(std::string const& strBody)
{
	DoctorCompleteResponse result;
	boost::shared_ptr<message::DoctorCompleteResponse> respon(message::DoctorCompleteResponse::default_instance().New());
	respon->ParseFromString(strBody);
	result.datetime = Core::gbk_from_utf8(respon->datetime());
	result.doctor_id = Core::gbk_from_utf8(respon->doctor_id());
	event_handler const&& strLocalSer = Core::pack_binary(result);
	return strLocalSer;
}

event_handler ExpertsDecoder::decode_history(std::string const& strBody)
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

event_handler ExpertsDecoder::decode_add_history(std::string const& strBody)
{
	IllHistoryAddResponse result;
	boost::shared_ptr<message::IllHistoryAddResponse> respon(message::IllHistoryAddResponse::default_instance().New());
	respon->ParseFromString(strBody);
	result.patient_id = Core::gbk_from_utf8(respon->patient_id());
	result.datetime = Core::gbk_from_utf8(respon->datetime());
	event_handler const&& strLocalSer = Core::pack_binary(result);
	return strLocalSer;
}
