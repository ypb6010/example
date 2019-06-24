#include "stable.h"
#include "AssistCore.h"
#include "AssistManager.h"
#include "AssistWindowInterface.h"



AssistCore::AssistCore()
{
	
}

AssistCore::~AssistCore()
{

}

core_ptr AssistCore::creator()
{
	return boost::make_shared<this_type>();
}

void AssistCore::setMainWindow(WindowInterface* pWindow)
{
	m_pMainWindow = dynamic_cast<decltype(this->m_pMainWindow)>(pWindow);
	if (!m_pLoginWindow)
	{
		__super::setMainWindow(pWindow);		
	}
}

WindowInterface* AssistCore::mainWindow() const
{
	return m_pMainWindow;
}

void AssistCore::receipt_heartbeat(std::string const& strMsg, msg_header_t const& head)
{
	parse_header(std::move(head));
	if (strMsg.empty())
	{
		return;
	}
}

void AssistCore::initOthers()
{
	if (m_encoder)
	{
		m_encoder = boost::make_shared<Encoder>();
	}

	REG_EVENT(message::AC_COMMAND_DIAGNOSIS_HEARTBEAT_RESPONSE, receipt_heartbeat);
	REG_EVENT_ARG(message::AC_COMMAND_DIAGNOSIS_BASE_RESPONSE, DiagnosisInfoResponse, AssistWindowInterface, &AssistWindowInterface::receiptDiagnosisInfo);
	REG_EVENT_ARG(message::AC_COMMAND_DIAGNOSIS_LIST_PUSH, DiagnosisListPush, AssistWindowInterface,&AssistWindowInterface::receiptDiagnosisList);
	REG_EVENT_ARG(message::AC_COMMAND_DIAGNOSIS_BEGIN_RESPONSE, DiagnosisBeginResponse, AssistWindowInterface,&AssistWindowInterface::receiptStartSerive);
	REG_EVENT_ARG(message::AC_COMMAND_DIAGNOSIS_ACCEPT_CALL_PUSH, DiagnosisAcceptCallPush, AssistWindowInterface, &AssistWindowInterface::receiptCallNext);
	REG_EVENT_ARG(message::AC_COMMAND_DIAGNOSIS_RESPONSE_CALL_RESPONSE, DiagnosisResponseCallResponse, AssistWindowInterface, &AssistWindowInterface::receiptCallResult);
	REG_EVENT_ARG(message::AC_COMMAND_DOCTOR_SURE_PASS_PUSH, DoctorSurePassPush, AssistWindowInterface, &AssistWindowInterface::receiptSurePassPush);
	REG_EVENT_ARG(message::AC_COMMAND_DIAGNOSIS_PAUSE_PUSH, DiagnosisPausePush, AssistWindowInterface, &AssistWindowInterface::receiptPausePush);
	REG_EVENT_ARG(message::AC_COMMAND_DIAGNOSIS_LEAVE_RESPONSE, DiagnosisLeaveResponse, AssistWindowInterface, &AssistWindowInterface::receiptLeave);
	REG_EVENT_ARG(message::AC_COMMAND_DIAGNOSIS_LEAVE_RECOVER_RESPONSE, DiagnosisLeaveRecoverResponse, AssistWindowInterface, &AssistWindowInterface::receiptLeaveRecover);
	REG_EVENT_ARG(message::AC_COMMAND_DIAGNOSIS_COMPLETE_PUSH, DoctorCompletePush, AssistWindowInterface, &AssistWindowInterface::receiptCompletePush);
	REG_EVENT_ARG(message::AC_COMMAND_DIAGNOSIS_SPARE_RESPONSE, DiagnosisSpareResponse, AssistWindowInterface, &AssistWindowInterface::receiptShare);
	REG_EVENT_ARG(message::AC_COMMAND_DIAGNOSIS_HISTORY_RESPONSE, IllHistoryResponse, AssistWindowInterface, &AssistWindowInterface::receiptHistory);


	REG_ENC(message::CA_COMMAND_DIAGNOSIS_BASE_LIST_REQUEST, encode_userbase);
	REG_ENC(message::CA_COMMAND_DIAGNOSIS_BEGIN_REQUEST, encode_diagnosis);
	REG_ENC(message::CA_COMMAND_DIAGNOSIS_CALL_RESPONSE_REQUEST, encode_call_response);
	REG_ENC(message::CA_COMMAND_DIAGNOSIS_HEARTBEAT_REQUEST, encode_heartbeat);
	REG_ENC(message::CA_COMMAND_DIAGNOSIS_PAUSE_RECOVER_REQUEST, encode_pause_recover);
	REG_ENC(message::CA_COMMAND_DIAGNOSIS_PASS_RECOVER_REQUEST, encode_pass_recover);
	REG_ENC(message::CA_COMMAND_DIAGNOSIS_LEAVE_REQUEST, encode_leave);
	REG_ENC(message::CA_COMMAND_DIAGNOSIS_LEAVE_RECOVER_REQUEST, encode_leave_recover);
	REG_ENC(message::CA_COMMAND_DIAGNOSIS_SPARE_REQUEST, encode_spare);
	REG_ENC(message::CA_COMMAND_DOCTOR_COMPLETE_REQUEST, encode_complete);
	REG_ENC(message::CA_COMMAND_DIAGNOSIS_HISTORY_REQUEST, encode_history);
	__super::initOthers();
}

void AssistCore::netAreaConnect(std::string const& strMsg)
{
	__super::netAreaConnect(strMsg);
	m_pMainWindow->requesUserbase(m_localPubKey);
}
