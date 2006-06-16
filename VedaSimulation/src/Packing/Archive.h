#ifndef ARCHIVE_H_
#define ARCHIVE_H_

#include <fstream>

using namespace std;

namespace Packing
{
	
/* base archive class */
	
class Archive
{
protected:
	int version; /* versioning NYE */
	bool opened;
public:
	Archive():
		opened(false)
	{ }
	virtual ~Archive() { }
	
	virtual void open() { opened = true; }
	virtual void close() { opened = false; }
	
	int get_Version() { return version; }
	void set_Vesion(int n_version) { version = n_version; }
};


/*
 *	name-value pair
 */

/* named item */

template<class T>
struct Named
{
	const char* name;
	T & item;

	explicit Named(const char * n_name, T & n_item):
		name(n_name), item(n_item)
	{ }
	
	Named(const Named & rhs):
		name(rhs.name), item(rhs.item)
	{ }
	
	template<class TArchive>
	void linkArchive(TArchive & ar)
	{
		ar & name & value();
	}
	
	T & value()
	{
		return item;
	}
};

/* fabric */

template<class T>
Named<T> makeNamed(const char* n_name, T & n_item)
{
	return Named<T>(n_name, n_item);
}

}

#endif /*ARCHIVE_H_*/
