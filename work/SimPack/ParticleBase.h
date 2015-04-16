#ifndef PARTICLE_BASE_H
#define PARTICLE_BASE_H

#include <gtkmm/drawingarea.h>
#include "TimeKeeper.h"
#include "Color.h"

class ParticleBase : public TimeKeeper
{
public:
    // units for x,w,w,h should be meteres...
    ParticleBase(double x, double y, double w, double h, double vX, double vY)
      : m_x(x), m_y(y), m_w(w), m_h(h), m_vX(vX), m_vY(vY), color(Color(24,24,24,240)) {};
    
    virtual ~ParticleBase() {};
    
    double getX() const { return m_x; }
    double getY() const { return m_y; }
    double getW() const { return m_w; }
    double getH() const { return m_h; }
    double getVX() const{ return m_vX; }
    double getVY() const{ return m_vY; }
    Color getColor() const { return color; }

    void setColor(Color c){color=c;}
    void setX(double x) { m_x = x; }
    void setY(double y) { m_y = y; }
    void setW(double w) { m_w = w; }
    void setH(double h) { m_h = h; }
    void setVX(double vx) { m_vX = vx; }
    void setVY(double vy) { m_vY = vy; }

    virtual void draw(int win_height, int win_width, 
      const Cairo::RefPtr<Cairo::Context>& cr);
    virtual void tick(long t);

    double distance(const ParticleBase* pb) const {
      double dX(pb->getX()-getX()), dY(pb->getY()-getY());
      return std::sqrt(dX*dX+dY*dY);
    }
    double angle(const ParticleBase* pb) const {
      if((pb) == this){return 0;}
      double dX(pb->getX()-getX()), dY(pb->getY()-getY());
      return dX==0.0 && dY>0.0 ? 0.0 :
             dX==0.0 && dY<0.0 ? 1.0 :
             dY==0.0 && dX>0.0 ? 0.5 :
             dY==0.0 && dX<0.0 ? 1.5 : atan2(dY,dX);
    }
    static ParticleBase theoryParticle(){return ParticleBase(999999,999999,0,0,0,0);}

protected:
  Color color;
private:
  double m_vX;
  double m_vY;
  double m_x;
  double m_y;
  double m_w;
  double m_h;
};

#endif