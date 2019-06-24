#include "stable.h"
#include "NetGoogleFilter.h"
//#include "NetMessageManager.h"

using namespace ::google::protobuf;

NetGoogleFilter::NetGoogleFilter()
{

}

NetGoogleFilter::~NetGoogleFilter()
{

}

unsigned long long NetGoogleFilter::Adler32( unsigned char* buf, int len )
{
	unsigned long long adler = 1;
	unsigned long long s1 = adler & 0xffff;
	unsigned long long s2 = (adler >> 16) & 0xffff;
	for (int i = 0; i < len; i++) 
	{
		s1 = (s1 + buf[i]) % BASE;
		s2 = (s2 + s1) % BASE;
	}
	return (s2 << 16) + s1;
}