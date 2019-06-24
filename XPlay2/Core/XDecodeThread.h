#pragma once

#include <QObject>

class XDecode;

class XDecodeThread : public QObject
{
	Q_OBJECT

public:
	XDecodeThread(QObject *parent);
	virtual ~XDecodeThread();
	void push(AVPacket* pkt);

	AVPacket* pop();

	///清理队列
	virtual void clear();

	virtual void close();
protected:
	bool				m_isExit;
	int32_t				m_nMaxQueue;
	QQueue<AVPacket*>	m_pktQueue;
	QMutex				m_mut;
	XDecode*			m_pDecode;
};
