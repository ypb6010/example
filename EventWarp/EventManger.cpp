#include "stable.h"
#include "EventManger.h"


event_ptr EventManger::eventMangerFactory()
{
	return boost::make_shared<EventManger>();
}

EventManger::EventManger()
{
	
}


EventManger::~EventManger()
{
}

void EventManger::registerEvent(int32_t nCommand, event_fuction fun)
{
	auto it = m_funMap.find(nCommand);
	if (it != m_funMap.end())
	{
		debug_out << "重复注册回调函数" << nCommand << std::endl;
		debug_out << BOOST_CURRENT_FUNCTION << std::endl;
		return;
	}
	auto sig_ptr = boost::make_shared<event_signal_t>();
	sig_ptr->connect(fun);
	m_funMap.insert(std::make_pair(nCommand, sig_ptr));
}

void EventManger::pushEvent(int32_t nCommand, event_handler const& e, msg_header_t const& head)
{
	auto it = m_funMap.find(nCommand);
	if (it != m_funMap.end())
	{
		(*(it->second))(boost::cref(e),boost::cref(head));	///调用信号的operator()产生信号
	}
	else
	{
		debug_out << "数据包已经解析完成，但没找到核心响应函数：" << nCommand <<std::endl;
	}
}
