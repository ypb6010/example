#pragma once
///宏定义区
#define USE_CODEC
#define NO_QDEBUG
///C头文件包含区
extern "C" {
}

///C++头文件包含区
#include <string>
#include <sstream>
#include <queue>
#include <list>
#include <vector>
#include <tuple>
#include <fstream>

///依赖库头文件包含
#include <QProcess>

#include "Codec/AssistDecoder.h"
#include "Codec/AssistEncoder.h"

template <class E>class Coder_T;
typedef Coder_T<class AssistEncoder> Encoder;
typedef Coder_T<class AssistDecoder> Decoder;
///第三方库头文件包含
#include "global_define.h"

///本工程头文件包含

#include "Core.h"
#include "NetWork.h"
#include "AppManager.h"
#include "EventWarp.h"
#include "EventManger.h"
#include "EventDefine.h"
#include "AppManager.h"
#include "../Core/WindowInterface.h"
#include "../Core/Message/CommandID.pb.h"
#include "Message/AreaBase.pb.h"
#include "Message/TogetherCall.pb.h"
#include "Message/MedicalHistory.pb.h"



///库文件的包含
#ifdef _DEBUG
#pragma comment(lib,"Cored.lib")
#pragma comment(lib,"EventWarpd.lib")
#else
#pragma comment(lib,"Core.lib")
#pragma comment(lib,"EventWarp.lib")
#endif // _DEBUG