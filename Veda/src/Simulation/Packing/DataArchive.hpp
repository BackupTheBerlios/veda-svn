#ifndef NETARCHIVE_H_
#define NETARCHIVE_H_

#include "Archive.hpp"

namespace Packing
{

class DataArchive::public Archive
{
protected:
	vector<double> doubleData;
	vector<char> charData;
	vector<int> intData;
	vector<float> floatData;
	vector<char*> pcharData;
public:
	DataArchive():
		Archive()
	{ }
	
	virtual ~DataArchive() { }
	
	virtual void open()
	{
		Archive::open();
	}
	
	virtual void close()
	{
		Archive::close();
	}	
};

class IDataArchive;

class ODataArchive;

}

#endif /*NETARCHIVE_H_*/
