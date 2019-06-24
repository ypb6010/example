#pragma once

#include "Core/XDecodeThread.h"



class XVideoWidget;
class IVideoCall;

class XVideoThread : public XDecodeThread
{
	Q_OBJECT

public:
	XVideoThread(QObject *parent = 0);
	~XVideoThread();

	bool open(AVCodecParameters* param,IVideoCall* pCallInterface, int32_t nWidth, int32_t nHeight);

	void setSynpts(int64_t pts);
public slots:
	void doWork();
private:	
	QMutex				m_vmut;
	int64_t				m_llsynpts;
	IVideoCall*			m_pCallVideo;
};
