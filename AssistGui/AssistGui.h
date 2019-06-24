#pragma once
#include <QtWidgets/QWidget>
#include "ui_AssistGui.h"

class HistoryDialog;
class ExpertsCallDialog;

class AssistGui : public QWidget, virtual public AssistWindowInterface
{
	Q_OBJECT
	typedef AssistGui this_type;
public:
	AssistGui(Core* pCore, QWidget *parent = Q_NULLPTR);
	~AssistGui();
	void initExpandTableView();

	void initMainWindow();

	void initPopup();

	virtual void receiptDiagnosisInfo(DiagnosisInfoResponse const& result) override;

	virtual void receiptLogin(std::string const strMsg){}

	virtual void receiptDiagnosisList(DiagnosisListPush const& result) override;

	virtual void receiptStartSerive(DiagnosisBeginResponse const& result) override;

	virtual void receiptCallNext(DiagnosisAcceptCallPush const& result) override;

	virtual void receiptCallResult(DiagnosisResponseCallResponse const& result) override;

	virtual void receiptSurePassPush(DoctorSurePassPush const& result) override;

	virtual void receiptPausePush(DiagnosisPausePush const& result) override;

	virtual void receiptLeave(DiagnosisLeaveResponse const& result) override;

	virtual void receiptLeaveRecover(DiagnosisLeaveRecoverResponse const& result) override;

	virtual void receiptCompletePush(DoctorCompletePush const& result) override;

	virtual void receiptShare(DiagnosisSpareResponse const& result) override;

	virtual void receiptComplete(DiagnosisCompleteResponse const& result) override;

	virtual void receiptHistory(IllHistoryResponse const& result) override;
//兼容GUI线程槽函数
private slots:
	void private_diagno_info(DiagnosisInfoResponse const& request) const;
	void private_diagnosis_list(DiagnosisListPush const& request) const;
	void private_start(DiagnosisBeginResponse const& result) const;
	void private_call_next(DiagnosisAcceptCallPush const& result);
	void private_call_result(DiagnosisResponseCallResponse const& result);
	void private_sure_pass_push(DoctorSurePassPush const& result);
	void private_pause_push(DiagnosisPausePush const& result);
	void private_leave(DiagnosisLeaveResponse const& result);
	void private_leave_recover(DiagnosisLeaveRecoverResponse const& result);
	void private_complete_push(DoctorCompletePush const& result);
	void private_complete(DiagnosisCompleteResponse const& result);
	void private_history(IllHistoryResponse const& result);
//私有响应槽函数
private:
	void on_start();
	void on_timeout();
	void on_row_clicked(QModelIndex index);
	void on_leave(bool checked);
	void on_stop();
	void on_allergy();
	void on_past();
	void on_family();
	void on_heredity();
private:
	void updatePatient();
	void updateDoctor();

	void resetPatient();
	void resetDoctor();

	void updatePages() const;
	QString string2Sex(std::string const& sex);
	void initHisDialog(HistoryDialog::WindowIndex index);
private:
	Ui::AssistGui ui;
	HistoryDialog*		m_pHisDialog;
	ExpertsCallDialog*	m_pCallDialog;
	QProcess*			m_process;
	QTimer*				m_pTimer;
	TableModel*			m_pWaitModel;
	TableModel*			m_pPassModel;
	TableModel*			m_pPauseModel;
	TableModel*			m_pCompleteModel;

	TableModel*			m_pOfflineModel;
	TableModel*			m_platelyModel;
	TableModel*			m_pHistoryModel;
	TableModel*			m_pRemoteModel;
};
