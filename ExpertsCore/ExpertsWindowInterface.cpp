#include "stable.h"
#include "ExpertsWindowInterface.h"
#include "ExpertsCore.h"
#include "ExpertsManager.h"
#include "DataManager.h"

ExpertsWindowInterface::ExpertsWindowInterface(ExpertsCore* core)
	: m_pCore(core)
	, WindowInterface(core)
{
	BOOST_ASSERT_MSG(m_pCore, "核心模块初始化错误");
	m_pManager = dynamic_cast<decltype(m_pManager)>(m_pCore->appManager());
}

ExpertsWindowInterface::~ExpertsWindowInterface()
{

}

void ExpertsWindowInterface::requesUserbase(std::string const& pubKey)
{
	UserBaseRequest req;
	req.public_key = pubKey;
	std::string const&& localSer = Core::pack_binary(req);
	m_pCore->pack_message<message::CA_COMMAND_DOCTOR_BASE_LIST_REQUEST>(std::move(localSer));
}

void ExpertsWindowInterface::requestStart()
{
	DoctorBeginRequest req;
	const boost::posix_time::ptime now = boost::posix_time::second_clock::local_time();
	auto tm = boost::posix_time::to_tm(now);
	if (tm.tm_hour > 12)
	{
		req.begin_type = "1";
	}
	else
	{
		req.begin_type = "0";
	}
	req.doctor_id = m_pManager->dataManager()->doctorInfo().doctor_id;
	std::string const&& localSer = Core::pack_binary(req);
	m_pCore->pack_message<message::CA_COMMAND_DOCTOR_BEGIN_REQUEST>(std::move(localSer));
}

void ExpertsWindowInterface::requestCallNext()
{
	DioctorCallRequest req;
	data_ptr data = m_pManager->dataManager();
	req.doctor_id = data->doctorInfo().doctor_id;
	std::string const&& localSer = Core::pack_binary(req);
	m_pCore->pack_message<message::CA_COMMAND_DOCTOR_CALL_REQUEST>(localSer);
}

void ExpertsWindowInterface::requestPassPat(int32_t waitSec)
{
	data_ptr data = m_pManager->dataManager();
	DoctorSurePassRequest request;
	request.doctor_id = data->doctorInfo().doctor_id;
	request.register_id = data->currentRegID();
	request.wait_time = waitSec;
	std::string const&& localSer = Core::pack_binary(request);
	m_pCore->pack_message<message::CA_COMMAND_DOCTOR_SURE_PASS_REQUEST>(localSer);
}

void ExpertsWindowInterface::requestHeartbeat(std::string const&& s)
{
	m_pCore->pack_message<message::CA_COMMAND_DOCTOR_HEARTBEAT_REQUEST>(s);
}

void ExpertsWindowInterface::requestPausePat()
{
	data_ptr data = m_pManager->dataManager();
	DoctorPauseRequest request;
	request.doctor_id = data->doctorInfo().doctor_id;
	request.register_id = data->currentRegID();
	request.diagnosis_id = data->currentAssistID();
	request.patient_id = data->currentPatID();
	std::string const&& localSer = Core::pack_binary(request);
	m_pCore->pack_message<message::CA_COMMAND_DOCTOR_PAUSE_REQUEST>(localSer);
}

void ExpertsWindowInterface::requestComplete(std::string const& treat_main, std::string const& treat_propose, std::string const& deal_propose, std::string const& prescript_propose)
{
	DoctorStopRequest request;
	const boost::posix_time::ptime now = boost::posix_time::second_clock::local_time();
	data_ptr data = m_pManager->dataManager();
	request.doctor_id = data->doctorInfo().doctor_id;
	request.register_id = data->currentRegID();
	request.patient_id = data->currentPatID();
	request.diagnosis_id = data->currentAssistID();
	request.datetime = boost::posix_time::to_simple_string(now);
	request.treat_main = treat_main;
	request.treat_propose = treat_propose;
	request.deal_propose = deal_propose;
	request.prescript_propose = prescript_propose;
	std::string const&& localSer = Core::pack_binary(request);
	m_pCore->pack_message<message::CA_COMMAND_DOCTOR_STOP_REQUEST>(localSer);
}

void ExpertsWindowInterface::requestLeave()
{
	DoctorLeaveRequest request;
	request.doctor_id = m_pManager->dataManager()->doctorInfo().doctor_id;
	std::string const&& localSer = Core::pack_binary(request);
	m_pCore->pack_message<message::CA_COMMAND_DOCTOR_LEAVE_REQUEST>(localSer);
}

void ExpertsWindowInterface::requestLeaveRecover()
{
	DoctorLeaveRecoverRequest request;
	request.doctor_id = m_pManager->dataManager()->doctorInfo().doctor_id;
	std::string const&& localSer = Core::pack_binary(request);
	m_pCore->pack_message<message::CA_COMMAND_DOCTOR_LEAVE_RECOVER_REQUEST>(localSer);
}

void ExpertsWindowInterface::requestDoctorComplete()
{
	DoctorCompleteRequest request;
	const boost::posix_time::ptime now = boost::posix_time::second_clock::local_time();
	request.datetime = boost::posix_time::to_simple_string(now);
	request.doctor_id = m_pManager->dataManager()->doctorInfo().doctor_id;
	std::string const&& localSer = Core::pack_binary(request);
	m_pCore->pack_message<message::CA_COMMAND_DOCTOR_COMPLETE_REQUEST>(localSer);
}

void ExpertsWindowInterface::requestHistory(std::string const& patient_id)
{
	IllHistoryRequest request;
	request.patient_id = patient_id;
	std::string const&& localSer = Core::pack_binary(request);
	m_pCore->pack_message<message::CA_COMMAND_DOCTOR_HISTORY_REQUEST>(localSer);
}

void ExpertsWindowInterface::requestAddHistory(int32_t ill_type, std::string const& content)
{
	IllHistoryAddRequest request;
	data_ptr data = m_pManager->dataManager();
	request.content = content;
	request.ill_type = ill_type;
	request.doctor_id = data->doctorInfo().doctor_id;
	request.patient_id = data->currentPatID();
	std::string const&& localSer = Core::pack_binary(request);
	m_pCore->pack_message<message::CA_COMMAND_DIAGNOSIS_HISTORY_REQUEST>(localSer);
}

