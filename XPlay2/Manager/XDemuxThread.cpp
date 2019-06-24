#include "stable.h"
#include "XDemuxThread.h"
#include "Core/XDemux.h"
#include "Audio/XResample.h"
#include "Audio/XAudioPlay.h"
#include "Video/XVideoThread.h"
#include "Audio/XAudioThread.h"
#include "Video/XVideoWidget.h"
#include "Manager/WorkerController.h"

XDemuxThread::XDemuxThread(QObject *parent /*= 0*/) 
	: QObject(parent)
	, m_pController(nullptr)
	, m_isExit(false)
	, m_pxdem(nullptr)
	, m_pVideoThread(nullptr)
	, m_pAudioThread(nullptr)
	, m_llPts(0)
	, m_lltotalMs(0)
{

}

XDemuxThread::~XDemuxThread()
{
	close();
	m_pController->waitAll();
#if 0
	if (m_pAudioThread)
	{
		delete m_pAudioThread;
	}
	if (m_pVideoThread)
	{
		delete m_pVideoThread;
	}
#endif
	if (m_pController)
	{
		delete m_pController;
	}
	if(m_pxdem)
		delete m_pxdem;
	m_pxdem = nullptr;
}

bool XDemuxThread::open(char const* url, IVideoCall* pCall)
{
	if (url == 0 || url[0] == '\0')
	{
		return false;
	}
	QMutexLocker locker(&m_mut);
	if (!m_pxdem)
	{
		m_pxdem = new XDemux;
	}
	if (!m_pVideoThread)
	{
		m_pVideoThread = new XVideoThread;
	}
	if (!m_pAudioThread)
	{
		m_pAudioThread = new XAudioThread;
	}

	if (!m_pController)
	{
		m_pController = new WorkerController(this);
		//setParent(m_pController);
	}
	///解封装
	m_pxdem->clear();
	m_pxdem->close();
	if (!m_pxdem->open(url))
	{
		debug_out << "m_pxdem->open(url)：failed" << '\n';
		return false;
	}
	///视频解码线程
	m_pVideoThread->close();
	if (!m_pVideoThread->open(m_pxdem->copyVParam(), pCall, m_pxdem->videoWidth(), m_pxdem->videoHeitht()))
	{
		debug_out << "m_pVideoThread->open(m_pxdem->copyVParam(), pCall, m_pxdem->videoWidth(), m_pxdem->videoHeitht())：failed" << '\n';
		return false;
	}
	///音频解码线程
	m_pAudioThread->close();
	if (!m_pAudioThread->open(m_pxdem->copyAParam(), m_pxdem->audioSampleRate(), m_pxdem->audioChanels()))
	{
		debug_out << "m_pAudioThread->open(m_pxdem->copyAParam(), m_pxdem->audioSampleRate(), m_pxdem->audioChanels())" << '\n';
		return false;
	}
	m_lltotalMs = m_pxdem->totalMs();
	return true;
}

void XDemuxThread::start()
{
	m_pController->startAll();
}

int64_t XDemuxThread::getTotalMs() const
{
	return m_lltotalMs;
}

int64_t XDemuxThread::getPts() const
{
	return m_llPts;
}

void XDemuxThread::doWork()
{
	while (!m_isExit)
	{
		QMutexLocker locker(&m_mut);
		if (!m_pxdem)
		{
			QThread::msleep(1);
			continue;
		}

		if (m_pVideoThread && m_pAudioThread)
		{
			m_llPts = m_pAudioThread->pts();
			m_pVideoThread->setSynpts(m_pAudioThread->pts());
		}

		AVPacket* pkt = nullptr;
		if (m_pxdem)
		{
			pkt = m_pxdem->read();
		}		
		if (!pkt)
		{
			QThread::msleep(1);
			continue;
		}
		if (m_pxdem->isAudio(pkt))
		{
			m_pAudioThread->push(pkt);
		}
		else
		{
			m_pVideoThread->push(pkt);
		}

		if (!pkt)
		{
			QThread::msleep(1);
			continue;
		}
		QThread::msleep(1);
	}
	m_pVideoThread->close();
	m_pAudioThread->close();
}


void XDemuxThread::close()
{
	m_isExit = true;
}
