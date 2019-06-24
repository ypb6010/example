#include "stable.h"
#include "ExpertsCore.h"
#include "ExpertsWindowInterface.h"

ExpertsCore::ExpertsCore()
{
}

core_ptr ExpertsCore::creator()
{
	return boost::make_shared<this_type>();
}

void ExpertsCore::setMainWindow(WindowInterface* pWindow)
{
	m_pMainWindow = dynamic_cast<decltype(this->m_pMainWindow)>(pWindow);
	if (!m_pLoginWindow)
	{
		__super::setMainWindow(pWindow);
	}
}

WindowInterface* ExpertsCore::mainWindow() const
{
	return m_pMainWindow;
}

void ExpertsCore::initOthers()
{
	if (m_encoder)
	{
		m_encoder = boost::make_shared<Encoder>();
	}	
	REG_EVENT(message::AC_COMMAND_DOCTOR_HEARTBEAT_RESPONSE, receipt_heartbeat);
	REG_EVENT_ARG(message::AC_COMMAND_DOCTOR_BEGIN_RESPONSE, DoctorBeginResponse, ExpertsWindowInterface, &ExpertsWindowInterface::receiptBegin);
	REG_EVENT_ARG(message::AC_COMMAND_DOCTOR_BASE_RESPONSE, DoctorInfoResponse, ExpertsWindowInterface, &ExpertsWindowInterface::receiptDoctorInfo);
	REG_EVENT_ARG(message::AC_COMMAND_DOCTOR_LIST_PUSH, DiagnosisListPush, ExpertsWindowInterface, &ExpertsWindowInterface::receiptExpertsList);
	REG_EVENT_ARG(message::AC_COMMAND_DOCTOR_CALL_RESPONSE, DoctorCallResponse, ExpertsWindowInterface, &ExpertsWindowInterface::receiptCallNext);
	REG_EVENT_ARG(message::AC_COMMAND_DOCTOR_ACCEPT_CALL_RESULT_PUSH, DoctorAcceptCallResultPush, ExpertsWindowInterface, &ExpertsWindowInterface::receiptCallResult);
	REG_EVENT_ARG(message::AC_COMMAND_DOCTOR_ROOM_ID_PUSH, DoctorRoomIDPush, ExpertsWindowInterface, &ExpertsWindowInterface::receiptRoomPush);
	REG_EVENT_ARG(message::AC_COMMAND_DOCTOR_SURE_PASS_RESPONSE, DoctorSurePassResponse, ExpertsWindowInterface, &ExpertsWindowInterface::receiptSurePass);
	REG_EVENT_ARG(message::AC_COMMAND_DOCTOR_PAUSE_RESPONSE, DoctorPauseResponse, ExpertsWindowInterface, &ExpertsWindowInterface::receiptPause);
	REG_EVENT_ARG(message::AC_COMMAND_DOCTOR_STOP_RESPONSE, DoctorStopResponse, ExpertsWindowInterface, &ExpertsWindowInterface::receiptStop);
	REG_EVENT_ARG(message::AC_COMMAND_DOCTOR_LEAVE_RESPONSE, DoctorLeaveResponse, ExpertsWindowInterface, &ExpertsWindowInterface::receiptLeave);
	REG_EVENT_ARG(message::AC_COMMAND_DOCTOR_LEAVE_RECOVER_RESPONSE, DoctorLeaveRecoverResponse, ExpertsWindowInterface, &ExpertsWindowInterface::receiptLeaveRecover);
	REG_EVENT_ARG(message::AC_COMMAND_DOCTOR_COMPLETE_RESPONSE, DoctorCompleteResponse, ExpertsWindowInterface, &ExpertsWindowInterface::receiptComplete);
	REG_EVENT_ARG(message::AC_COMMAND_DOCTOR_HISTORY_RESPONSE, IllHistoryResponse, ExpertsWindowInterface, &ExpertsWindowInterface::receiptHistory);
	REG_EVENT_ARG(message::AC_COMMAND_DOCTOR_HISTORY_ADD_RESPONSE, IllHistoryAddResponse, ExpertsWindowInterface, &ExpertsWindowInterface::receiptAddHistory);


	REG_ENC(message::CA_COMMAND_DOCTOR_BASE_LIST_REQUEST, encode_userbase);
	REG_ENC(message::CA_COMMAND_DOCTOR_BEGIN_REQUEST, encode_start_service);
	REG_ENC(message::CA_COMMAND_DOCTOR_CALL_REQUEST, encode_call_next);
	REG_ENC(message::CA_COMMAND_DOCTOR_HEARTBEAT_REQUEST, encode_heartbeat);
	REG_ENC(message::CA_COMMAND_DOCTOR_SURE_PASS_REQUEST, encode_sure_pass);
	REG_ENC(message::CA_COMMAND_DOCTOR_PAUSE_REQUEST, encode_pause);
	REG_ENC(message::CA_COMMAND_DOCTOR_STOP_REQUEST, encode_stop);
	REG_ENC(message::CA_COMMAND_DOCTOR_LEAVE_REQUEST, encode_leave);
	REG_ENC(message::CA_COMMAND_DOCTOR_LEAVE_RECOVER_REQUEST, encode_leave_recover);
	REG_ENC(message::CA_COMMAND_DOCTOR_COMPLETE_REQUEST, encode_complete);
	REG_ENC(message::CA_COMMAND_DOCTOR_HISTORY_REQUEST, encode_history);
	REG_ENC(message::CA_COMMAND_DOCTOR_HISTORY_ADD_REQUEST, encode_add_history);
	__super::initOthers();
}

void ExpertsCore::netAreaConnect(std::string const& strMsg)
{
	__super::netAreaConnect(strMsg);
	m_pMainWindow->requesUserbase(m_localPubKey);
}

void ExpertsCore::receipt_heartbeat(std::string const& strMsg, msg_header_t const& head)
{
	parse_header(std::move(head));
	if (!strMsg.empty())
	{
		debug_out << strMsg << std::endl;
		return;
	}
}
