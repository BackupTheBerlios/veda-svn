#ifndef VECTOR_H_
#define VECTOR_H_

#include <string.h>

#include "Packing/Archive.h"

using Packing::nvp;

namespace Geometry
{

template<class TReal>
class Vector
{
public:
	TReal x, y, z;	
public:
	Vector():
		x(0), y(0), z(0) { }

	Vector(TReal a):
		x(a), y(a), z(a) { }
	
	Vector(TReal n_x, TReal n_y, TReal n_z):
		x(n_x), y(n_y), z(n_z) { }
	
	virtual ~Vector() { }
	
	Vector & operator=(const Vector & v)
	{
		x = v.x; y = v.y; z = v.z;
		return *this;
	}
	
	Vector & operator+=(const Vector & v)
	{
		x += v.x; y += v.y; z += v.z;
		return *this;
	}
	
	template<class TArchive>
	void linkArchive(TArchive & ar, const int v=0)
	{
		ar & nvp("x", x) & nvp("y", y);
		if(v == 1)
			ar & nvp("z", z);
	}
};

}

#endif /*VECTOR_H_*/
