#include "Polygon.h"

namespace Geometry
{

/* main function of all project */

template<class T>
int Polygon<T>::cutWith(Line<T> &line) 
{ 
	int i1, i2, i, j;
	Line<T> segm;
	Point<T> p1, p2, c = getCenter();
	
	std::vector<Point<T> > tmpPoints;
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

template<class T>
void Polygon<T>::cache()
{
	m_minManhat = minManhatRadius();
	m_maxManhat = maxManhatRadius();
	m_minRadius = minRadius();
	m_maxRadius = maxRadius();
}

/* place of point */

template<class T>
int Polygon<T>::nearSide(const Point<T> & v, const T r)
{
	
	if(distance(v, center) > m_maxRadius + r) return 0;
		
	int kNear = 0;
	int i;
	T t;
	Point<T> a, b;
	Point<T> ab, n, v_par, vb;
	T dist;
	Line<T> line;
	
	for(i = 0; i < size() && !kNear; ++i){
		line = side(i);
		a = line.getA(); b = line.getB();
		ab = a - b;
		dist = line.distance(v);
		
		if(dist < r){
			v_par = v - n * ((v - a) & n);
			vb = v_par - b;
			t = (vb.getX() + vb.getY()) / (ab.getX() + ab.getY());
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

template<class T>
int Polygon<T>::contains(const Point<T>& p)
{
	if(distance(p, center) > m_maxRadius) return 0;
	
	int kOk = 1;
	int i;

	Point<T> c = center;
	Line<T> line;
	
	for(i = 0; i < size(); ++i){
		line = side(i);
		if(! line.oneSide(c, p)){
			kOk = 0;
			break;
		}
	}
	return kOk;
}

template<class T>
int Polygon<T>::nearOutside(const Point<T>& v, const T r)
{
	return (!contains(v) && nearSide(v, r));
}

template<class T>
int Polygon<T>::nearInside(const Point<T>& v, const T r)
{
	return (contains(v) && nearSide(v, r));
}

}
