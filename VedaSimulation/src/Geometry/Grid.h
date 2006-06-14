#ifndef GRID_H_
#define GRID_H_

#include <vector>

#include "Vector.h"
#include "Polygon.h"

using namespace std;

namespace Geometry
{

template<class TReal>
class Grid
{
	vector<Polygon<TReal> > m_Domens;
	vector<Vector<TReal> > m_Centers;
public:
	Grid() { }

	virtual ~Grid() { }

	char* get_Name()
	{
		char* res = new char[80];
		strcpy(res, "I'm Grid, friend!");
		return res;
	}
};

}

#endif /*GRID_H_*/
