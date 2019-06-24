#pragma once

class XResample
{
public:
	XResample();
	virtual ~XResample();
	///打开一个要重采样的样本
	bool open(AVCodecParameters* para,bool isClear = false);

	///关闭重采样
	void close();

	///返回重采样的大小,无论成功与否都要释放indata空间
	int32_t resample(AVFrame* indata, uint8_t* data);

	void setOutFormat(AVSampleFormat format);
private:
	AVSampleFormat m_format;
	QMutex m_mut;
	SwrContext* m_pActx;
};
