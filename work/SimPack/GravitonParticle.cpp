#include "GravitonParticle.h"
#include <iostream>
#include <algorithm>

void GravitonParticle::interact(){

vector<ParticleBase*>::iterator eaten = find((*m_particles).begin(), (*m_particles).end(), this);

	for (vector<ParticleBase*>::iterator it = (*InteractingParticle::m_particles).begin(); 
        it!=(*InteractingParticle::m_particles).end(); it++) {
		
		double gravity((*it) != this ? fieldStrength/(distance(*it)*distance(*it)):0);
		
		(**it).setVX((**it).getVX()-gravity*cos(angle(*it)));
		(**it).setVY((**it).getVY()-gravity*sin(angle(*it)));
    	
    	if((*it)!=this && 2*distance(*it)<getW()) {
            eaten = it;
    	}
    }
if((*eaten)!=this){
   eatParticle(eaten);
}

}
void GravitonParticle::eatParticle(vector<ParticleBase*>::iterator eaten){

    setW(1+getW());
    setH(1+getH());
    fieldStrength = 1.1*fieldStrength;
    m_particles->erase(eaten);
}