#include "stable.h"
#include "AssistWindowInterface.h"
#include "AssistCore.h"
#include "AssistManager.h"
#include "DataManager.h"


AssistWindowInterface::AssistWindowInterface(AssistCore* core) 
	: m_pCore(core)
	, WindowInterface(core)
{
	BOOST_ASSERT_MSG(m_pCore, "核心模块初始化错误");
	m_pManager = dynamic_cast<decltype(m_pManager)>(core->appManager());
}

AssistWindowInterface::~AssistWindowInterface()
{

}

void AssistWindowInterface::requesUserbase(std::string const& pubKey)
{
	UserBaseRequest req;
	req.public_key = pubKey;
	std::string const&& localSer = Core::pack_binary(req);
	m_pCore->pack_message<message::CA_COMMAND_DIAGNOSIS_BASE_LIST_REQUEST>(std::move(localSer));
}

void AssistWindowInterface::requestStart()
{
	DiagnosisBeginRequest req;
	req.diagnosis_id = m_pManager->dataManager()->diagnosisInfo().organize_id;
	std::string const&& localSer = Core::pack_binary(req);
	m_pCore->pack_message<message::CA_COMMAND_DIAGNOSIS_BEGIN_REQUEST>(std::move(localSer));
}

void AssistWindowInterface::requestCallResult(bool isAgree)
{
	DiagnosisResponseCallRequest request;
	data_ptr data = m_pManager->dataManager();
	request.response = isAgree ? "1" : "0";
	request.doctor_id = data->currentDoctorID();
	request.register_id = data->currentRegID();
	std::string const&& localSer = Core::pack_binary(request);
	m_pCore->pack_message<message::CA_COMMAND_DIAGNOSIS_CALL_RESPONSE_REQUEST>(std::move(localSer));
}

void AssistWindowInterface::requestHeartbeat(std::string const&& s)
{
	m_pCore->pack_message<message::CA_COMMAND_DIAGNOSIS_HEARTBEAT_REQUEST>(s);
}

void AssistWindowInterface::requestPauseRecover(std::string const&& patient_id)
{
	data_ptr data = m_pManager->dataManager();
	auto&& patient = data->findPauseFromPatientID(std::move(patient_id));
	DiagnosisPauseRecoverRequest request;
	request.diagnosis_id = data->diagnosisInfo().organize_id;
	request.patient_id = patient.patient_id;
	request.register_id = patient.register_id;
	if (request.diagnosis_id.empty() && request.patient_id.empty() && request.register_id.empty())
	{
		return;
	}
	std::string const&& localSer = Core::pack_binary(request);
	m_pCore->pack_message<message::CA_COMMAND_DIAGNOSIS_PAUSE_RECOVER_REQUEST>(localSer);
}

void AssistWindowInterface::requestPassRecover(std::string const&& patient_id)
{
	data_ptr data = m_pManager->dataManager();
	auto&& patient = data->findPassFromPatientID(std::move(patient_id));
	DiagnosisPassRecoverRequest request;
	request.diagnosis_id = data->diagnosisInfo().organize_id;
	request.patient_id = patient.patient_id;
	request.register_id = patient.register_id;
	if (request.diagnosis_id.empty() && request.patient_id.empty() && request.register_id.empty())
	{
		return;
	}
	std::string const&& localSer = Core::pack_binary(request);
	m_pCore->pack_message<message::CA_COMMAND_DIAGNOSIS_PASS_RECOVER_REQUEST>(localSer);
}

void AssistWindowInterface::requestLeave()
{
	DiagnosisLeaveRequest request;
	request.diagnosis_id = m_pManager->dataManager()->diagnosisInfo().organize_id;
	std::string const&& localSer = Core::pack_binary(request);
	m_pCore->pack_message<message::CA_COMMAND_DIAGNOSIS_LEAVE_REQUEST>(localSer);
}

void AssistWindowInterface::requestLeaveRecover()
{
	DiagnosisLeaveRecoverRequest request;
	request.diagnosis_id = m_pManager->dataManager()->diagnosisInfo().organize_id;
	std::string const&& localSer = Core::pack_binary(request);
	m_pCore->pack_message<message::CA_COMMAND_DIAGNOSIS_LEAVE_RECOVER_REQUEST>(localSer);
}

void AssistWindowInterface::requestSpare(std::string const& strSpare)
{
	DiagnosisSpareRequest request;
	request.diagnosis_id = m_pManager->dataManager()->diagnosisInfo().organize_id;
	request.content = strSpare;
	std::string const&& localSer = Core::pack_binary(request);
	m_pCore->pack_message<message::CA_COMMAND_DIAGNOSIS_SPARE_REQUEST>(localSer);
}

void AssistWindowInterface::requestComplete()
{
	DoctorCompleteRequest request;
	request.doctor_id = m_pManager->dataManager()->diagnosisInfo().organize_id;
	boost::posix_time::ptime time = boost::posix_time::second_clock::local_time();
	request.datetime = boost::posix_time::to_simple_string(time);
	std::string const&& localSer = Core::pack_binary(request);
	m_pCore->pack_message<message::CA_COMMAND_DIAGNOSIS_COMPLETE_REQUEST>(localSer);
}

void AssistWindowInterface::requestHistory(std::string const& patient_id)
{
	IllHistoryRequest request;
	data_ptr data = m_pManager->dataManager();
	request.patient_id = patient_id;
	std::string const&& localSer = Core::pack_binary(request);
	m_pCore->pack_message<message::CA_COMMAND_DIAGNOSIS_HISTORY_REQUEST>(localSer);
}
