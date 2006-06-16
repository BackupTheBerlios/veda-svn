#ifndef IXMLARCHIVE_H_
#define IXMLARCHIVE_H_

#include <istream>

#include <tinyxml/tinyxml.h>

#include "XmlArchive.h"

using namespace std;

namespace Packing
{

class IXmlArchive: public XmlArchive
{
	istream & m_is;
public:
	IXmlArchive(istream & is):
		m_is(is), XmlArchive()
	{ 
	}
	
	virtual ~IXmlArchive() { }
	
	/* header */
	
	virtual void open()
	{
		Archive::open();
		
		m_is>>m_document;
		
		m_pElement = m_document.RootElement();
	}
	
	virtual void close()
	{
		/* nothing */
		
		Archive::close();
	}
	
	/* link operator */
	
	template<class T>
	IXmlArchive & operator&(T & item)
	{
		(*this)>>(item);
		return *this;
	}
	
	/* main operator */
	
	template<class T>
	IXmlArchive & operator>>(T & item)
	{
		if(!opened) open();
		read(item);
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
		item.linkArchive(*this);
	}
	
	/* standard */
	
	void read(double & item) { m_is>>item; }
	
	void read(int & item) { m_is>>item; }
	
	void read(char & item) { m_is>>item; }
	
	void read(string & item) { m_is>>item; }
};

}

#endif /*IXMLARCHIVE_H_*/
