#ifndef PARTICLE_H_
#define PARTICLE_H_

#include <string>

#include "Geometry/Point.hpp"
#include "Packing/Archive.hpp"

using namespace std;

using namespace Geometry;
using namespace Packing;

namespace Physics
{

template<class TPhys, class TMath>
class Particle
{
	
public:
	TPhys sxx, syy, szz;
	TPhys omg;
	TPhys m;
	
	TMath x, y, z;
	
	string name;
	
public:
	Particle(double n_x, double n_y, double n_z):
		x(n_x), y(n_y), z(n_z), name("Particle"),
		sxx(123), syy(456), szz(789)
	{ 
		
	}
	
	virtual ~Particle() { }
	
	Particle<TPhys, TMath> & operator=(const Point<TMath> & rhs)
	{
		x = rhs.x; y = rhs.y;
		return *this;
	}
	
	template<class TArchive>
	void linkArchive(TArchive & ar, const int v)
	{
		ar & nvp("name", name)
		   & nvp("x", x)
		   & nvp("y", y)
		   & nvp("z", z);
	}
	
};

}

#endif /*PARTICLE_H_*/
