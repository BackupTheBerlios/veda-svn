#include "Log.h"

Log& Log::operator<<(const char * str)
{
	m_Os<<str<<endl;
	return *this;
}
