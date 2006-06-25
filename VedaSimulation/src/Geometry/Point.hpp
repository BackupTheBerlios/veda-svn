#ifndef POINT_H_
#define POINT_H_

#include <string.h>

#include "Packing/Packing.h"

#include "Math.hpp"

namespace Geometry
{

template<class T>
class Point
{
public:
	T x, y;	
public:
	Point():
		x(0), y(0)
	{ }

	Point(T a):
		x(a), y(a)
	{ }
	
	Point(T n_x, T n_y):
		x(n_x), y(n_y)
	{ }
	
	virtual ~Point() { }
	
	/* create some incedible points */
	
	void makeRandom(const T& a = 1)
	{
		x = a * (2.0 * Rand() - 1.0);
		y = a * (2.0 * Rand() - 1.0);
	}
	
	void makeRandom(const Point& p){
		m_X = p.m_X * (2 * fp_rand() - 1);
		m_Y = p.m_Y * (2 * fp_rand() - 1);
	}
	
	void makeNaN()
	{ m_X = fp_nan(); m_Y = fp_nan(); }
	
	void makeInf()
	{ m_X = fp_inf(); m_Y = fp_inf(); }
	
	/* check for sanity */
	
	int valid(){ return fp_valid(m_X) && fp_valid(m_Y); }
	
	/* operators */
	
	Point & operator=(const T & a) { x = a; y = a; return *this; }
	Point & operator=(const Point & v) { x = v.x; y = v.y; return *this; }
	
	Point & operator+=(const Point & v) { x += v.x; y += v.y; return *this; }
	Point & operator-=(const Point & v) { x -= v.x; y -= v.y; return *this; }

	Point & operator*=(const T& a) { x*=a; y*=a; return *this; }	
	Point & operator/=(const T& a) { x/=a; y/=a; return *this; }

	friend Point operator+(const Point& p1, const Point& p2){ return Point(p1.x + p2.x, p1.y + p2.y); }
	friend Point operator-(const Point& p1, const Point& p2){ return Point(p1.x - p2.x, p1.y - p2.y); }
	
	friend Point operator*(const Point& p, const T& a){ return Point(p.x * a, p.y * a); }
	friend Point operator*(const T& a, const Point& p){ return Point(p.x * a, p.y * a);}
	friend Point operator/(const Point& p, const T& a){ return Point(p.x / a, p.y / a); }
	
	/* some insane operators */
	
	T operator&(const Point p){ return x*p.x + y*p.y; }
	T operator^(const Point p){ return x*p.y - y*p.x; }
	
	T modulus(){return Sqrt(Sqr(x) + Sqr(y)); }
	T manhat(){return Abs(x) + Abs(y); }
	T operator!(){ return modulus(); }
	
	T modulusTo(const Point& p){ return ((*this) - p).modulus(); }
	T manhatTo(const Point& p){ return ((*this) - p).manhat(); }
	virtual T distance(const Point& p){ return modulusTo(p); }
	friend T distance(const Point& p1, const Point& p2) { return (p1 - p2).modulus(); }
	
	void turn () { T t = -x; x = y; y = t; }
	void turn_() { T t = x; x = -y; y = t; }
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
