#ifndef NETARCHIVE_H_
#define NETARCHIVE_H_

#include "Archive.h"

namespace Packing
{

class NetArchive::public Archive
{
protected:
	vector<double> doubleData;
	vector<char> charData;
	vector<int> intData;
	vector<float> floatData;
public:
	NetArchive():
		Archive()
	{ }
	
	virtual ~NetArchive() { }
	
	virtual void open()
	{
		Archive::open();
	}
	
	virtual void close()
	{
		Archive::close();
	}
	
	
};

}

#endif /*NETARCHIVE_H_*/
