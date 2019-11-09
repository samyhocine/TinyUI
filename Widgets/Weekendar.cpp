#include "Weekendar.h"

Weekendar::Weekendar(uint16_t x, uint16_t y, uint16_t w, uint16_t h, char days[TXT_SIZE], uint8_t days_r, uint8_t days_g, uint8_t days_b,
  uint8_t *sel, uint8_t sel_r, uint8_t sel_g, uint8_t sel_b, Widget *parent) :
  Widget(x, y, w, h, parent)
{
  init(x, y, w, h, days, days_r, days_g, days_b, sel, sel_r, sel_g, sel_b);
}

Weekendar::Weekendar(Position position, Size size, char days[TXT_SIZE], Color days_color, uint8_t *sel, Color sel_color, Widget *parent) :
  Widget(position, size, parent)
{
  init(position.x, position.y, size.w, size.h, days, days_color.r, days_color.g, days_color.b,
    sel, sel_color.r, sel_color.g, sel_color.b);
}

void Weekendar::init(uint16_t x, uint16_t y, uint16_t w, uint16_t h, char days[TXT_SIZE], uint8_t days_r, uint8_t days_g, uint8_t days_b,
  uint8_t *sel, uint8_t sel_r, uint8_t sel_g, uint8_t sel_b)
{
  Button button;
  char c[TXT_SIZE];

  for (uint8_t i = 0; i < 7; i++)
  {
    c[0] = days[i];
    c[1] = '\0';

    button.setColor(0, 0, 0);
    button.setText(c);
    button.setTextColor(days_r, days_g, days_b);
    button.setPosition(getParent()->getPosition());
    button.move(x + i*BUTTON_WIDTH, y);
    button.setSize(BUTTON_WIDTH, BUTTON_WIDTH);
    m_button.push_back(button);
  }

  m_sel = sel;

  m_days_color.r = days_r;
  m_days_color.g = days_g;
  m_days_color.b = days_b;

  m_sel_color.r = sel_r;
  m_sel_color.g = sel_g;
  m_sel_color.b = sel_b;
}

bool Weekendar::manageEvents(Position pointer)
{
  bool event_occured = false;
  uint8_t sel = 0;

  for (uint8_t i = 0; i < m_button.size(); i++)
  {
    if (m_button[i].isPointerOver(pointer))
    {
      sel |= (1 << i);
      event_occured = true;
    }
  }

  if (event_occured)
  {
    updateSel(sel);
    updateDaysColor();
  }

  return event_occured;
}

void Weekendar::updateSel(uint8_t sel)
{
  *m_sel = *m_sel ^ sel;
}

void Weekendar::updateDaysColor()
{
  for (uint8_t i = 0; i < m_button.size(); i++)
  {
    if (*m_sel & (1 << i))
      m_button[i].setTextColor(m_sel_color);
    else
      m_button[i].setTextColor(m_days_color);
  }
}

void Weekendar::display(Screen *screen)
{
  for (uint8_t i = 0; i < m_button.size(); i++)
    Painter::drawButton(screen, &m_button[i]);
}
