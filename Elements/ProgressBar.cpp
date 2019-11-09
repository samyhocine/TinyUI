#include "ProgressBar.h"
#include "Widget.h"

ProgressBar::ProgressBar() : TextBox()
{
  m_val = nullptr;

  for (uint8_t i = 0; i < VAL_WIDTH; i++)
    m_txt[i] = '0';
}

ProgressBar::ProgressBar(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint8_t r, uint8_t g, uint8_t b, uint8_t *val, Widget *parent) :
  TextBox(x, y, w, h, (char *) "", parent)
{
  m_val = val;
  setColor(r, g, b);
  setTextColor(invertColor(r, g, b));
  update();
}

ProgressBar::ProgressBar(Position position, Size size, Color color, uint8_t *val, Widget *parent) :
  TextBox(position, size, (char *) "", parent)
{
  m_val = val;
  setColor(color);
  setTextColor(invertColor(color));
  update();
}

void ProgressBar::setVal(uint8_t *val)
{
  m_val = val;
  update();
}

void ProgressBar::update()
{
  sprintf(m_txt, "%d", *m_val);
  setText(m_txt);
}
