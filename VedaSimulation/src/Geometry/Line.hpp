#ifndef LINE_H_
#define LINE_H_

#include "Packing/Packing.hpp"

#include "Math.hpp"
#include "Point.hpp"

namespace Geometry
{

class Line
{
protected:
	Point a, b;
public:
	Line():
		a(0), b(0)
	{ }

	Line(const Point & n_a, const Point & n_b): 
		a(n_a), b(n_b) 
	{ } 
	
	Line(const double x1, const double y1, const double x2, const double y2): 
		a(Point(x1, y1)), b(Point(x2, y2))
	{ }
	
	Line(const Line & rhs):
		a(rhs.a), b(rhs.b)
	{ }
	
	~Line(){}
	
	/* operators */
		
	Line& operator=(const Line& line) { a = line.a; b = line.b; return *this; }
	
	/* get, set */
		
	Point getA() {return a; }
	Point getB() {return b; }
	
	void setA(const Point & p){ a = p; }
	void setB(const Point & p){ b = p; }
	
	/* some routines */
	
	double length() { return (a - b).modulus(); }
	
	double distance(const Point & p)
	{
		Point n = (a - b).turned().normalized();
		return Abs((a - p) & n);
	}
	
	Point getNormal() {return (a - b).turned(); }
	
	/* checks */
	
	Point cross(Line& line);
	
	Point crossIn(Line& line);
	
	int oneSide(const Point & p1, const Point & p2);
	
	template<class TArchive>
	void linkArchive(TArchive & ar)
	{
		ar & nvp("a", a) & nvp("b", b);
	}
};

}

#endif /*LINE_H_*/
