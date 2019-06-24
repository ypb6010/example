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

///依赖库头文件包含
#include "../Core/Codec/EncoderBase.h"
#include "../Core/Codec/DecoderBase.h"
#include "../Core/Message/CommandID.pb.h"
#include "Codec/ExpertsDecoder.h"
#include "Codec/ExpertsEncoder.h"

template <class E>class Coder_T;
typedef Coder_T<ExpertsEncoder> Encoder;
typedef Coder_T<ExpertsDecoder> Decoder;

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
#include "expertscore_global.h"
#include "Message/TogetherCall.pb.h"
#include "Message/AreaBase.pb.h"
#include "Message/MedicalHistory.pb.h"
///库文件的包含
#ifdef _DEBUG
#pragma comment(lib,"Cored.lib")
#pragma comment(lib,"EventWarpd.lib")
#else
#pragma comment(lib,"Core.lib")
#pragma comment(lib,"EventWarp.lib")
#endif // _DEBUG