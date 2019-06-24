#include "stable.h"
#include "NetWork.h"
#include "Transmitter.h"


NetWork::net_ptr NetWork::make_network(tcp_ptr pTcp /*= 0*/)
{
	return boost::make_shared<Transmitter>(pTcp);
}

uint64_t NetWork::adler32(char const* const buf, int32_t len)
{
	unsigned char const* const p = reinterpret_cast<unsigned char const* const>(buf);
	uint64_t adler = 1;
	uint64_t s1 = adler & 0xffff;
	uint64_t s2 = (adler >> 16) & 0xffff;
	for (int i = 0; i < len; i++)
	{
		s1 = (s1 + p[i]) % BASE;
		s2 = (s2 + s1) % BASE;
	}
	return (s2 << 16) + s1;
}

NetWork::NetWork()
{
}

NetWork::~NetWork()
{

}
