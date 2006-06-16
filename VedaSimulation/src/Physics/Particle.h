#ifndef PARTICLE_H_
#define PARTICLE_H_

#include <string>

#include "../Packing/Archive.h"
#include "../Packing/OArchive.h"

using namespace std;

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
	
	template<class TArchive>
	void linkArchive(TArchive & ar)
	{
		ar & name & x & y & z;
		ar & sxx & syy & szz;
	}
};

}

#endif /*PARTICLE_H_*/
