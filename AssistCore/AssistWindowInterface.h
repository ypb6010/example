#pragma once
#include "assistcore_global.h"
#include "../Core/WindowInterface.h"

class AssistCore;
class AssistManager;

class ASSISTCORE_EXPORT AssistWindowInterface :public WindowInterface
{
public:
	AssistWindowInterface(AssistCore* core);
	~AssistWindowInterface();
//请求
public:
	//初始基本信息
	virtual void requesUserbase(std::string const& pubKey);
	//请求开始
	virtual void requestStart();

	virtual void requestCallResult(bool isAgree);

	virtual void requestHeartbeat(std::string const&& s = std::string());

	virtual void requestPauseRecover(std::string const&& patient_id);

	virtual void requestPassRecover(std::string const&& patient_id);

	virtual void requestLeave();
	
	virtual void requestLeaveRecover();

	virtual void requestSpare(std::string const& strSpare);

	virtual void requestComplete();

	virtual void requestHistory(std::string const& patient_id);

//回执
public:
	virtual void receiptDiagnosisInfo(DiagnosisInfoResponse const& strMsg) = 0;

	virtual void receiptDiagnosisList(DiagnosisListPush const& request) = 0;

	virtual void receiptStartSerive(DiagnosisBeginResponse const& result) = 0;

	virtual void receiptCallNext(DiagnosisAcceptCallPush const& result) = 0;

	virtual void receiptCallResult(DiagnosisResponseCallResponse const& result) = 0;

	virtual void receiptSurePassPush(DoctorSurePassPush const& result) = 0;

	virtual void receiptPausePush(DiagnosisPausePush const& result) = 0;

	virtual void receiptLeave(DiagnosisLeaveResponse const& result) = 0;

	virtual void receiptLeaveRecover(DiagnosisLeaveRecoverResponse const& result) = 0;

	virtual void receiptCompletePush(DoctorCompletePush const& result) = 0;

	virtual void receiptShare(DiagnosisSpareResponse const& result) = 0;

	virtual void receiptComplete(DiagnosisCompleteResponse const& result) = 0;

	virtual void receiptHistory(IllHistoryResponse const& result) = 0;

protected:
	AssistCore* m_pCore;
	AssistManager* m_pManager;
};