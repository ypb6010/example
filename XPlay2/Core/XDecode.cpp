#include "stable.h"
#include "XDecode.h"


bool XDecode::open(AVCodecParameters * para)
{
	close();
	if (!para)
	{
		return false;
	}
	AVCodec* codec = avcodec_find_decoder(para->codec_id);

	if (!codec)
	{
		avcodec_parameters_free(&para);
		debug_out << "没有找到解码器" << para->codec_id << endl;
		return false;
	}
	debug_out << "找到解码器" << para->codec_id << endl;
	QMutexLocker locker(&m_mut);
	///创建解码器 视频和音频
	m_codec = avcodec_alloc_context3(codec);
	avcodec_parameters_to_context(m_codec, para);
	debug_out << m_codec->thread_count << '\n';
	m_codec->thread_count = 2;
	int re = avcodec_open2(m_codec, 0, 0);

	if (re != 0)
	{
		avcodec_free_context(&m_codec);
		avcodec_parameters_free(&para);
		char buf[1024] = { 0 };
		av_strerror(re, buf, sizeof(buf) - 1);
		debug_out << buf << endl;
		return false;
	}
	avcodec_parameters_free(&para);
	return true;
}

bool XDecode::send(AVPacket* pkt)
{
	QMutexLocker locker(&m_mut);
	if (!pkt || pkt->size <= 0 || !pkt->data)
	{
		av_packet_free(&pkt);
		return false;
	}
	if (!m_codec)
	{
		av_packet_free(&pkt);
		return false;
	}
	int re = avcodec_send_packet(m_codec, pkt);
	av_packet_free(&pkt);
	if (re != 0)
	{
		return false;
	}
	return true;
}

AVFrame* XDecode::recv()
{
	if (!m_codec)
	{
		return nullptr;
	}
	QMutexLocker locker(&m_mut);
	AVFrame* frame = av_frame_alloc();
	int re = avcodec_receive_frame(m_codec, frame);
	if (re != 0)
	{
		av_frame_free(&frame);
		return nullptr;
	}
	//debug_out << "[" << frame->linesize[0] << "]" << '\n';
	m_llPts = frame->pts;
	return frame;
}

void XDecode::close()
{
	QMutexLocker locker(&m_mut);
	if (m_codec)
	{
		avcodec_close(m_codec);
		avcodec_free_context(&m_codec);
		m_llPts = 0;
	}
}

void XDecode::clear()
{
	QMutexLocker locker(&m_mut);
	///清理解码缓冲
	if (m_codec)
	{
		avcodec_flush_buffers(m_codec);
	}
}

int64_t XDecode::pts() const
{
	return m_llPts;
}

XDecode::XDecode()
	: m_isAudio(false)
	, m_codec(0)
	, m_llPts(0)
{
}


XDecode::~XDecode()
{
	QMutexLocker locker(&m_mut);
	if (m_codec)
	{
		avcodec_flush_buffers(m_codec);
		avcodec_close(m_codec);
		avcodec_free_context(&m_codec);
		m_llPts = 0;
	}
}

void XDecode::XFreeAvpacket(AVPacket** pkt)
{
	if (!pkt || !*pkt)
	{
		return;
	}
	av_packet_free(pkt);
}
