#ifndef PARTICLE_H_
#define PARTICLE_H_

namespace Physics
{

template<class TReal>
class Particle
{
	TReal sxx, syy, szz;
	TReal omg;
public:
	Particle() { }
	virtual ~Particle() { }
};

}

#endif /*PARTICLE_H_*/
