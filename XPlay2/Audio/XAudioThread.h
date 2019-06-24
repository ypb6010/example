#pragma once
#include "XDecodeThread.h"

class XDecode;
class XAudioPlay;
class XResample;

class XAudioThread : public XDecodeThread
{
	Q_OBJECT

public:

	XAudioThread(QObject *parent = 0);
	virtual ~XAudioThread();

	bool open(AVCodecParameters* para, int32_t sampleRate, int32_t chanels);


	int64_t pts();
	///Òì²½Ö´ÐÐº¯Êý
public slots:
	void doWork();

private:
	QMutex				m_amut;
	int64_t				m_llpts;
	XAudioPlay*			m_pAp;
	XResample*			m_pRes;
};
