#ifndef INTERACTING_PARTICLE_H
#define INTERACTING_PARTICLE_H

#include "ParticleBase.h"
#include "ParticlePlayground.h"
#include <vector>

class InteractingParticle : public ParticleBase
{
public:
    InteractingParticle(double x, double y, double w, double h, double vX, double vY, ParticlePlayground* parPlay)
          : ParticleBase(x, y, w, h,vX,vY), m_particles((*parPlay).getParticles()) { };
    virtual ~InteractingParticle(){};
    virtual void tick(long t){
    	interact();
    	ParticleBase::tick(t);
    };
protected:
 const vector<ParticleBase*>* m_particles;
private:
  virtual void interact(){};
};

#endif