#ifndef POLYGON_H_
#define POLYGON_H_

#include <vector>

#include "Vector.h"

using namespace std;

namespace Geometry
{

template<class TReal>
class Polygon
{
	vector<Vector<TReal> > m_Vectors;
public:
	Polygon() { }
	virtual ~Polygon() { }
};

}

#endif /*POLYGON_H_*/
