#include "stable.h"
#include "XDecodeThread.h"
#include "Core/XDecode.h"

XDecodeThread::XDecodeThread(QObject *parent)
	: QObject(parent)
	, m_isExit(false)
	, m_pDecode(new XDecode)
	, m_nMaxQueue(200)
{
}

XDecodeThread::~XDecodeThread()
{
	m_isExit = true;
	QMutexLocker locker(&m_mut);
		delete m_pDecode;
	m_pDecode = nullptr;
}



void XDecodeThread::push(AVPacket* pkt)
{
	if (!pkt)
	{
		return;
	}
	while (!m_isExit)
	{
		QMutexLocker locker(&m_mut);
		if (m_pktQueue.size() < m_nMaxQueue)
		{
			m_pktQueue.enqueue(pkt);
			break;
		}
		QThread::msleep(1);
	}
}

AVPacket* XDecodeThread::pop()
{
	QMutexLocker locker(&m_mut);
	if (m_pktQueue.isEmpty())
	{
		return nullptr;
	}
	AVPacket* pkt = m_pktQueue.dequeue();
	return pkt;
}

void XDecodeThread::clear()
{
	QMutexLocker locker(&m_mut);
	if (m_pDecode)
	{
		m_pDecode->clear();
	}
	while (!m_pktQueue.isEmpty())
	{
		AVPacket* pkt = m_pktQueue.dequeue();
		XDecode::XFreeAvpacket(&pkt);
	}
}

void XDecodeThread::close()
{
	//clear();
	m_isExit = true;
	//m_pDecode->close();
	//QMutexLocker locker(&m_mut);
	//if(m_pDecode)
	//	delete m_pDecode;
	//m_pDecode = nullptr;
}
