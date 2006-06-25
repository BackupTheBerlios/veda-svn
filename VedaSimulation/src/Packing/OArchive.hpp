#ifndef OARCHIVE_H_
#define OARCHIVE_H_

#include <fstream>

#include "Archive.hpp"

using namespace std;

namespace Packing
{

class OArchive: public Archive
{
	ostream & m_os;
public:
	OArchive(ostream & n_os):
		m_os(n_os), Archive()
	{
	}
	
	virtual ~OArchive() { }
	
	/* header */
	
	virtual void open()
	{
		Archive::open();
		
		m_os<<"simple archive: begin"<<endl;
	}
	
	virtual void close()
	{
		m_os<<"end"<<endl;
		
		Archive::close();
	}
	
	/* link operator */

	template<class T>
	OArchive & operator&(T & item)
	{
		if(opened) write(item);
		return *this;
	}
	
	template<class T>
	OArchive & operator&(Named<T> named)
	{
		if(opened) write(named.item);
		return *this;
	}
	
protected:
	
	/*
	 *  working procedures 
	 */
	
	/* common */
	
	template<class T>
	void write(T & item)
	{
		item.linkArchive(*this, version);
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

#endif /*OARCHIVE_H_*/
