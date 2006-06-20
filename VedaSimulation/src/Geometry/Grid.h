#ifndef GRID_H_
#define GRID_H_

#include <vector>

#include "Packing/Archive.h"

#include "Point.h"
#include "Line.h"
#include "Polygon.h"

using namespace std;

namespace Geometry
{

template<class TReal>
class Grid
{
	vector<Polygon<TReal> > domens;
	vector<Point<TReal> > centers;
	
	Point<TReal> center;
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
		Line<double> llline;
	}
	
	template<class TArchive>
	void linkArchive(TArchive & ar, const int v=0)
	{
		ar & nvp("center", center);
	}
};

}

#endif /*GRID_H_*/
