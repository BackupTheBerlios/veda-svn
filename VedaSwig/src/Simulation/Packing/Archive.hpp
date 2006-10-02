#ifndef ARCHIVE_H_
#define ARCHIVE_H_

#include <fstream>

using namespace std;

namespace Packing
{
	
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
	
	T & value()
	{
		return item;
	}
};

/* fabric */

template<class T>
Named<T> nvp(const char* n_name, T & n_item)
{
	return Named<T>(n_name, n_item);
}
	
/* base archive class */
	
class Archive
{
protected:
	static const int c_NameLength = 32;
	
	static char* c_ItemTag;
	static char* c_RootTag;
	static char* c_VersionTag;

	int version; /* versioning NYE */
	bool opened;
public:
	Archive(const int n_version = 0):
		opened(false), version(n_version)
	{ }
	virtual ~Archive() { if(opened) close(); }
	
	virtual void open() { opened = true; }
	virtual void close() { opened = false; }
	
	int get_Version() { return version; }
	void set_Vesion(int n_version) { version = n_version; }
};

class IArchive;

class OArchive;

}

#endif /*ARCHIVE_H_*/
