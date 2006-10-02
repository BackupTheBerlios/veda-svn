#ifndef POLYGON_H_
#define POLYGON_H_

#include <vector>

#include "Point.hpp"
#include "Line.hpp"

using namespace std;

namespace Geometry
{

class Polygon
{
	vector<Point> points;
	Point center;
	
	double m_minManhat;
	double m_maxManhat;
	double m_minRadius;
	double m_maxRadius;
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
		
	Polygon& operator=(const Polygon& rhs)
	{
		points = rhs.points;
		center = rhs.center;
		return *this;
	}
	
	Point operator[](int i) { return points[i]; }
	
	Polygon & operator<<(const Point & p)
	{
		points.push_back(p);
		return *this;
	}
	
	/* routines */
	
	int size(){return points.size(); }
	int getNum(){return points.size(); }
	
	Line side(const int i)
	{
		return Line(points[i], points[(i + 1) % size()]);
	}
	
	void add(const Point & p) { points.push_back(p); }

	void clear() { points.clear(); }

	
	void square(double a)
	{
		clear();
		add(Point(-a, -a));
		add(Point(-a, a));
		add(Point(a, a));
		add(Point(a, -a));
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
	
	Point calcedCenter()
	{
		Point c = 0;
		for(int i = 0; i < size(); ++i){
			c += points[i];	
		}
		c /= size();
		return c;
	}
	
	Point getCenter(){ return center; }
	void setCenter(const Point & p){ center = p; }
	
	/* different radiai */
	
	double averageRadius()
	{
		double r = 0;
		for(int i = 0; i <size(); ++i) r += (center - points[i]).modulus();
		r /= size();
		return r;
	}
	
	double maxRadius()
	{
		double r = 0, t;
		for(int i = 0; i < size(); ++i)
			if(r < (t = center.distance(points[i]))) r = t;
		return r;
	}
	
	double minRadius()
	{
		double r = 0, t;
		for(int i = 0; i < size(); ++i)
			if(r > (t = center.distance(points[i]))) r = t;
		return r;
	}
	
	double maxManhatRadius()
	{
		double r = 0, t;
		for(int i = 0; i < size(); ++i)
			if(r < (t = (center.manhatTo(points[i])))) r =t;
		return r;
	}
	
	double minManhatRadius()
	{
		double r = 0, t;
		for(int i = 0; i < size(); ++i)
			if(r > (t = (center.manhatTo(points[i])))) r = t;
		return r;
	}
	
	/* place of point */
	
	double area()
	{
		double ar = 0;
		for(int i = 0; i < size(); ++i){
			ar += points[i] ^ points[(i+1) % size()];
		}
		ar *= 0.5;
		return Abs(ar);
	}
	
	/* main function of all project */
	
	int cutWith(Line &line) 
	{ 
		int i1, i2, i, j;
		Line segm;
		Point p1, p2, c = getCenter();
		
		std::vector<Point > tmpPoints;
		tmpPoints.reserve(points.size() + 2);
		
		int kFound = 0;
		
		i = 0;
		
		while((i < size()) && !kFound){
			segm = side(i);
			p1 = line.crossIn(segm); kFound = p1.valid();
			++i;
		}
		--i;
		
		if(kFound){
			i1 = i;
			if(line.oneSide(points[i1], c)){
				kFound = 0;
				i = (i1 + 1) % size();
				while(!kFound){
					segm = side(i);
					p2 = line.crossIn(segm); kFound = p2.valid();
					i = (i + 1) % size();
				}
				i2 = i;
				
				for(i = i2; i != (i1 + 1) % size(); i = (i + 1) % size())
					tmpPoints.push_back(points[i]);
				
				/* please write update subroutine for polygon class, to exclude nearest points */
				
				//if(tmpPoints.empty()||(!fp_zero(p1.manhatTo(*tmpPoints.end())) && !fp_zero(p1.manhatTo(*tmpPoints.begin()))))
					tmpPoints.push_back(p1);
				
				
				//if(tmpPoints.empty()||(!fp_zero(p2.manhatTo(*tmpPoints.end())) && !fp_zero(p2.manhatTo(*tmpPoints.begin()))))
					tmpPoints.push_back(p2);
				
				points = tmpPoints;
				
				return 1;
			}else{
				kFound = 0;
				i1 = (i1 + 1) % size();
				i = i1;
				while(!kFound){
					segm = side(i);
					p2 = line.crossIn(segm); kFound = p2.valid();
					i = (i + 1) % size();
				}
				i2 = i;
				
				for(i = i1; i != i2; i = (i + 1) % size())
					tmpPoints.push_back(points[i]);
				
				//if(tmpPoints.empty()||(!fp_zero(p2.manhatTo(*tmpPoints.end()))&&!fp_zero(p2.manhatTo(*tmpPoints.begin()))))
					tmpPoints.push_back(p2);
				
				//if(tmpPoints.empty()||(!fp_zero(p1.manhatTo(*tmpPoints.end()))&&!fp_zero(p1.manhatTo(*tmpPoints.begin()))))
					tmpPoints.push_back(p1);
				
				points = tmpPoints;
				
				return 1;
			}
		}
		return 0;
	}

	/* common */
	
	void cache()
	{
		m_minManhat = minManhatRadius();
		m_maxManhat = maxManhatRadius();
		m_minRadius = minRadius();
		m_maxRadius = maxRadius();
	}
	
	/* place of point */
	
	int nearSide(const Point & v, const double r)
	{
		
		if(distance(v, center) > m_maxRadius + r) return 0;
			
		int kNear = 0;
		int i;
		double t;
		Point a, b;
		Point ab, n, v_par, vb;
		double dist;
		Line line;
		
		for(i = 0; i < size() && !kNear; ++i){
			line = side(i);
			a = line.getA(); b = line.getB();
			ab = a - b;
			dist = line.distance(v);
			
			if(dist < r){
				v_par = v - n * ((v - a) & n);
				vb = v_par - b;
				t = (vb.x + vb.y) / (ab.x + ab.y);
				if(t > 0 && t < 1) kNear =1;
			}
		}
		
		for(i = 0; i < size() && !kNear; ++i){
			if(points[i].manhatTo(v) < r) if(points[i].distance(v) < r){
				kNear = 1;
			}
		}
		
		return kNear;
	}
	
	int contains(const Point& p)
	{
		if(distance(p, center) > m_maxRadius) return 0;
		
		int kOk = 1;
		int i;
	
		Point c = center;
		Line line;
		
		for(i = 0; i < size(); ++i){
			line = side(i);
			if(! line.oneSide(c, p)){
				kOk = 0;
				break;
			}
		}
		return kOk;
	}
	
	int nearOutside(const Point& v, const double r)
	{
		return (!contains(v) && nearSide(v, r));
	}
	
	int nearInside(const Point& v, const double r)
	{
		return (contains(v) && nearSide(v, r));
	}
	
	template<class TArchive>
	void linkArchive(TArchive & ar, const int ver)
	{
		static char temp[16];
		for(int i=0; i < size(); ++i){
			sprintf(temp, "p%d", i);
			ar & nvp(temp, points[i]);
		}
	}
};

}

#endif /*POLYGON_H_*/
