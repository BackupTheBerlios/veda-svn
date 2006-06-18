#ifndef POLYGON_H_
#define POLYGON_H_

#include <vector>

#include "Point.h"

using namespace std;

namespace Geometry
{

template<class TReal>
class Polygon
{
	vector<Point<TReal> > m_points;
public:
	Polygon() { }
	virtual ~Polygon() { }
};

}

#endif /*POLYGON_H_*/
