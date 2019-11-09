#include "Box.h"
#include "Widget.h"

Box::Box()
{
  setPosition(0, 0);
  setSize(0, 0);
  setColor(0, 0, 0);
  m_parent = nullptr;
}

Box::Box(uint16_t x, uint16_t y, uint16_t w, uint16_t h, Widget *parent)
{
  setPosition(parent->getPosition());
  move(x, y);
  setPosition(x, y);
  setSize(w, h);
  setColor(0, 0, 0);
  m_parent = parent;
}

Box::Box(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint8_t r, uint8_t g, uint8_t b, Widget *parent)
{
  setPosition(parent->getPosition());
  move(x, y);
  setSize(w, h);
  setColor(r, g, b);
  m_parent = parent;
}

Box::Box(Position position, Size size, Widget *parent)
{
  setPosition(parent->getPosition());
  move(position.x, position.y);
  setSize(size);
  setColor(0, 0, 0);
  m_parent = parent;
}

Box::Box(Position position, Size size, Color color, Widget *parent)
{
  setPosition(parent->getPosition());
  move(position.x, position.y);
  setSize(size);
  setColor(color);
  m_parent = parent;
}

void Box::setParent(Widget *parent)
{
  m_parent = parent;
}

Widget* Box::getParent()
{
  return m_parent;
}
