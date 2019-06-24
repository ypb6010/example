#pragma once

///C头文件包含区
extern "C" {
#include "libavformat/avformat.h"
#include "libavcodec/avcodec.h"
#include "libswscale/swscale.h"
#include "libswresample/swresample.h"
}
#pragma comment(lib,"avformat.lib")
#pragma comment(lib,"avutil.lib")
#pragma comment(lib,"avcodec.lib")
#pragma comment(lib,"swscale.lib")
#pragma comment(lib,"swresample.lib")

///C++头文件包含区
#include <string>
#include <sstream>
#include <queue>
#include <list>
#include <vector>

#ifdef _DEBUG
#ifdef NO_QDEBUG
#include <iostream>
#define debug_out std::cout
using std::cout;
using std::endl;
#else
#include <QDebug>
#define debug_out qDebug()
#endif //NO_QDEBUG
#else 
static std::string logString;
static std::stringstream logStream(logString);
#define debug_out /##/
//#define debug_out logStream
#endif //_DEBUG

///依赖库头文件包含
#include <QDebug>
#include <QMutex>
#include <QMutexLocker>
#include <QThread>
#include <QtWidgets/QApplication>
#include <QAudioFormat>
#include <QAudioOutput>
#include <QQueue>
#include <QFileDialog>
#include <QMessageBox>
#include <QTimer>
///第三方库头文件包含

///本工程头文件包含
#if 0
#include "Core/XDemux.h"
#include "XPlay2.h"
#include "Core/XDecode.h"
#include "audio/XResample.h"
#include "video/WorkerManageer.h"
#include "video/WorkerController.h"
#include "audio/XAudioPlay.h"
#include "audio/CXAudioPlay.h"
#include "audio/XAudioThread.h"
#endif

