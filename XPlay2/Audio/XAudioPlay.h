#pragma once

class XAudioPlay
{
public:
	XAudioPlay();
	virtual ~XAudioPlay();
	static XAudioPlay* instance();

	virtual bool open() = 0;

	virtual void close() = 0;

	virtual bool write(uint8_t* data,int32_t datasize) = 0;

	virtual int32_t getFree() const = 0;

	virtual int64_t getNoPlayMs() = 0;

	void setChanels(int32_t chanels);

	void setSampleRate(int32_t nSampleRate);

	void setSampleSize(int32_t nSampleSize);
protected:
	int32_t m_nSampleRate;
	int32_t m_nSampleSize;
	int32_t m_nChanels;

};
