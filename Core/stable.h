#pragma once
#define NO_QDEBUG
#define USE_CODEC
#define LOCAL_HEARTBEAT 1024
#define HEART_BEAT		1024
///C头文件包含区
extern "C" {

}

///C++头文件包含区
#include <string>
#include <sstream>
#include <queue>
#include <list>
#include <vector>
#include <fstream>

///依赖库头文件包含
#include <QMutex>
#include <QMutexLocker>
#include <QThread>
#include <QtWidgets/QApplication>
#include <QQueue>
#include <QTimer>
///第三方库头文件包含
#include "openssl/rsa.h"    
#include "openssl/pem.h" 
#include "openssl/err.h"

///本地库头文件包含（项目外全局）
#include "Codec/DecoderBase.h"
#include "Codec/EncoderBase.h"
template <class E>class Coder_T;
typedef Coder_T<class EncoderBase> Encoder;
typedef Coder_T<class DecoderBase> Decoder;
#include <boost/algorithm/string.hpp>
#include "global_define.h"
#include "EventDefine.h"
#include "Message/UserLogin.pb.h"
#include "Message/CommandID.pb.h"
#include "Message/Version.pb.h"
///本地库头文件包含（项目外局部）
#include "NetWork.h"
#include "EventManger.h"

#ifdef _DEBUG
#include "boost/locale.hpp"
#pragma comment(lib,"NetWorkd.lib")
#pragma comment(lib,"EventWarpd.lib")
#pragma comment(lib,"libcrypto.lib")
#else
#pragma comment(lib,"EventWarp.lib")
#pragma comment(lib,"NetWork.lib")
#pragma comment(lib,"libcrypto.lib")
#pragma comment(lib,"libssl.lib")
#endif // _DEBUG
