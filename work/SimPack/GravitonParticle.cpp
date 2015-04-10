#include "GravitonParticle.h"
#include <iostream>

void GravitonParticle::interact(){

	for (vector<ParticleBase*>::const_iterator it = (*InteractingParticle::m_particles).begin(); 
        it!=(*InteractingParticle::m_particles).end(); it++) {
		double gravity((*it) != this ? fieldStrength/(distance(*it)*distance(*it)):0);
		
		(**it).setVX((**it).getVX()-gravity*cos(angle(*it)));
		(**it).setVY((**it).getVY()-gravity*sin(angle(*it)));
    
    }

}