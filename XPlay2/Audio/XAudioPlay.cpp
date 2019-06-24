#include "stable.h"
#include "CXAudioPlay.h"
#include "XAudioPlay.h"

XAudioPlay::XAudioPlay()
	:m_nSampleRate(44100)
	, m_nSampleSize(16)
	, m_nChanels(2)
{
}

XAudioPlay::~XAudioPlay()
{
}

XAudioPlay* XAudioPlay::instance()
{
	static CXAudioPlay p;
	return &p;
}

void XAudioPlay::setChanels(int32_t chanels)
{
	m_nChanels = chanels;
}

void XAudioPlay::setSampleRate(int32_t nSampleRate)
{
	m_nSampleRate = nSampleRate;
}

void XAudioPlay::setSampleSize(int32_t nSampleSize)
{
	m_nSampleSize = nSampleSize;
}

