#ifndef GRID_H_
#define GRID_H_

#include <vector>

#include "Packing/Archive.hpp"

#include "Point.hpp"
#include "Line.hpp"
#include "Polygon.hpp"

using namespace std;

namespace Geometry
{

class Grid
{
	vector<Polygon> domens;
	vector<Point> centers;
	
	Point center;
public:
	Grid() { }

	virtual ~Grid() { }

	char* get_Name()
	{
		char* res = new char[80];
		strcpy(res, "I'm Grid, friend!");
		return res;
	}
	
	void test()
	{
		Line llline;
	}
	
	template<class TArchive>
	void linkArchive(TArchive & ar, const int v=0)
	{
		ar & nvp("center", center);
	}
};

}

#endif /*GRID_H_*/
