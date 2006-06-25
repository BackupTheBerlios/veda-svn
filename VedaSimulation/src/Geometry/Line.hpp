#ifndef LINE_H_
#define LINE_H_

#include "Packing/Packing.h"

#include "Math.hpp"
#include "Point.hpp"

namespace Geometry
{

template<class T>
class Line
{
protected:
	Point<T> a, b;
public:
	Line():
		a(0), b(0)
	{ }

	Line(const Point<T> & n_a, const Point<T> & n_b): 
		a(n_a), b(n_b) 
	{ } 
	
	Line(const T x1, const T y1, const T x2, const T y2): 
		a(Point<T>(x1, y1)), b(Point<T>(x2, y2))
	{ }
	
	Line(const Line & rhs):
		a(rhs.a), b(rhs.b)
	{ }
	
	~Line(){}
	
	/* operators */
		
	Line& operator=(const Line& line) { a = line.a; b = line.b; return *this; }
	
	/* get, set */
		
	Point<T> getA() {return a; }
	Point<T> getB() {return b; }
	
	void setA(const Point<T> & p){ a = p; }
	void setB(const Point<T> & p){ b = p; }
	
	/* some routines */
	
	T length() { return (a - b).modulus(); }
	
	T distance(const Point<T> & p)
	{
		Point<T> n = (a - b).turned().normalized();
		return Abs((a - p) & n);
	}
	
	Point<T> getNormal() {return (a - b).turned(); }
	
	/* checks */
	
	Point<T> cross(Line& line);
	
	Point<T> crossIn(Line& line);
	
	int oneSide(const Point<T> & p1, const Point<T> & p2);
	
	Point<T> cross(Line& line)
	{
		Point<T> n = getNormal();
		double t = ((m_A - line.m_B) & n) / ((line.m_A - line.m_B) & n);
		
		return t*line.m_A + (1 - t)*line.m_B;
	}
	
	Point<T> crossIn(Line<T> & line)
	{
		Point<T> n = getNormal();
		T t = ((m_A - line.m_B) & n) / ((line.m_A - line.m_B) & n);
		
		Point<T> res;
		
		if( (t > 0 && t <1) || fp_zero(t) || fp_zero(1 - t)){
			res = (t*line.m_A + (1 - t)*line.m_B);
		}else res.makeNaN();
		
		return res;
	}
	
	int oneSide(const Point<T> & p1, const Point<T> & p2)
	{
		Point<T> n = getNormal();
		return Signum((p1 - m_A) & n) == Signum((p2 - m_A) & n);
	}
	
	template<class TArchive>
	void linkArchive(TArchive & ar)
	{
		ar & nvp("a", a) & nvp("b", b);
	}
};

}

#endif /*LINE_H_*/
