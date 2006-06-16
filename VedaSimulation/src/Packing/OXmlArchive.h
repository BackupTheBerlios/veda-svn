#ifndef OXMLARCHIVE_H_
#define OXMLARCHIVE_H_

#include <ostream>

#include <tinyxml/tinyxml.h>

#include "XmlArchive.h"

using namespace std;

namespace Packing
{

class OXmlArchive: public XmlArchive
{
	ostream & m_os;
public:
	OXmlArchive(ostream & n_os):
		m_os(n_os), XmlArchive()
	{ }
	
	virtual ~OXmlArchive() { }
	
	/* header */
	
	virtual void open()
	{
		Archive::open();
		
		m_document;
	}
	
	virtual void close()
	{
	}
	
	/* link operator */

	template<class T>
	OXmlArchive & operator&(T & item)
	{
		return (*this)<<(item);
	}
	
	/* main operator */
	
	template<class T>
	OXmlArchive & operator<<(T & item)
	{
		if(!opened) open();
		write(item);
		return *this;
	}
	
	template<class T>
	OXmlArchive & operator&(Named<T> named)
	{
		return (*this)<<(named);
	}

protected:
	
	/*
	 *  working procedures 
	 */
	
	/* common */
	
	template<class T>
	void write(T & item)
	{
		item.linkArchive(*this);
		m_os<<endl;
	}
	
	/* standard */
	
	void write(double & item) { m_os<<item<<" "; }
	
	void write(int & item) { m_os<<item<<" "; }

	void write(char & item) { m_os<<item<<" "; }
	
	void write(string & item) { m_os<<item<<" "; }
	
	void write(const char* item) { m_os<<item<<" "; }
		

};

}

#endif /*OXMLARCHIVE_H_*/
