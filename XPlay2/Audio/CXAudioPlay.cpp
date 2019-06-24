#include "stable.h"

#include "CXAudioPlay.h"

CXAudioPlay::CXAudioPlay()
	:output(nullptr)
{
}

CXAudioPlay::~CXAudioPlay()
{
	if (output)
	{
		delete output;
		output = nullptr;
	}
}

bool CXAudioPlay::open()
{
	close();
	QAudioFormat fmt;
	fmt.setSampleRate(m_nSampleRate);
	fmt.setSampleSize(m_nSampleSize);
	fmt.setChannelCount(2);
	fmt.setCodec("audio/pcm");
	fmt.setByteOrder(QAudioFormat::LittleEndian);
	fmt.setSampleType(QAudioFormat::UnSignedInt);
	QMutexLocker locker(&m_mut);
	output = new QAudioOutput(fmt);
	io = output->start();
	if (io)
	{
		return true;
	}
	return false;
}

void CXAudioPlay::close()
{
	QMutexLocker locker(&m_mut);
	if (io)
	{
		io = nullptr;
	}
	if (output)
	{
		output->stop();
		delete output;
		output = nullptr;
	}
}

bool CXAudioPlay::write(uint8_t* data, int32_t datasize)
{
	if (!data || datasize <= 0)
	{
		return false;
	}
	QMutexLocker locker(&m_mut);
	if (!output || !io)
	{
		return false;
	}
	int nSize = io->write(reinterpret_cast<char const*>(data), datasize);
	if (nSize != datasize)
	{
		return false;
	}
	return true; 
}

int32_t CXAudioPlay::getFree() const
{
	QMutexLocker locker(const_cast<QMutex*>(&m_mut));
	if (!output)
	{
		return 0;
	}
	int32_t nFree = output->bytesFree();
	return nFree;
}

int64_t CXAudioPlay::getNoPlayMs()
{
	if (!output)
	{
		return 0;
	}
	int64_t pts = 0;
	QMutexLocker locker(&m_mut);
	double dSize = output->bufferSize() - output->bytesFree();
	///1S音频数据大小
	double dSecSize = m_nSampleRate * (m_nSampleSize / 8) * m_nChanels;
	if (dSecSize <= 0)
	{
		pts = 0;
	}
	else
	{
		pts = (dSize / dSecSize) * 1000;
	}
	return pts;
}
