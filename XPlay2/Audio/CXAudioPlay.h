#pragma once

#include "audio/XAudioPlay.h"

class CXAudioPlay :public XAudioPlay
{
public:

	~CXAudioPlay();


	virtual bool open() override;

	virtual void close() override;

	virtual bool write(uint8_t* data, int32_t datasize) override;

	virtual int32_t getFree() const override;

	virtual int64_t getNoPlayMs() override;

protected:
	CXAudioPlay();
	static void* operator new(size_t size)
	{
		return ::operator new(size);
	}

	static void operator delete(void* p)
	{
		::operator delete(p);
	}
private:
	QAudioOutput* output;
	QIODevice* io;
	QMutex m_mut;
	friend XAudioPlay;
};
