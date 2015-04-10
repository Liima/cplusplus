#include "SplendidoParticle.h"

void SplendidoParticle::interact(){
  m_isHappy = true;
  ParticleBase tp(ParticleBase::theoryParticle());
  ParticleBase* closest(&tp);
  for (vector<ParticleBase*>::const_iterator it = (*InteractingParticle::m_particles).begin(); 
        it!=(*InteractingParticle::m_particles).end(); it++) {
    if( this->distance(*it) <= this->distance(closest) && (*it)!=this)
      	closest = *it;   }
  double xDiff((*closest).getX()-this->getX());
  double yDiff((*closest).getY()-this->getY());
  if(this->distance(closest)<=50 && xDiff*this->getVX()+yDiff*this->getVY()>0){
  	setVX(-1*getVX());
    setVY(-1*getVY());
    m_isHappy = false;}
  m_isHappy ? color.setRGB(255,0,0):color.setRGB(0,0,255);
}