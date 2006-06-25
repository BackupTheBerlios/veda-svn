#ifndef OXMLARCHIVE_H_
#define OXMLARCHIVE_H_

#include <ostream>

#include <tinyxml/tinyxml.h>

#include "XmlArchive.hpp"

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
		
		m_document.LinkEndChild(new TiXmlElement(c_RootTag));
		
		m_pElement = m_document.RootElement();
		
		m_pElement->SetAttribute(c_VersionTag, version);
	}
	
	virtual void close()
	{
		m_os<<m_document;
		
		Archive::close();
	}
	
	/* link operator */

	template<class T>
	OXmlArchive & operator&(T & item)
	{
		if(opened) (*this) & nvp(c_ItemTag, item);
		return *this;
	}
	
	template<class T>
	OXmlArchive & operator&(Named<T> item)
	{
		if(opened) write(item);
		return *this;
	}

protected:
	
	/*
	 *  working procedures 
	 */
	
	/* common */
	
	template<class T>
	void write(Named<T> item)
	{
		TiXmlElement * pOldElem = m_pElement;
		
		m_pElement = m_pElement->LinkEndChild(new TiXmlElement(item.name))->ToElement();

		item.item.linkArchive(*this, version);
		
		m_pElement = pOldElem;
	}
	
	/* standard */
	
	void write(Named<double> & item)
	{ m_pElement->SetDoubleAttribute(item.name, item.item); }
	
	void write(Named<int> & item)
	{ m_pElement->SetAttribute(item.name, item.item); }
	
	void write(Named<char> & item)
	{ 
		char str[2]; str[0] = item.item; str[1] = '\0';
		m_pElement->SetAttribute(item.name, str); 
	}

	void write(Named<const char*> & item) 
	{
		m_pElement->SetAttribute(item.name, item.item);
	}
	
	void write(Named<string> & item)
	{
		m_pElement->SetAttribute(item.name, item.item.c_str());
	}
};

}

#endif /*OXMLARCHIVE_H_*/
