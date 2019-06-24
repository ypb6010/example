#pragma once

#include <QObject>

class XDemuxThread;
class XAudioThread;
class XVideoWidget;

class WorkerController : public QObject
{
	Q_OBJECT
private:
	QThread m_demuxThread;
	QThread m_videoThread;
	QThread m_audioThread;
	XDemuxThread* m_pXDemuxThread;
public:
	WorkerController(XDemuxThread* pXDemuxThread);
	virtual ~WorkerController();

	void emitOperate();

	void emitStartAudio();

	void emitStartVideo();

	void startAll();

	void waitAll();
signals:
	void starManager();
	void startVideo();
	void startAudio();
};
