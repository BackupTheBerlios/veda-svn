#include <iostream>
#include <sstream>
#include <string>

#include <tinyxml/tinyxml.h>

#include "Log.hpp"

#include "Geometry/Point.hpp"
#include "Geometry/Polygon.hpp"
#include "Geometry/Grid.hpp"

#include "Packing/OArchive.hpp"
#include "Packing/IArchive.hpp"
#include "Packing/Archive.hpp"

#include "Packing/OXmlArchive.hpp"
#include "Packing/IXmlArchive.hpp"

#include "Physics/Particle.hpp"
#include "Physics/Area.hpp"

using namespace std;

using namespace Geometry;
using namespace Physics;
using namespace Packing;

int main(int argc, char** argv)
{
	/* test serialization */
	
	Area<double, double> area;
	
	OArchive coar(cout);
	
	cout<<"Test area archiving"<<endl;
	
	coar.open();
	coar & area;
	coar.close();
	
	cout<<endl;
	
	area.initTest();
	
	int n = 3, m = 5;
	
	/*
	ofstream ofs("test.xml");
	OXmlArchive oxml(ofs);
	
	oxml.open();
	oxml & nvp("area", area);
	oxml & nvp("n", n) & m;
	oxml.close();
	
	ofs.close();
	*/
	
	Area<double, double> iarea;
	
	/*
	ifstream ifs("test.xml");
	IXmlArchive ixml(ifs);
	
	ixml.open();
	ixml & nvp("area", iarea);
	ixml.close();
	
	ifs.close();
	*/
	
	coar.open();
	coar & nvp("iarea", iarea);
	coar.close();
	
	/* polygon out */
	
	Polygon poly;
	
	OXmlArchive oxml2;
	
	oxml2.open();
	oxml2 & nvp("poly", poly);
	oxml2.close();
	
	return 0;
}
