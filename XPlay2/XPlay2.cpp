#include "stable.h"
#include "XPlay2.h"
#include "Manager/XDemuxThread.h"

XDemuxThread* pWorkManager = nullptr;

XPlay2::XPlay2(QWidget *parent)
	: QWidget(parent)
	, m_ptimer(new QTimer(this))
{
	ui.setupUi(this);
	connect(ui.pushButton, &QPushButton::clicked, this, &XPlay2::openFile);
	connect(m_ptimer, &QTimer::timeout, this, &XPlay2::on_timer);
	m_ptimer->start(40);
}

XPlay2::~XPlay2()
{
	delete pWorkManager;
}

IVideoCall* XPlay2::getIVedioCall() const
{
	return ui.openGLWidget;
}

void XPlay2::mouseDoubleClickEvent(QMouseEvent *event)
{
	Q_UNUSED(event);
	if (isFullScreen())
	{
		showNormal();
	}
	else
	{
		showFullScreen();
	}
}

void XPlay2::openFile()
{
	if (!pWorkManager)
	{
		pWorkManager = new XDemuxThread;
	}
	QString name = QFileDialog::getOpenFileName(this, QString::fromLocal8Bit("选择视频文件"));
	if (name.isEmpty())return;
	this->setWindowTitle(name);
	if (!pWorkManager->open(name.toLocal8Bit(), ui.openGLWidget))
	{
		QMessageBox::information(0, "error", "open file failed!");
		return;
	}
	if (pWorkManager)
	{
		pWorkManager->start();
	}
}

void XPlay2::on_timer()
{
	int64_t nTotalMs = pWorkManager->getTotalMs();
	if (nTotalMs > 0)
	{
		double dPos = (double)pWorkManager->getPts() / (double)nTotalMs;
		ui.horizontalSlider->setValue(ui.horizontalSlider->maximum() * dPos);
	}
}
