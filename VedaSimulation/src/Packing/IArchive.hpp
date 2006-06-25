#ifndef IARCHIVE_H_
#define IARCHIVE_H_

#include <fstream>

#include <tinyxml/tinyxml.h>

#include "Archive.hpp"

using namespace std;

namespace Packing
{

class IArchive: public Archive
{
	istream & m_is;
public:
	IArchive(istream & is):
		m_is(is), Archive()
	{ 
	}
	
	virtual ~IArchive() { }
	
	/* header */
	
	virtual void open()
	{
		Archive::open();
		
		char tmp[256]; m_is.getline(tmp,256);
	}
	
	virtual void close()
	{
		char tmp[256]; m_is.getline(tmp, 256);
		
		Archive::close();
	}
	
	/* link operator */
	
	template<class T>
	IArchive & operator&(T & item)
	{
		if(!opened) return;
		read(item);
		return *this;
	}
	
	template<class T>
	IArchive & operator&(Named<T> named)
	{
		if(!opened) return;
		read(named.item);
		return *this;
	}
	
protected:
	
	/*
	 *  working procedures 
	 */
	
	/* common */
	
	template<class T>
	void read(T & item)
	{
		item.linkArchive(*this, version);
	}
	
	/* standard */
	
	void read(double & item) { m_is>>item; }
	
	void read(int & item) { m_is>>item; }
	
	void read(char & item) { m_is>>item; }
	
	void read(string & item) { m_is>>item; }
};
}

#endif /*IARCHIVE_H_*/
