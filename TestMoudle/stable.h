#pragma once
///宏定义区
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
#include <iostream>
#include <fstream>

///依赖库头文件包含
#include <QMutex>
#include <QMutexLocker>
#include <QThread>

///第三方库头文件包含
#include <boost/assert.hpp>
#include <boost/core/ref.hpp>
#include <boost/array.hpp>
#include <boost/smart_ptr/make_shared.hpp>
#include <boost/make_shared.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>
#include <boost/thread.hpp>
#include <boost/thread/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/thread/lock_factories.hpp>
#include <boost/thread/scoped_thread.hpp>
#include <boost/format.hpp>
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/asio.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/steady_timer.hpp>
#include <boost/smart_ptr.hpp>
#include <boost/smart_ptr/make_shared.hpp>
#include <boost/function.hpp>
#include <boost/bimap.hpp>
#include <boost/locale.hpp>
#include <boost/lexical_cast.hpp>
#include <sstream>
#include <iostream>

#include <openssl/err.h>
///本工程头文件包含																																																																		
#include "global_define.h"
#include "EventDefine.h"

#include "Core.h"
#include "AppManager.h"
#include "../AssistCore/AssistCore.h"
#include "../AssistCore/AssistManager.h"
#include "NetWork.h"
#pragma comment(lib,"libcrypto.lib")
#pragma comment(lib,"libssl.lib")