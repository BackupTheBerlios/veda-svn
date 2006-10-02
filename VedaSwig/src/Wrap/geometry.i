%module geometry

%{
#include "Geometry/Point.hpp"
#include "Geometry/Line.hpp"
#include "Geometry/Polygon.hpp"

#include "Packing/Archive.hpp"
#include "Packing/IXmlArchive.hpp"
#include "Packing/OXmlArchive.hpp"

using namespace Geometry;
using namespace Packing;
%}

/*
*	Geometry
*/

/* Point */

%rename(assign) Geometry::Point::operator=;

%include "Geometry/Point.hpp"

%extend Geometry::Point
{
	const char* __str__()
	{
		static char temp[256];
		sprintf(temp,"[ %g, %g ]", self->x, self->y);
		return &temp[0];
	}
};

extern Geometry::distance(const Geometry::Point&, const Geometry::Point&);

/* Line */

%rename(assign) Geometry::Line::operator=;

%include "Geometry/Line.hpp"


/* Polygon */

%rename(assign) Geometry::Polygon::operator=;
%ignore Geometry::Polygon::operator[];

%include "Geometry/Polygon.hpp"


/*
*	Archiving
*/

/* common */

%include "Packing/Archive.hpp"

%template(nvp) Packing::nvp<Geometry::Point>;
%template(nvp) Packing::nvp<Geometry::Line>;
%template(nvp) Packing::nvp<Geometry::Polygon>;

/* Data based archiving */

/* Xml archiving */

%include "Packing/XmlArchive.hpp"

%include "Packing/IXmlArchive.hpp"

%extend Packing::IXmlArchive
{
	Packing::IXmlArchive & __and__(Geometry::Point & item)
	{ return (*self) & item; }
	
	Packing::IXmlArchive & __and__(Packing::Named<Geometry::Point> & item)
	{ return (*self) & item; }
	
	Packing::IXmlArchive & __and__(Geometry::Line & item)
	{ return (*self) & item; }
	
	Packing::IXmlArchive & __and__(Packing::Named<Geometry::Line> & item)
	{ return (*self) & item; }
	
	Packing::IXmlArchive & __and__(Geometry::Polygon & item)
	{ return (*self) & item; }
	
	Packing::IXmlArchive & __and__(Packing::Named<Geometry::Polygon> & item)
	{ return (*self) & item; }
}


%include "Packing/OXmlArchive.hpp"

%extend Packing::OXmlArchive
{
	Packing::OXmlArchive & __and__(Geometry::Point & item)
	{ return (*self) & item; }
	
	Packing::OXmlArchive & __and__(Packing::Named<Geometry::Point> & item)
	{ return (*self) & item; }
	
	Packing::OXmlArchive & __and__(Geometry::Line & item)
	{ return (*self) & item; }
	
	Packing::OXmlArchive & __and__(Packing::Named<Geometry::Line> & item)
	{ return (*self) & item; }
	
	Packing::OXmlArchive & __and__(Geometry::Polygon & item)
	{ return (*self) & item; }
	
	Packing::OXmlArchive & __and__(Packing::Named<Geometry::Polygon> & item)
	{ return (*self) & item; }
}

/* end */