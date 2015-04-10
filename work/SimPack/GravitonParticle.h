#ifndef GRAVITON_PARTICLE_H
#define GRAVITON_PARTICLE_H

#include "InteractingParticle.h"
#include <stdlib.h>
#include <cmath>

class GravitonParticle : public InteractingParticle {
	public:
   		GravitonParticle(ParticlePlayground* parPlay, double fStr)
    	: InteractingParticle(rand() % 1000 + 25, rand() % 1000 + 25,
          						40, 40, 0, 0, parPlay), fieldStrength(fStr) { }
    	virtual ~GravitonParticle() {}
	private:
 		void interact();
 		double fieldStrength;
};
#endif