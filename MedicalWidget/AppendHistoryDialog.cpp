#include "stable.h"
#include "AppendHistoryDialog.h"
#include "ui_AppendHistoryDialog.h"

AppendHistoryDialog::AppendHistoryDialog(QWidget *parent)
	: QDialog(parent)
	, ui(new Ui::AppendHistoryDialog)
{
	ui->setupUi(this);
	setWindowFlags(windowFlags() | Qt::FramelessWindowHint);
	connect(this,&AppendHistoryDialog::windowTitleChanged,ui->titleText,&QLabel::setText);
}

AppendHistoryDialog::~AppendHistoryDialog()
{
	delete ui;
}

QString AppendHistoryDialog::plianText() const
{
	return ui->maskEdit->toPlainText();
}
