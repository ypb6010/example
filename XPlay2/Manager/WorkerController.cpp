#include "stable.h"
#include "WorkerController.h"
#include "XVideoWidget.h"
#include "Manager/XDemuxThread.h"
#include "audio/XAudioThread.h"
#include "video/XVideoThread.h"


WorkerController::WorkerController(XDemuxThread* pXDemuxThread)
	//: QObject(pXDemuxThread)
{
	pXDemuxThread->moveToThread(&m_demuxThread);
	connect(&m_demuxThread, &QThread::finished, this, &XDemuxThread::deleteLater, Qt::QueuedConnection);
	connect(this, &WorkerController::starManager, pXDemuxThread, &XDemuxThread::doWork);
	m_demuxThread.start();

	pXDemuxThread->videoThread()->moveToThread(&m_videoThread);
	connect(&m_videoThread, &QThread::finished, pXDemuxThread->videoThread(), &XVideoThread::deleteLater, Qt::QueuedConnection);
	connect(this, &WorkerController::startVideo, pXDemuxThread->videoThread(), &XVideoThread::doWork);
	m_videoThread.start();

	pXDemuxThread->audioThread()->moveToThread(&m_audioThread);
	connect(&m_audioThread, &QThread::finished, pXDemuxThread->audioThread(), &XAudioThread::deleteLater, Qt::QueuedConnection);
	connect(this, &WorkerController::startAudio, pXDemuxThread->audioThread(), &XAudioThread::doWork);
	m_audioThread.start();
}

WorkerController::~WorkerController()
{
	///关闭manager自动关闭音频，视频线程，自动结束不释放内存，
	///连接线程结束信号后deleteLater后会释放内存
	//m_pXDemuxThread->close();

	//if (m_demuxThread.isRunning())
	//{
	//	m_demuxThread.quit();
	//	m_demuxThread.wait();
	//}
	//if (m_videoThread.isRunning())
	//{
	//	m_videoThread.quit();
	//	m_videoThread.wait();
	//}
	//if (m_audioThread.isRunning())
	//{
	//	m_audioThread.quit();
	//	m_audioThread.wait();
	//}
}


void WorkerController::emitOperate()
{
	emit startVideo();
}

void WorkerController::emitStartAudio()
{
	emit startAudio();
}

void WorkerController::emitStartVideo()
{
	emit startVideo();
}

void WorkerController::startAll()
{
	emit starManager();
	emit startVideo();
	emit startAudio();
}

void WorkerController::waitAll()
{
	m_demuxThread.quit();
	m_demuxThread.wait();

	m_videoThread.quit();
	m_videoThread.wait();
	
	m_audioThread.quit();
	m_audioThread.wait();	
}

