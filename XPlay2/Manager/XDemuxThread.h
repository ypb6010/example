#pragma once

#include <QObject>


class XDemux;
class XDecode;
class XResample;
class XVideoThread;
class XAudioThread;
class XVideoWidget;
class IVideoCall;
class WorkerController;

class XDemuxThread : public QObject
{
	Q_OBJECT

public:
	XDemuxThread(QObject *parent = 0);
	virtual ~XDemuxThread();

	bool open(char const* url, IVideoCall* pCall);

	void start();

	XVideoThread* videoThread() const
	{
		return m_pVideoThread;
	}

	XAudioThread* audioThread() const
	{
		return m_pAudioThread;
	}

	int64_t getTotalMs() const;

	int64_t getPts() const;
public slots:
	void doWork();
	void close();
private:
	bool				m_isExit;		///线程退出标识
	int64_t				m_llPts;
	int64_t				m_lltotalMs;		///视频总长度
	QMutex				m_mut;			///互斥对象
	XDemux*				m_pxdem;		///解封装类
	XVideoThread*		m_pVideoThread;	///视频解码线程
	XAudioThread*		m_pAudioThread;	///音频解码线程
	WorkerController*	m_pController;	///线程控制器
};
