#ifndef POINT_H_
#define POINT_H_

#include <string.h>

#include "Packing/Archive.hpp"

#include "Math.hpp"

namespace Geometry
{

class Point
{
public:
	double x, y;	
public:
	Point():
		x(0), y(0)
	{ }

	Point(double a):
		x(a), y(a)
	{ }
	
	Point(double n_x, double n_y):
		x(n_x), y(n_y)
	{ }
	
	virtual ~Point() { }
	
	/* create some incedible points */
	
	void makeRandom(const double& a = 1)
	{
		x = a * (2.0 * Rand() - 1.0);
		y = a * (2.0 * Rand() - 1.0);
	}
	
	void makeRandom(const Point& p){
		x = p.x * (2 * Rand() - 1);
		y = p.y * (2 * Rand() - 1);
	}
	
	void makeNaN()
	{ x = Nan(); y = Nan(); }
	
	void makeInf()
	{ x = Inf(); y = Inf(); }
	
	/* check for sanity */
	
	int valid(){ return isValid(x) && isValid(y); }
	
	/* operators */
	
	Point & operator=(const Point & v) { x = v.x; y = v.y; return *this; }
	
	Point & operator+=(const Point & v) { x += v.x; y += v.y; return *this; }
	Point & operator-=(const Point & v) { x -= v.x; y -= v.y; return *this; }

	Point & operator*=(const double& a) { x*=a; y*=a; return *this; }	
	Point & operator/=(const double& a) { x/=a; y/=a; return *this; }

	Point operator-() const { return Point(-x, -y); }
	Point operator+(const Point& p){ return Point(x + p.x, y + p.y); }
	
	Point operator*(const double& a) const { return Point(x * a, y * a); }
	Point operator/(const double& a){ return Point(x / a, y / a); }
	
	/* some insane operators */
	
	double operator&(const Point p){ return x*p.x + y*p.y; }
	double operator^(const Point p){ return x*p.y - y*p.x; }
	
	double modulus() const {return Sqrt(Sqr(x) + Sqr(y)); }
	double manhat() const {return Abs(x) + Abs(y); }
	
	double modulusTo(const Point& p) const { return Sqrt(Sqr(x - p.x) + Sqr(y - p.y)); }
	double manhatTo(const Point& p) const { return Abs(x - p.x) + Abs(y - p.y); }
	virtual double distance(const Point& p) const { return modulusTo(p); }
	
	void turn () { double t = -x; x = y; y = t; }
	void turn_() { double t = x; x = -y; y = t; }
	Point turned(){ return Point(y, -x); }
	Point turned_(){return Point(-y, x); }
	
	void normalize(){ (*this) /= modulus(); }
	Point normalized(){ Point p = *this; return p / modulus(); }
	
	template<class TArchive>
	void linkArchive(TArchive & ar, const int v=0)
	{
		ar & nvp("x", x) & nvp("y", y);
	}

};

Point operator-(const Point & p1, const Point& p);

Point operator*(const double& a, const Point& p);

double distance(const Point& p1, const Point& p2);

}

#endif /*POINT_H_*/
