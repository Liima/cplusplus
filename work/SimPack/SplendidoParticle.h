#ifndef SPLENDIDO_PARTICLE_H
#define SPLENDIDO_PARTICLE_H

#include "InteractingParticle.h"
#include <stdlib.h>

class SplendidoParticle : public InteractingParticle
{
public:
    SplendidoParticle(ParticlePlayground* parPlay)
          : InteractingParticle(rand() % 500, rand() % 500,
          						10, 10,
          						(rand() % 40) - 20, (rand() % 40) - 20,
          						parPlay), m_isHappy(true) { };
    virtual ~SplendidoParticle() {};
private:
 bool m_isHappy;
 void interact();
};

#endif