#include "Resizeable.h"

Resizeable::Resizeable()
{
  setSize(0, 0);
}

void Resizeable::setSize(uint16_t w, uint16_t h)
{
  m_size.w = w;
  m_size.h = h;
}

void Resizeable::setSize(Size size)
{
  m_size = size;
}

uint16_t Resizeable::getWidth()
{
  return m_size.w;
}

uint16_t Resizeable::getHeight()
{
  return m_size.h;
}

Size Resizeable::getSize()
{
  return m_size;
}
