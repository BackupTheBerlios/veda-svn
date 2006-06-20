#ifndef POLYGON_H_
#define POLYGON_H_

#include <vector>

#include "Point.h"
#include "Line.h"

using namespace std;

namespace Geometry
{

template<class T>
class Polygon
{
	vector<Point<T> > points;
	Point<T> center;
	
	T m_minManhat;
	T m_maxManhat;
	T m_minRadius;
	T m_maxRadius;
public:
	Polygon(const int n_size = 16):
		center(0)
	{ 
		points.reserve(n_size);
		
		m_minManhat = m_minRadius = 0;
		m_maxManhat = m_maxRadius = 1e+40;
	}
	
	~Polygon() {}
	
	/* operators */
		
	Polygon& operator=(const Polygon& n_poly)
	{
		points = rhs.points;
		center = rhs.center;
		return *this;
	}
	
	Point<T> operator[](int i) { return points[i]; }
	
	Polygon & operator<<(const Point<T> & p)
	{
		points.push_back(p);
		return *this;
	}
	
	/* routines */
	
	int size(){return points.size(); }
	int getNum(){return points.size(); }
	
	Line<T> side(const int i)
	{
		return Line<T>(points[i], points[(i + 1) % size()]);
	}
	
	void add(const Point<T> & p) { points.push_back(p); }

	void clear() { points.clear(); }
	
	void cache();
	
	void square(T a)
	{
		clear();
		add(Point<T>(-a, -a));
		add(Point<T>(-a, a));
		add(Point<T>(a, a));
		add(Point<T>(a, -a));
	}
	
	/* center */
	
	void calcCenter()
	{
		center = 0;
		for(int i = 0; i < size(); ++i){
			center += points[i];	
		}
		center /= size();
	}
	
	Point<T> calcedCenter()
	{
		Point<T> c = 0;
		for(int i = 0; i < size(); ++i){
			c += points[i];	
		}
		c /= size();
		return c;
	}
	
	Point<T> getCenter(){ return center; }
	void setCenter(const Point<T> & p){ center = p; }
	
	/* different radiai */
	
	T averageRadius()
	{
		T r = 0;
		for(int i = 0; i <size(); ++i) r += !(center - points[i]);
		r /= size();
		return r;
	}
	
	T maxRadius()
	{
		T r = 0, t;
		for(int i = 0; i < size(); ++i)
			if(r < (t = center.distance(points[i]))) r = t;
		return r;
	}
	
	T minRadius()
	{
		T r = 0, t;
		for(int i = 0; i < size(); ++i)
			if(r > (t = center.distance(points[i]))) r = t;
		return r;
	}
	
	T maxManhatRadius()
	{
		T r = 0, t;
		for(int i = 0; i < size(); ++i)
			if(r < (t = (center.manhatTo(points[i])))) r =t;
		return r;
	}
	
	T minManhatRadius()
	{
		T r = 0, t;
		for(int i = 0; i < size(); ++i)
			if(r > (t = (m_Center.manhatTo(points[i])))) r = t;
		return r;
	}
	
	/* place of point */
	
	int contains(const Point<T> & p);
	
	T area()
	{
		T ar = 0;
		for(int i = 0; i < size(); ++i){
			ar += points[i] ^ points[(i+1) % size()];
		}
		ar *= 0.5;
		return fp_abs(ar);
	}
	
	int cutWith(Line<T> &line);
	
	int nearSide(const Point<T> & p, const T r);
	int nearOutside(const Point<T> & p, const T r);
	int nearInside(const Point<T> & p, const T r);
	
	template<class TArchive>
	void linkArchive(TArchive & ar, const int ver)
	{
		ar & nvp("point0", points[0]);
	}
};

}

#endif /*POLYGON_H_*/
