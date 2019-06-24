#pragma once

class IVideoCall
{
public:
	virtual void init(int nWidth, int nHeight) = 0;
	virtual void paintVideo(AVFrame* frame) = 0;

};
