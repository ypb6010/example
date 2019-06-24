#pragma once

#include <QDialog>

namespace Ui {
	class ButtonDialog;
}

class MEDICALWIDGET_EXPORT ButtonDialog : public QDialog
{
	Q_OBJECT

public:
	ButtonDialog(QWidget *parent = Q_NULLPTR);
	~ButtonDialog();
	void setTitle(QString const& strTitle);
	void setOkText(QString const& strText);
	void setCancelText(QString const& strText);
	void setDisplayText(QString const& strText);
	void setCancelButtonVisiable(bool bVisiable);
	void setOkButtonVisiable(bool bVisiable);
private:
	Ui::ButtonDialog* ui;
};
