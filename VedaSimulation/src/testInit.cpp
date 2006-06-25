#include <iostream>
#include <sstream>
#include <string>

#include <tinyxml/tinyxml.h>

#include "Geometry/Point.hpp"
#include "Geometry/Polygon.hpp"
#include "Geometry/Grid.hpp"

#include "Physics/Particle.hpp"

#include "Packing/OArchive.hpp"
#include "Packing/IArchive.hpp"

#include "Log.hpp"

using namespace std;

using namespace Geometry;
using namespace Physics;
using namespace Packing;

template<class TReal>
ostream & operator<<(ostream & os, Point<TReal> & v)
{
	return os<<"Vector: "<<v.x<<", "<<v.y<<", "<<v.z;
}

int main(int argc, char** argv)
{
	Log log(cout);
	
	log<<"start";
	
	for(int i=0; i<1; ++i){
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
	
	/* test serialization */
	
	Particle<double, double> particle(1, 2, 3), part(0, 0, 0);
	
	
	stringstream testStream;
	OArchive oar(testStream);
	
	oar<<particle;
	
	IArchive iar(testStream);
	
	iar>>part;
	
	cout<<"Track particle: "<<part.x<<endl;
	
	OArchive coar(cout);
	
	cout<<"Test particle archiving"<<endl;
	coar<<part;
	cout<<endl;
	
	cout<<"Test Tiny"<<endl;
	
	TiXmlDocument document("");
	
	stringstream st("<root><omg>Real Omg!</omg>Xmmmm</root>");
	
	st>>document;
	
	TiXmlElement * pElement;
	pElement = document.RootElement();
	
	cout<<">>GetText"<<endl;
	cout<<(pElement==0?"Absent":"Exists")<<endl;
	cout<<pElement->Value()<<endl;
	
	cout<<">>Out document"<<endl;
	cout<<document<<endl;
	
	log<<"Finish";
	
	return 0;
}
