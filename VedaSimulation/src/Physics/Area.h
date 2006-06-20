#ifndef AREA_H_
#define AREA_H_


#include <string>

#include "../Geometry/Grid.h"

#include "../Packing/Archive.h"

#include "Particle.h"

using namespace std;

using namespace Packing;

using namespace Geometry;

using namespace std;

namespace Physics
{

template<class TPhys, class TMath>
class Area
{
	Grid<TMath> m_grid;
	Particle<TPhys, TMath> m_particle;
	Particle<TPhys, TMath> m_ethalon;
	
	string info;
public:
	Area():
		m_particle(5, 5, 5), m_ethalon(7, 7, 7), info("JustConstructed")
	{ }
	virtual ~Area() { }
	
	void initTest()
	{
		m_particle = Point<TMath>(1, 1);
		m_ethalon = Point<TMath>(4, 5);
	}
	
	template<class TArchive>
	void linkArchive(TArchive & ar, const int v=0)
	{
		ar & nvp("particle", m_particle)
		   & nvp("ethalon", m_ethalon);
		ar & nvp("info", info);
		ar & nvp("grid", m_grid);
	}
};

}

#endif /*AREA_H_*/
