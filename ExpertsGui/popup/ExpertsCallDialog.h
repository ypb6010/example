#pragma once

#include <QDialog>
#include "ui_ExpertsCallDialog.h"

class CallAssistDialog : public QDialog
{
	Q_OBJECT

public:
	CallAssistDialog(QWidget *parent = Q_NULLPTR);
	~CallAssistDialog();
	void init();
	void setTitle(QString const& strTitle);
	void setPatient(PatientBaseInfo const& patient);
	void setDoctor(DiagnosisInfoResponse const& assist);
	void assistAgree();
	void assistDisagree();
	int waitTimeSec();
private slots:
	void timeout_slot();
private:
	QString string2Sex(std::string const& sex);
private:
	Ui::CallAssistDialog ui;
	int m_timeMes;
	QTimer* m_ptimer;
protected:
	virtual void showEvent(QShowEvent *e) override;

};
