#ifndef AREA_H_
#define AREA_H_


#include <string>

#include "../Geometry/Grid.h"

#include "../Packing/Archive.h"
#include "../Packing/OArchive.h"

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
	
	string name;
public:
	Area():
		m_particle(5, 5, 5), m_ethalon(7, 7, 7), name("MegaArea")
	{ }
	virtual ~Area() { }
	
	template<class TArchive>
	void linkArchive(TArchive & ar)
	{
		ar & m_particle & m_ethalon;
		ar & name;
	}
};

}

#endif /*AREA_H_*/
