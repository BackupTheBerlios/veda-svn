#include <iostream>
#include <sstream>
#include <string>

#include <tinyxml/tinyxml.h>

#include "Log.h"

#include "Geometry/Vector.h"
#include "Geometry/Polygon.h"
#include "Geometry/Grid.h"

#include "Packing/OArchive.h"
#include "Packing/IArchive.h"
#include "Packing/Archive.h"

#include "Packing/OXmlArchive.h"
#include "Packing/IXmlArchive.h"

#include "Physics/Particle.h"
#include "Physics/Area.h"

using namespace std;

using namespace Geometry;
using namespace Physics;
using namespace Packing;

int main(int argc, char** argv)
{
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
	coar.close();
	cout<<endl;
	
	Area<double, double> area;
	
	OArchive coar2(cout);
	
	cout<<"Test area archiving"<<endl;
	
	coar2<<area;
	coar2.close();
	cout<<endl;
	
	return 0;
}
