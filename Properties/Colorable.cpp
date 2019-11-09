#include "Colorable.h"

Colorable::Colorable()
{
  setColor(0, 0, 0);
}

void Colorable::setColor(uint8_t r, uint8_t g, uint8_t b)
{
  m_color.r = r;
  m_color.g = g;
  m_color.b = b;
}

void Colorable::setColor(Color color)
{
  m_color = color;
}

uint8_t Colorable::getRColor()
{
  return m_color.r;
}

uint8_t Colorable::getGColor()
{
  return m_color.g;
}

uint8_t Colorable::getBColor()
{
  return m_color.b;
}

Color Colorable::getColor()
{
  return m_color;
}

void Colorable::invertColor()
{
  m_color.r = 0xFF - m_color.r;
  m_color.g = 0xFF - m_color.g;
  m_color.b = 0xFF - m_color.b;
}

Color Colorable::invertColor(uint8_t r, uint8_t g, uint8_t b)
{
  Color _color;

  _color.r = 0xFF - r;
  _color.g = 0xFF - g;
  _color.b = 0xFF - b;

  return _color;
}

Color Colorable::invertColor(Color color)
{
  Color _color;

  _color.r = 0xFF - color.r;
  _color.g = 0xFF - color.g;
  _color.b = 0xFF - color.b;

  return _color;
}
