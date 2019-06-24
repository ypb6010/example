#include "stable.h"
#include "XVideoThread.h"
#include "XVideoWidget.h"
#include "Core/XDecode.h"

XVideoThread::XVideoThread(QObject *parent)
	: XDecodeThread(parent)
{

}

XVideoThread::~XVideoThread()
{

}

///代理接口
bool XVideoThread::open(AVCodecParameters* param, IVideoCall* pCallInterface, int32_t nWidth, int32_t nHeight)
{
	if (!param)
	{
		return false;
	}
	clear();
	m_isExit = false;
	do 
	{
		QMutexLocker locker(&m_vmut);
		m_pCallVideo = pCallInterface;
		m_llsynpts = 0;
		if (pCallInterface)
		{
			pCallInterface->init(nWidth, nHeight);
		}
	} while (false);
	if (!m_pDecode)
	{
		m_pDecode = new XDecode;
	}
	return m_pDecode->open(param);
}


void XVideoThread::setSynpts(int64_t pts)
{
	m_llsynpts = pts;
}

void XVideoThread::doWork()
{
	while (!m_isExit)
	{
		QMutexLocker locker(&m_vmut);

		if (m_llsynpts > 0 && m_llsynpts < m_pDecode->pts())
		{
			QThread::msleep(1);
			continue;
		}
		bool res = false;
		if (m_pDecode)
		{
			AVPacket* pkt = pop();
			res = m_pDecode->send(pkt);

		}
		if (!res)
		{
			QThread::msleep(1);
			continue;
		}
		///一次的发送可能对应多个recv
		while (!m_isExit)
		{
			AVFrame* frame = m_pDecode->recv();
			if (!frame)
			{
				break;
			}
			///显示视频
			if (m_pCallVideo)
			{
				m_pCallVideo->paintVideo(frame);
			}
		}
	}
}
