#include "Line.h"

namespace Geometry
{

template<class T>
Point<T> Line<T>::cross(Line& line)
{
	Point<T> n = getNormal();
	double t = ((m_A - line.m_B) & n) / ((line.m_A - line.m_B) & n);
	
	return t*line.m_A + (1 - t)*line.m_B;
}

template<class T>
Point<T> Line<T>::crossIn(Line<T> & line)
{
	Point<T> n = getNormal();
	T t = ((m_A - line.m_B) & n) / ((line.m_A - line.m_B) & n);
	
	Point<T> res;
	
	if( (t > 0 && t <1) || fp_zero(t) || fp_zero(1 - t)){
		res = (t*line.m_A + (1 - t)*line.m_B);
	}else res.makeNaN();
	
	return res;
}

template<class T>
int Line<T>::oneSide(const Point<T> & p1, const Point<T> & p2)
{
	Point<T> n = getNormal();
	return Signum((p1 - m_A) & n) == Signum((p2 - m_A) & n);
}

}
