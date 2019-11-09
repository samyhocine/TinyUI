#ifndef RESIZEABLE_H
#define RESIZEABLE_H

#include "Size.h"

class Resizeable
{
  public:
    Resizeable();

    virtual void setSize(uint16_t w, uint16_t h);
    virtual void setSize(Size size);

    uint16_t getWidth();
    uint16_t getHeight();

    Size getSize();

  private:
    Size m_size;
};

#endif //RESIZEABLE_H
