#ifndef LOGGER_H_
#define LOGGER_H_

#include <fstream>

using namespace std;

class Log
{
protected:
	ostream & m_Os;
public:
	Logger(ostream & os):
		m_Os(os) { }
		
	virtual ~Log() { }
	
	
	Log& operator<<(const char * str);
};

#endif /*LOGGER_H_*/
