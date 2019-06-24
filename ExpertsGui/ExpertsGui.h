#pragma once

#include <QWidget>
#include "ui_ExpertsGui.h"

class CallAssistDialog;
class HistoryDialog;

class ExpertsGui : public QWidget , virtual public ExpertsWindowInterface
{
	Q_OBJECT
	typedef ExpertsGui this_type;
public:
	ExpertsGui(Core* pCore, QWidget *parent = Q_NULLPTR);
	~ExpertsGui();

	void initLeftTableView();

	void initMainWindow();

	void initPopup();

	//重写的接口
public:
	virtual void receiptLogin(std::string const strMsg) override{}

	virtual void receiptDoctorInfo(DoctorInfoResponse const& result) override;

	virtual void receiptExpertsList(DiagnosisListPush const& result) override;

	virtual void receiptBegin(DoctorBeginResponse const& result) override;

	virtual void receiptCallNext(DoctorCallResponse const& result) override;

	virtual void receiptCallResult(DoctorAcceptCallResultPush const& result) override;

	virtual void receiptPause(DoctorPauseResponse const& result) override;

	virtual void receiptRoomPush(DoctorRoomIDPush const& result) override;

	virtual void receiptSurePass(DoctorSurePassResponse const& result) override;

	virtual void receiptStop(DoctorStopResponse const& result) override;

	virtual void receiptLeave(DoctorLeaveResponse const& result) override;

	virtual void receiptLeaveRecover(DoctorLeaveRecoverResponse const& result) override;

	virtual void receiptComplete(DoctorCompleteResponse const& result) override;

	virtual void receiptHistory(IllHistoryResponse const& result) override;

	virtual void receiptAddHistory(IllHistoryAddResponse const& result) override;
private slots:
	void private_doctor_info(DoctorInfoResponse const& result);

	void private_doctor_list(DiagnosisListPush const& result);

	void private_begin(DoctorBeginResponse const& result);

	void private_call_next(DoctorCallResponse const& result);

	void private_call_result(DoctorAcceptCallResultPush const& result);

	void private_pause(DoctorPauseResponse const& result);

	void private_stop(DoctorStopResponse const& result);

	void private_leave(DoctorLeaveResponse const& result);

	void private_leave_recover(DoctorLeaveRecoverResponse const& result);

	void private_doctor_complete(DoctorCompleteResponse const& result);

	void private_sure_pass(DoctorSurePassResponse const& result);

	void private_history(IllHistoryResponse const& result);
private:
	void on_start();
	void on_leave(bool checked);
	void on_stop();
	void on_call_next();
	void on_timeout(); 
	void on_pause();
	void on_complete();
	void on_video();

	void on_allergy();
	void on_past();
	void on_family();
	void on_heredity();

	void on_add_drug();
	void on_add_past();
	void on_add_family();
	void on_add_genetic();
private:
	void waitState();
	void workState();
	void updatePages();
	void updatePatient();
	void updateAssist();
	void resetPatient();
	void resetDoctor();
	void enterRoom();
	QString string2Sex(std::string const& sex);
	void initHisDialog(HistoryDialog::WindowIndex index);
private:
	CallAssistDialog*	m_pCallAssist;
	HistoryDialog*		m_pHisDialog;
	QTimer*				m_pTimer;
	QProcess*			m_process;
	Ui::ExpertsGuiClass ui;

	TableModel* m_pWaitModel;
	TableModel* m_pPassModel;
	TableModel* m_pPauseModel;
	TableModel* m_pCompleteModel;

	TableModel* m_platelyModel;
	TableModel* m_pHistoryModel;
	TableModel* m_pRemoteModel;
};
