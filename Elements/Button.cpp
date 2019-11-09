#include "Button.h"
#include "Widget.h"

Button::Button() : TextBox()
{
  m_callback = nullptr;
}

Button::Button(uint16_t x, uint16_t y, uint16_t w, uint16_t h, char txt[TXT_SIZE], void (*callback)(), Widget *parent) :
  TextBox(x, y, w, h, txt, parent)
{
  m_callback = callback;
}

Button::Button(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint8_t r, uint8_t g, uint8_t b,
               char txt[TXT_SIZE], uint8_t txt_r, uint8_t txt_g, uint8_t txt_b, void (*callback)(), Widget *parent) :
  TextBox(x, y, w, h, txt, parent)
{
  m_callback = callback;
}

Button::Button(Position position, Size size, Color color, char txt[TXT_SIZE], Color txt_color, void (*callback)(), Widget *parent) :
  TextBox(position, size, color, txt, txt_color, parent)
{
  m_callback = callback;
}

Button::Button(Position position, Size size, char txt[TXT_SIZE], void (*callback)(), Widget *parent) :
  TextBox(position, size, txt, parent)
{
  m_callback = callback;
}

bool Button::isPointerOver(uint16_t x, uint16_t y)
{
  bool is_over = false;

  if ((x >= getXPosition()) && (x <= (getXPosition() + getWidth())))
    if ((y >= getYPosition()) && (y <= (getYPosition() + getHeight())))
      is_over = true;

  return is_over;
}

bool Button::isPointerOver(Position pointer)
{
  return isPointerOver(pointer.x, pointer.y);
}

void Button::callback()
{
  if(m_callback != nullptr)
    (*m_callback)();
}
