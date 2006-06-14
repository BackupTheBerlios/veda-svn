#include <iostream>

#include "Geometry/Vector.h"
#include "Geometry/Polygon.h"
#include "Geometry/Grid.h"

using namespace std;

using namespace Geometry;

template<class TReal>
ostream & operator<<(ostream & os, Vector<TReal> & v)
{
	return os<<"Vector: "<<v.x<<", "<<v.y<<", "<<v.z;
}

int main(int argc, char** argv)
{
	for(int i=0; i<10; ++i){
		cout<<"Preved medved."<<endl;
	}
	
	Polygon<double> polygon;
	Grid<double> grid;
	
	cout<<grid.get_Name()<<endl;
	
	Vector<double> v, v0;
	
	v.x = 1; v.y = 2; v.z = 3;
	
	cout<<v<<endl;
	
	v0.x = 54;
	
	cout<<v0<<endl;
	
	v0 = v;
	
	cout<<v0<<endl;
	
	return 0;
}
