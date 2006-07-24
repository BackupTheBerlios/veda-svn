#ifndef IXMLARCHIVE_H_
#define IXMLARCHIVE_H_

#include <istream>
#include <string>

#include <tinyxml/tinyxml.h>

#include "XmlArchive.hpp"

using namespace std;

namespace Packing
{

class IXmlArchive: public XmlArchive
{
	istream & m_is;
public:
	IXmlArchive();

/*
	IXmlArchive(istream & is):
		m_is(is), XmlArchive()
	{
	}
*/
	
	virtual ~IXmlArchive() { }
	
	/* header */
	
	virtual void open()
	{
		Archive::open();
		
		m_is>>m_document;
		
		m_pElement = m_document.RootElement();
		
		m_pElement->Attribute(c_VersionTag, &version);
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
		if(opened) (*this) & nvp(c_ItemTag, item);
		return *this;
	}
	
	template<class T>
	IXmlArchive & operator&(Named<T> item)
	{
		if(opened) read(item);
		return *this;
	}
	
protected:
	
	/*
	 *  working procedures 
	 */
	
	/* common */
	
	template<class T>
	void read(Named<T> item)
	{
		TiXmlElement * pOldElem = m_pElement;
		
		m_pElement = m_pElement->FirstChildElement(item.name);

		item.item.linkArchive(*this, version);
		
		m_pElement = pOldElem;
	}
	
	/* standard */
	
	void read(Named<double> & item)
	{ m_pElement->Attribute(item.name, &item.item); }
	
	void read(Named<int> & item)
	{ m_pElement->Attribute(item.name, &item.item); }
	
	void read(Named<char> & item)
	{ 
		item.item = m_pElement->Attribute(item.name)[0];
	}

	void read(Named<char*> & item) 
	{
		strcpy(item.item, m_pElement->Attribute(item.name));
	}
	
	void read(Named<string> & item)
	{
		item.item = m_pElement->Attribute(item.name);
	}
};

}

#endif /*IXMLARCHIVE_H_*/
