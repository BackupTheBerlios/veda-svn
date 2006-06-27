#ifndef POINT_H_
#define POINT_H_

#include <string.h>

#include "Packing/Packing.hpp"

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
	
	Point & operator=(const double & a) { x = a; y = a; return *this; }
	Point & operator=(const Point & v) { x = v.x; y = v.y; return *this; }
	
	Point & operator+=(const Point & v) { x += v.x; y += v.y; return *this; }
	Point & operator-=(const Point & v) { x -= v.x; y -= v.y; return *this; }

	Point & operator*=(const double& a) { x*=a; y*=a; return *this; }	
	Point & operator/=(const double& a) { x/=a; y/=a; return *this; }

	friend Point operator+(const Point& p1, const Point& p2){ return Point(p1.x + p2.x, p1.y + p2.y); }
	friend Point operator-(const Point& p1, const Point& p2){ return Point(p1.x - p2.x, p1.y - p2.y); }
	
	friend Point operator*(const Point& p, const double& a){ return Point(p.x * a, p.y * a); }
	friend Point operator*(const double& a, const Point& p){ return Point(p.x * a, p.y * a);}
	friend Point operator/(const Point& p, const double& a){ return Point(p.x / a, p.y / a); }
	
	/* some insane operators */
	
	double operator&(const Point p){ return x*p.x + y*p.y; }
	double operator^(const Point p){ return x*p.y - y*p.x; }
	
	double modulus(){return Sqrt(Sqr(x) + Sqr(y)); }
	double manhat(){return Abs(x) + Abs(y); }
	double operator!(){ return modulus(); }
	
	double modulusTo(const Point& p){ return ((*this) - p).modulus(); }
	double manhatTo(const Point& p){ return ((*this) - p).manhat(); }
	virtual double distance(const Point& p){ return modulusTo(p); }
	friend double distance(const Point& p1, const Point& p2) { return (p1 - p2).modulus(); }
	
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

}

#endif /*POINT_H_*/
