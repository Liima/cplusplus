#ifndef ROGUE_PLAYGROUND_H
#define ROGUE_PLAYGROUND_H

#include "ParticlePlayground.h"
#include "InteractingParticle.h"
#include <iostream>


class RoguePlayground : public ParticlePlayground
{
public:
	RoguePlayground() : ParticlePlayground() {};
  	virtual ~RoguePlayground(){};
 
  	virtual void tick(long t){
  		(rand()%320 < 5 && switchParticle()); 
  		ParticlePlayground::tick(t);
  	}
 private:
 	bool switchParticle(){
 			std::cout << "switching" <<std::endl;
 			ParticleBase* rogueCell(getParticles()->at(rand()%getParticles()->size()));
  			getParticles()->at(rand()%getParticles()->size()) = new  ParticleBase(rogueCell->getX(), rogueCell->getY(), rogueCell->getW(),
  			 rogueCell->getH(), rogueCell->getVX(), rogueCell->getVY());
  			return true;
}
};

#endif