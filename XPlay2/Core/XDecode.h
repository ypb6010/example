#pragma once
class XDecode
{
public:
	///打开解码器，并释放AVCodecParameters* para;
	virtual bool open(AVCodecParameters* para);

	///发送到解码线程，并且要实时释放pkt的空间
	virtual bool send(AVPacket* pkt);

	///获取解码后的数据，一次的send可能对应多个recv,获取最后缓冲时候要发送NULL获取最后缓冲
	///每次复制一份，由调用者去释放av_frame_free
	virtual AVFrame* recv();

	///关闭解码
	virtual void close();

	///清理解码缓存
	virtual void clear();

	int64_t pts() const;
	
	XDecode();
	virtual ~XDecode();

	static void XFreeAvpacket(AVPacket** pkt);
private:
	bool m_isAudio;
	int32_t  m_llPts;				///当前解码的pts
	AVCodecContext* m_codec;
	QMutex m_mut;
};

