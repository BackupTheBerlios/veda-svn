#include "Line.hpp"

namespace Geometry{

Point Line::cross(Line& line)
{
	Point n = getNormal();
	double t = ((a - line.b) & n) / ((line.a - line.b) & n);
	
	return t*line.a + (1 - t)*line.b;
}

Point Line::crossIn(Line & line)
{
	Point n = getNormal();
	double t = ((a - line.b) & n) / ((line.a - line.b) & n);
	
	Point res;
	
	if( (t > 0 && t <1) || isZero(t) || isZero(1 - t)){
		res = (t*line.a + (1 - t)*line.b);
	}else res.makeNaN();
	
	return res;
}

int Line::oneSide(const Point & p1, const Point & p2)
{
	Point n = getNormal();
	return Signum((p1 - a) & n) == Signum((p2 - a) & n);
}

}
