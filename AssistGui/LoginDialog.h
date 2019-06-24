#pragma once

#include <QDialog>
#include "ui_LoginDialog.h"
#include "../Core/WindowInterface.h"

class LoginTitleBar;
extern std::string const pubFile;

class LoginDialog : public QDialog ,public WindowInterface
{
	Q_OBJECT

public:
	LoginDialog(Core* pCore, QWidget *parent = Q_NULLPTR);
	~LoginDialog();
	void on_loginptn();
	   
protected:
	virtual void receiptLogin(std::string const strMsg) override;

private:
	Ui::LoginDialog ui;
	LoginTitleBar* titleBar;
};
