#include "stable.h"
#include "XAudioThread.h"
#include "XAudioPlay.h"
#include "XResample.h"
#include "Core/XDecode.h"




XAudioThread::XAudioThread(QObject *parent)
	: XDecodeThread(parent)
	, m_pAp(XAudioPlay::instance())
	, m_pRes(new XResample)
{

}

XAudioThread::~XAudioThread()
{
	m_isExit = true;
	if (m_pRes)
	{
		delete m_pRes;
	}
}

bool XAudioThread::open(AVCodecParameters* para,int32_t sampleRate, int32_t chanels)
{
	if (!para)
	{
		return false;
	}
	clear();
	m_isExit = false;
	QMutexLocker locker(&m_amut);
	bool isSucessfull = true;
	m_llpts = 0;

	if (!m_pRes->open(para,false))
	{
		isSucessfull = false;
		debug_out << "m_pRes->open(para)" << '\n';
	}

	m_pAp->setSampleRate(sampleRate);
	m_pAp->setChanels(chanels);

	if (!m_pAp->open())
	{
		isSucessfull = false;
		debug_out << "m_pAp->open() failed" << '\n';
	}
	if (!m_pDecode)
	{
		m_pDecode = new XDecode;
	}
	if (!m_pDecode->open(para))
	{
		isSucessfull = false;
		debug_out << "m_pDecode->open(para) failed" << '\n';
	}
	debug_out << "XAudioThread::open finsh： " << isSucessfull ? "true" : "false";
	debug_out << '\n';
	return isSucessfull;
}

int64_t XAudioThread::pts()
{
	return m_llpts;
}

void XAudioThread::doWork()
{
	uint8_t* pcm = nullptr;
	while (!m_isExit)
	{
		AVPacket* pkt = nullptr;
		QMutexLocker locker(&m_amut);

	
		pkt = pop();		
		bool res = m_pDecode->send(pkt);
		if (!res)
		{
			QThread::msleep(1);
			continue;
		}
		///一次recv可能对应多次的send
		while (!m_isExit)
		{
			if (!pcm)
			{
				pcm = new uint8_t[1024 * 1024 * 10];
			}
			AVFrame* frame = nullptr;
			if (m_pDecode)
			{
				frame = m_pDecode->recv();
			}
			if (!frame)
			{
				break;
			}
			///减去缓冲中未播放的时间
			m_llpts = m_pDecode->pts() - m_pAp->getNoPlayMs();

			//debug_out << "XAudioThread::doWork：pts:" << m_llPts << '\n';
			///重采样
			int32_t size = m_pRes->resample(frame, pcm);		
			if (size < 0)
			{
				av_frame_free(&frame);
				QThread::msleep(1);
				continue;
			}
			///进行音频播放
			while (!m_isExit)
			{
				///缓冲没有播放完毕，空间不够
				if (m_pAp->getFree() < size)
				{
					QThread::msleep(1);
					continue;
				}
				if (m_pAp->write(pcm, size))
				{
					break;
				}
			}
		}
	}
	if (pcm)
	{
		delete[] pcm;
		pcm = nullptr;
	}
}
