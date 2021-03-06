#ifndef XMLARCHIVE_H_
#define XMLARCHIVE_H_

#include <tinyxml/tinyxml.h>

#include "Archive.hpp"

namespace Packing
{

class XmlArchive: public Archive
{
protected:
	TiXmlDocument m_document;
	TiXmlElement * m_pElement;
public:
	XmlArchive():
		Archive()
	{ }
	virtual ~XmlArchive() { }
	
	virtual void open() { opened = true; }
	virtual void close() { opened = false; }
};

class IXmlArchive;
class OXmlArchive;

}

#endif /*XMLARCHIVE_H_*/
