#ifndef MOVEABLE_H
#define MOVEABLE_H

#include "Position.h"

class Moveable
{
  public:
    Moveable();

    virtual void setPosition(uint16_t x, uint16_t y);
    virtual void setPosition(Position position);

    virtual void move(uint16_t x, uint16_t y);
    virtual void move(Position vect);

    uint16_t getXPosition();
    uint16_t getYPosition();

    Position getPosition();

  private:
    Position m_position;
};

#endif //MOVEABLE_H
