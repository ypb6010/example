#pragma once

#include <QDialog>


namespace Ui
{
	class AppendHistoryDialog;
};

class MEDICALWIDGET_EXPORT AppendHistoryDialog : public QDialog
{
	Q_OBJECT

public:
	AppendHistoryDialog(QWidget *parent = Q_NULLPTR);
	~AppendHistoryDialog();
	QString plianText() const;
private:
	Ui::AppendHistoryDialog* ui;
};
