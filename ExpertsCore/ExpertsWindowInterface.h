#pragma once
#include "expertscore_global.h"
#include "../Core/WindowInterface.h"
class ExpertsCore;
class ExpertsManager;

class EXPERTSCORE_EXPORT ExpertsWindowInterface :public WindowInterface
{
public:
	ExpertsWindowInterface(ExpertsCore* core);
	~ExpertsWindowInterface();
//请求
public:
	//第一次登陆到区域服，传输公钥，请求基本信息
	virtual void requesUserbase(std::string const& pubKey);		
	//开始门诊请求
	virtual void requestStart();	
	//请求叫号
	virtual void requestCallNext();
	//请求过号
	virtual void requestPassPat(int32_t waitSec);
	//心跳请求
	virtual void requestHeartbeat(std::string const&& s = std::string());

	virtual void requestPausePat();

	virtual void requestComplete(std::string const& treat_main, std::string const& treat_propose, std::string const& deal_propose, std::string const& prescript_propose);

	virtual void requestLeave();

	virtual void requestLeaveRecover();

	virtual void requestDoctorComplete();

	virtual void requestHistory(std::string const& patient_id);

	virtual void requestAddHistory(int32_t ill_type, std::string const& content);

//回执
public:
	//获得医生信息
	virtual void receiptDoctorInfo(DoctorInfoResponse const& result) = 0;
	//获取初始状态列表
	virtual void receiptExpertsList(DiagnosisListPush const& request) = 0;
	//开始门诊响应
	virtual void receiptBegin(DoctorBeginResponse const& result) = 0;
	//专家叫号等待响应
	virtual void receiptCallNext(DoctorCallResponse const& result) = 0;
	//专家叫号后助诊的响应回执
	virtual void receiptCallResult(DoctorAcceptCallResultPush const& result) = 0;

	virtual void receiptPause(DoctorPauseResponse const& result) = 0;

	virtual void receiptRoomPush(DoctorRoomIDPush const& result) = 0;

	virtual void receiptSurePass(DoctorSurePassResponse const& result) = 0;

	virtual void receiptStop(DoctorStopResponse const& result) = 0;

	virtual void receiptLeave(DoctorLeaveResponse const& result) = 0;

	virtual void receiptLeaveRecover(DoctorLeaveRecoverResponse const& result) = 0;

	virtual void receiptComplete(DoctorCompleteResponse const& result) = 0;

	virtual void receiptHistory(IllHistoryResponse const& result) = 0;

	virtual void receiptAddHistory(IllHistoryAddResponse const& result) = 0;
protected:
	ExpertsCore* m_pCore;
	ExpertsManager* m_pManager;
};