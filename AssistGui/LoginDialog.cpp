#include "stable.h"
#include "LoginDialog.h"
#include "LoginTitleBar.h"
#include "Core.h"


LoginDialog::LoginDialog(Core* core, QWidget *parent)
	: QDialog(parent)
	, WindowInterface(core)
{
	ui.setupUi(this);
	titleBar = new LoginTitleBar(this);
	QVBoxLayout* vRoot = new QVBoxLayout(this);
	setWindowFlags(windowFlags() | Qt::FramelessWindowHint);
	setWindowTitle(QStringLiteral("登录助诊端"));
	vRoot->insertWidget(0, titleBar,1);
	installEventFilter(titleBar);
	connect(ui.loginPtn, &QPushButton::clicked, this, &LoginDialog::on_loginptn);
}

LoginDialog::~LoginDialog()
{
}

void LoginDialog::on_loginptn()
{
	auto userName = ui.userLe->text();
	auto password = ui.passLe->text();
	///user_type=1 专家，0是助诊
	requestLogin(0, QString2String(userName), QString2String(password), pubFile);
}

void LoginDialog::receiptLogin(std::string const strMsg)
{
	if (!strMsg.empty())
	{
		if (strMsg == "pass accpet")
		{
			QMetaObject::invokeMethod(this, &QDialog::accept);
			return;
		}
		ui.errLab->setText(String2QString(strMsg));
		return;
	}
}

