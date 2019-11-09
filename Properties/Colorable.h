#ifndef COLORABLE_H
#define COLORABLE_H

#include "Color.h"

class Colorable
{
  public:
    Colorable();

    virtual void setColor(uint8_t r, uint8_t g, uint8_t b);
    virtual void setColor(Color color);

    uint8_t getRColor();
    uint8_t getGColor();
    uint8_t getBColor();

    Color getColor();

    void  invertColor();
    Color invertColor(uint8_t r, uint8_t g, uint8_t b);
    Color invertColor(Color color);

  private:
    Color m_color;
};

#endif //COLORABLE_H
