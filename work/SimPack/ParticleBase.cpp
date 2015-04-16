#include "ParticleBase.h"
#include "SimApp.h"

void ParticleBase::draw(int win_height, int win_width, 
  const Cairo::RefPtr<Cairo::Context>& cr)
{
  double xpix = (getX() / SimApp::getMetersPerPixel());
  double ypix = (getY() / SimApp::getMetersPerPixel());
  double wpix = (getW() / SimApp::getMetersPerPixel());
  double hpix = (getH() / SimApp::getMetersPerPixel());

  if(xpix>win_width)
   setX(SimApp::getMetersPerPixel()*(xpix-win_width));
  if(ypix>win_height)
   setY(SimApp::getMetersPerPixel()*(ypix-win_height));
  if(xpix<0)
    setX(SimApp::getMetersPerPixel()*(xpix+win_width));
  if(ypix<0)
    setY(SimApp::getMetersPerPixel()*(ypix+win_height));

  cr->save();
  cr->set_line_width(1.0);
  cr->set_source_rgba(color.red(), color.green(), color.blue(), color.alpha());
  cr->arc(xpix, ypix, wpix / 2.0, 0.0, 2.0 * M_PI);
  cr->fill_preserve();
  cr->stroke();
  cr->restore();
}

void ParticleBase::tick(long t)
{
	double deltaX = ((getVX() / SimApp::getMetersPerPixel()) * SimApp::getSecPerTick());
	double deltaY = ((getVY() / SimApp::getMetersPerPixel()) * SimApp::getSecPerTick());
	setX(getX() + deltaX);
	setY(getY() + deltaY);
}
