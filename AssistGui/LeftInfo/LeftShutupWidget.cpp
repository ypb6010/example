#include "stable.h"
#include "LeftShutupWidget.h"

LeftShutupWidget::LeftShutupWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setWindowFlags(windowFlags() | Qt::FramelessWindowHint);
}

LeftShutupWidget::~LeftShutupWidget()
{
}
