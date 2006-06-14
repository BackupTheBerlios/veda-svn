#include "Log.h"

#include <time.h>

double get_Time()
{
	return (double)clock() / CLOCKS_PER_SEC;
}

Log& Log::operator<<(const char * str)
{
	m_Os<<get_Time()<<":"<<str<<endl;
	return *this;
}
