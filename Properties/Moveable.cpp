#include "Moveable.h"

Moveable::Moveable()
{
  setPosition(0, 0);
}

void Moveable::setPosition(uint16_t x, uint16_t y)
{
  m_position.x = x;
  m_position.y = y;
}

void Moveable::setPosition(Position position)
{
  m_position = position;
}

void Moveable::move(uint16_t x, uint16_t y)
{
  m_position.x += x;
  m_position.y += y;
}

void Moveable::move(Position vect)
{
  m_position.x += vect.x;
  m_position.y += vect.y;
}

uint16_t Moveable::getXPosition()
{
  return m_position.x;
}

uint16_t Moveable::getYPosition()
{
  return m_position.y;
}

Position Moveable::getPosition()
{
  return m_position;
}
