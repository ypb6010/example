#pragma once
#include "EventDefine.h"
#include "core_global.h"

class CORE_EXPORT WindowInterface
{
public:
	WindowInterface(Core* pCore)
		: m_pCore(pCore)
	{
		BOOST_ASSERT(m_pCore);
	}
public:

	virtual void requestLogin(int32_t user_type, std::string const username, std::string const pass, std::string const pubFile);
public:
	virtual void receiptLogin(std::string const strMsg) = 0;

protected:
	Core* m_pCore;
};
