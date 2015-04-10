#ifndef COLOR_H
#define COLOR_H


class Color   {
  public:
    Color(int r, int g, int b, int a) {        //Color constructor for HSL
      setRGB(r,g,b);
      setAlpha(a);
      updateHSL();}

    Color(float h, float s, float l, float a) { //Color constructor for HSL
      setHSL(h,s,l);
      setAlpha(255*a);
      updateRGB();}
    virtual ~Color() {};
    const float red(){return m_R/255.0;}
    const float green(){return m_G/255.0;}
    const float blue(){return m_B/255.0;}
    const float alpha(){return m_A/255.0;}
    const float hue(){return m_H;}
    const float sat(){return m_S;}
    const float light(){return m_L;}
    void setRGB(int r, int g, int b);
    void setRGB(float r, float g, float b);
    void setHSL(float h, float s, float l);
    void setAlpha(int a){m_A=a<0?0:a>255?255:a;}
   
  private:
    int m_R, m_G, m_B, m_A;
    float m_H, m_S, m_L;
    void updateRGB(), updateHSL();
};

#endif