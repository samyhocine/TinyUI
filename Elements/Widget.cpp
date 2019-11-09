#include "Widget.h"

Widget::Widget()
{
  m_parent = nullptr;
  setVisible(false);
  setPosition(0, 0);
  setSize(0, 0);
}

Widget::Widget(uint16_t x, uint16_t y, uint16_t w, uint16_t h, Widget *parent)
{
  m_parent = parent;
  setVisible(false);

  if (parent != nullptr)
  {
    setPosition(parent->getPosition());
    setSize(parent->getSize());
  }
  else
  {
    setPosition(0, 0);
    setSize(0, 0);
  }
}

Widget::Widget(Position position, Size size, Widget *parent)
{
  m_parent = parent;
  setVisible(false);

  if (parent != nullptr)
  {
    setPosition(parent->getPosition());
    setSize(parent->getSize());
  }
  else
  {
    setPosition(0, 0);
    setSize(0, 0);
  }
}

void Widget::setVisible(bool visible)
{
  m_visible = visible;
}

void Widget::hide()
{
  m_visible = false;
}

bool Widget::isVisible()
{
  return m_visible;
}

void Widget::setParent(Widget *parent)
{
  m_parent = parent;
}

Widget* Widget::getParent()
{
  return m_parent;
}

bool Widget::manageEvents(Position pointer)
{
  return false;
}

void Widget::display(Screen *screen)
{

}
