#include "stable.h"
#include "EventWarp.h"

EventWarp::factory_type EventWarp::s_factory;

msg_ptr EventWarp::msgInterface() const
{
	return m_iMsg;
}

net_message_ptr EventWarp::netQueueInterface() const
{
	return m_netMsg;
}

local_message_ptr EventWarp::localEncodeInterface() const
{
	return m_localEnCode;
}

EventWarp::EventWarp()
	: m_iMsg(boost::make_shared<MessageQueue<event_data>>())
	, m_netMsg(boost::make_shared<MessageQueue<event_data>>())
	, m_localEnCode(boost::make_shared<MessageQueue<request_t>>())
{
	
}

event_ptr EventWarp::makeEventWarp(int key)
{
	auto it = s_factory.find(key);
	if (it != s_factory.end())
	{
		return it->second();
	}
	debug_out << "EventWarp没有找到注册的工厂\t:" << "s_factory : key = " << key << std::endl;
	debug_out << BOOST_CURRENT_FUNCTION << std::endl;
	return event_ptr();
}

void EventWarp::registerFactory(int key, event_factory_fun fun)
{
	if (s_factory.find(key) == s_factory.end())
	{
		s_factory.insert(std::make_pair(key, fun));
	}
	else
	{
		debug_out << "注册的工厂已经存在" << std::endl;
	}
}
