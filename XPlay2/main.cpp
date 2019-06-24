#include "stable.h"
#include "audio/XResample.h"
#include "XPlay2.h"

#include "Manager/XDemuxThread.h"

int main(int argc, char *argv[])
{
	///³õÊ¼»¯ÏÔÊ¾	
	QApplication a(argc, argv);
	XPlay2 w;
	w.show();

	
	//char const* url = "sss.mp4";
	//char const* url = "rtmp://58.200.131.2:1935/livetv/hunantv";
	//char const* url = "rtmp://live.hkstv.hk.lxdns.com/live/hks1";
	char const* url = "sss.mp4";
	if (!pWorkManager)
	{
		pWorkManager = new XDemuxThread;
	}
	pWorkManager->open(url, w.getIVedioCall());
	pWorkManager->start();

	int nValue = a.exec();
	return nValue;
}