#include "stable.h"
#include "ButtonDialog.h"
#include "ui_ButtonDialog.h"

ButtonDialog::ButtonDialog(QWidget *parent)
	: QDialog(parent)
	, ui(new Ui::ButtonDialog)
{
	ui->setupUi(this);
	setWindowFlags(windowFlags() | Qt::FramelessWindowHint);
}

ButtonDialog::~ButtonDialog()
{
	delete ui;
}

void ButtonDialog::setTitle(QString const& strTitle)
{
	setWindowTitle(strTitle);
	ui->titlelab->setText(strTitle);
}

void ButtonDialog::setOkText(QString const& strText)
{
	ui->okBtn->setText(strText);
}

void ButtonDialog::setCancelText(QString const& strText)
{
	ui->cancelBtn->setText(strText);
}

void ButtonDialog::setDisplayText(QString const& strText)
{
	ui->textlab->setText(strText);
}

void ButtonDialog::setCancelButtonVisiable(bool bVisiable)
{
	ui->cancelBtn->setVisible(bVisiable);
}

void ButtonDialog::setOkButtonVisiable(bool bVisiable)
{
	ui->okBtn->setVisible(bVisiable);
}
