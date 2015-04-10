#ifndef RAINBOW_PARTICLE_H
#define RAINBOW_PARTICLE_H

#include "InteractingParticle.h"
#include "Color.h"
#include <gtkmm/drawingarea.h>
#include <vector>
#include <stdlib.h>

class RainbowParticle : public InteractingParticle
{
public:
    RainbowParticle(ParticlePlayground* parPlay)
          : InteractingParticle(rand() % 500, rand() % 500,
          						12, 
          						12,
          						(rand() % 60) - 30,
          						(rand() % 60) - 30,
          						parPlay),  
          cV(fmod((float)rand(),0.21f)) 
          { color = Color(0.8f,1.0f,0.5f,0.99f);};
    virtual ~RainbowParticle() {};
private:
 float cV;
 void interact(){color.setHSL(color.hue()+cV,color.sat(),color.light());}
};

#endif