#include "Color.h"
#include <cmath>
#include <stdlib.h>

void Color::updateHSL()
{
	float fr(m_R/255.0),
		  fg(m_G/255.0),
		  fb(m_B/255.0),
		  max(fmax(fr,fmax(fg,fb))),
		  min(fmin(fr,fmin(fg,fb))),
		  delta(max-min);
	if(delta==0)
		m_H = 0;
	else if (fr == max)
		m_H = fmod((fg-fb)/(delta),6)/3;
	else if (fg == max)
		m_H = ((fb-fr)/(delta)+2)/3;
	else if (fb == max)
		m_H = ((fr-fg)/(delta)+4)/3;
	m_L = (max+min)/2;
	m_S = delta == 0 ? 0 : delta/(1-abs(2*m_L-1));

}
void Color::updateRGB(){
	float fh(m_H), 
		  fs(m_S),
		  fl(m_L),
		  hDeg(180*fh),
		  alpha((1.0-fabs(2.0*fl-1.0))*fs), 
		  beta(alpha*(1.0-fabs(fmod(hDeg/60,2.0)-1))), 
		  mu(fl-(alpha/2.0)),
		  red(mu),
		  blue(mu), 
		  green(mu);
	if (fh>=0.0  && fh<0.33)
		{red += alpha; green += beta; blue += 0.0;}
	else if (fh>=0.33 && fh<0.66)
		{red += beta; green += alpha; blue += 0.0;}
	else if (fh>=0.66&&fh<1.0)
		{red += 0.0; green += alpha; blue += beta;}
	else if (fh>=1.0&&fh<1.33)
		{red += 0.0; green += beta; blue += alpha;}
	else if (fh>=1.33&&fh<1.66)
		{red += beta; green += 0.0; blue += alpha;}
	else
		{red += alpha; green += 0.0; blue += beta;}
	m_R = (int)floor(red*255);
	m_G = (int)floor(green*255);
	m_B = (int)floor(blue*255);	
}
void Color::setRGB(int r, int g, int b){
	m_R = r < 0   ? 0   :
		  r > 255 ? 255 :
		  r 	 		;
	m_G = g < 0   ? 0   :
		  g > 255 ? 255 :
		  g 	 		;
	m_B = b < 0   ? 0   :
		  b > 255 ? 255 :
		  b 		;
	updateHSL()			;
}
void Color::setRGB(float r, float g, float b){
	m_R = r < 0.0 ? 0.0 :
		  r > 1.0 ? 1.0 :
		  255*r 		;
	m_G = g < 0.0 ? 0.0 :
		  g > 1.0 ? 1.0 :
		  255*g 		;
	m_B = b < 0.0 ? 0.0 :
		  b > 1.0 ? 1.0 :
		  255*b 		;
	updateHSL()			;
}
void Color::setHSL(float h, float s, float l){
	m_H = fmod(fabs(h),2.0);
	m_S = s < 0.0 ? 0.0 :
		  s > 1.0 ? 1.0 :
		  s 			;
	m_L = l < 0.0 ? 0.0 :
		  l > 1.0 ? 1.0 :
		  l 			;
	updateRGB()			;
}
