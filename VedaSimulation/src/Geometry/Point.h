#ifndef POINT_H_
#define POINT_H_

#include <string.h>

#include "Packing/Archive.h"

using Packing::nvp;

namespace Geometry
{

template<class TReal>
class Point
{
public:
	TReal x, y;	
public:
	Point():
		x(0), y(0) { }

	Point(TReal a):
		x(a), y(a) { }
	
	Point(TReal n_x, TReal n_y, TReal n_z):
		x(n_x), y(n_y) { }
	
	virtual ~Point() { }
	
	Point & operator=(const Point & v)
	{
		x = v.x; y = v.y; z = v.z;
		return *this;
	}
	
	Point & operator+=(const Point & v)
	{
		x += v.x; y += v.y;
		return *this;
	}
	
	template<class TArchive>
	void linkArchive(TArchive & ar, const int v=0)
	{
		ar & nvp("x", x) & nvp("y", y);
	}
};

}

#endif /*POINT_H_*/
