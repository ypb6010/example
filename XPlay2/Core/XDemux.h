#pragma once
struct AVRational;
struct AVFormatContext;
struct AVPacket;
struct AVCodecParameters;

class XDemux
{
///静态公有区
public:
	static double r2d(AVRational r);


	///公有接口区
public:
	XDemux();
	virtual ~XDemux();

	bool isAudio(AVPacket* pkt);

	/// 打开流媒体文件流，文件或者网络rtmp rtsp http
	virtual bool open(const std::string url);

	///空间需要调用者释放，释放AVPacket对象空间，和数据空间 av_packet_free
	virtual AVPacket* read();

	///对音视频进行移动读取的位置,pos为百分比值0.0-1.0之间
	virtual bool seek(double pos);

	virtual void clear();

	virtual void close();

	///获取视频参数,返回的空间需要清理掉，avcodec_parameters_free()
	AVCodecParameters* copyVParam();

	///获取音频参数,返回的空间需要清理掉，avcodec_parameters_free()
	AVCodecParameters* copyAParam();

	///获取或设置总音视频长度（毫秒）
	int64_t totalMs() const { return m_nTotalMs; }

	void setTotalMs(int val) { m_nTotalMs = val; }

	int32_t videoWidth() const;

	int32_t videoHeitht() const;
	
	int32_t audioSampleRate() const;

	int32_t audioChanels() const;
protected:
	///解封装上下文
	AVFormatContext* m_pIC;

	///音视频流
	int m_nVideoStream;
	int m_nAudioStream;

private:
	///视频的宽高
	int32_t m_nWidth;
	int32_t m_nHeight;

	///音频的采样率样本和大小
	int32_t m_nSampleRate;

	int32_t m_nChanels;

	///媒体总时长(毫秒)
	int32_t m_nTotalMs;
	///线程锁
	QMutex m_mut;
};