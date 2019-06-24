#include "stable.h"
#include "AppManager.h"
#include "Core.h"

AppManager::~AppManager()
{
	m_isRun = false;
	m_isDispatchExit = true;
	m_isDecodeExit = true;
	if (m_doDispach && m_doDispach->joinable())
	{
		m_doDispach->join();
	}
	if (m_decodeWork && m_decodeWork->joinable())
	{
		m_decodeWork->join();
	}
}

AppManager::AppManager()
	: m_isRun(false)
	, m_isDispatchExit(false)
	, m_isDecodeExit(false)
	, m_currentType(loginNet)
{

}

void AppManager::start()
{
	if (!m_isRun)
	{
		if (!m_eventManager)
		{
			m_eventManager = EventWarp::makeEventWarp();
		}
		if (!m_netLogin)
		{
			m_netLogin = NetWork::make_network();
		}
		if (!m_netArea)
		{
			m_netArea = NetWork::make_network();
		}
		if (!m_doDispach)
		{			
			m_doDispach = boost::make_shared<thread_type>(boost::bind(&this_type::dispachMsg, this));
		}
		if (!m_decodeWork)
		{
			m_decodeWork = boost::make_shared<thread_type>(boost::bind(&this_type::dispatchDecode, this));
		}
		initOthers();
		m_isRun = true;
	}
}

void AppManager::stop()
{
	m_isRun = false;
	m_isDecodeExit = true;
	m_isDispatchExit = true;
	releasePtr(m_doDispach);
	releasePtr(m_decodeWork);
	releasePtr(m_netLogin);
	releasePtr(m_eventManager);
}

net_ptr const AppManager::loginNetptr() const
{
	return m_netLogin;
}

net_ptr const AppManager::areaNetptr() const
{
	return m_netArea;
}

msg_ptr const AppManager::msgInterface() const
{
	return m_eventManager ? m_eventManager->msgInterface(): msg_ptr();
}

net_message_ptr const AppManager::netQueueInterface() const
{
	return m_eventManager ? m_eventManager->netQueueInterface() : net_message_ptr();
}

local_message_ptr const AppManager::localQueueInterface() const
{
	return m_eventManager ? m_eventManager->localEncodeInterface() : local_message_ptr();
}

event_ptr const AppManager::eventManager() const
{
	return m_eventManager ? m_eventManager : event_ptr();
}

void AppManager::registerDecoder(int32_t decNum, decoder_function fun)
{
	auto&& it = m_decFunMap.find(decNum);
	if (it == m_decFunMap.end())
	{
		m_decFunMap.insert(std::make_pair(decNum, fun));
	}
	else
	{
		debug_out << "解码号已经被注册：" << decNum << std::endl;
	}
}

event_handler AppManager::decode(int32_t decNum, std::string const&& strBody) const
{
	if (m_localPriKey.empty())
	{
		debug_out << "私钥目前没有被赋值,数据无法解密" << std::endl;
		return event_handler();
	}
	std::string const && clearBody = Core::rsa_pri_decrypt(strBody, m_localPriKey);
	if (clearBody.empty())
	{
		debug_out << "解密报文体失败" << std::endl;
		return event_handler();
	}
	auto&& it = m_decFunMap.find(decNum);
	if (it != m_decFunMap.cend())
	{
		return boost::bind(it->second, _1)(boost::cref(clearBody));
	}
	else
	{
		debug_out << "没有找到对应解码函数：" << decNum << std::endl;
		return event_handler();
	}
}

event_handler AppManager::decode(int32_t decNum, std::string const& strBody) const
{
	return decode(decNum, std::move(strBody));
}

void AppManager::setClientprikey(std::string const& prikey)
{
	if (m_localPriKey.empty())
	{
		m_localPriKey = prikey;
	}
	else
	{
		debug_out << "客户端私钥已经被赋值" << std::endl;
	}
}

void AppManager::releaseLogin()
{
	m_netLogin->stop();
	m_netLogin.reset();
	m_currentType = areaNet;
}

AppManager::connect_type AppManager::currentNetWork() const
{
	return m_currentType;
}

void AppManager::initOthers()
{
	if (!m_decoder)
	{
		m_decoder = boost::make_shared<Decoder>();
	}
	REG_LOGIN_EVENT(message::LC_COMMAND_LOGIN_RESPONSE);
	REG_LOGIN_EVENT(message::LC_COMMAND_VERSION_RESPONSE);
	REG_LOGIN_EVENT(message::LC_COMMAND_NONE);


	REG_DEC(message::LC_COMMAND_NONE, decode_heatbeat);
	REG_DEC(message::LC_COMMAND_VERSION_RESPONSE, decode_version);
	REG_DEC(message::LC_COMMAND_LOGIN_RESPONSE, decode_login);
}

void AppManager::registerLoginEvent(int32_t const& nCommand, net_cb_t const& fun)
{
	m_netLogin->addCbSrvToClient(nCommand, fun);
}

void AppManager::registerAreaEvent(int32_t const& nCommand, net_cb_t const& fun)
{
	m_netArea->addCbSrvToClient(nCommand, fun);
}

void AppManager::dispatchDecode()
{
	while (!m_isDecodeExit)
	{
		if (netQueueInterface()->isEmpty())
		{
			boost::this_thread::yield();
			continue;
		}
		event_data const&& netMsg = netQueueInterface()->popMsg();
		auto&&[type, strBody, head] = netMsg;
		auto&& strMsg = decode(type, strBody);
		event_data&& event = std::make_tuple(type, strMsg, head);
		msgInterface()->pushMsg(event);
	}
}

void AppManager::dispachMsg()
{
	while (!m_isDispatchExit)
	{
		if (!msgInterface()->isEmpty())
		{
			event_data const&& data = msgInterface()->popMsg();
			auto&&[nCommand, e, head] = std::move(data);
			if (!e.empty() && nCommand != 0 && !m_isDispatchExit)
			{
				eventManager()->pushEvent(nCommand, e, head);
			}
		}
		else
		{
			boost::this_thread::yield();
		}
	}
}

