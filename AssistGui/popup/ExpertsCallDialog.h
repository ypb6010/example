#pragma once

#include <QDialog>
#include "ui_ExpertsCallDialog.h"

class ExpertsCallDialog : public QDialog
{
	Q_OBJECT

public:
	ExpertsCallDialog(QWidget *parent = Q_NULLPTR);
	~ExpertsCallDialog();
	void init();
	void setPatient(PatientBaseInfo const& patient);
	void setDoctor(DoctorInfoResponse const& doctor);
private:
	QString string2Sex(std::string const& sex);
private:
	Ui::ExpertsCallDialog ui;
};
