#include "stable.h"
#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.callNextBtn->setVisible(false);
	ui.videoBtn->setVisible(false);
	ui.completeBtn->setVisible(false);
	ui.pauseBtn->setVisible(false);
}

MainWindow::~MainWindow()
{
}
