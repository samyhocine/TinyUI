#ifndef WEEKENDAR_H
#define WEEKENDAR_H

#include <vector>
#include "../Elements/Widget.h"
#include "../Elements/Button.h"

#define BUTTON_WIDTH 15

class Weekendar : public Widget
{
  public:
    Weekendar(uint16_t x, uint16_t y, uint16_t w, uint16_t h, char days[TXT_SIZE], uint8_t days_r, uint8_t days_g, uint8_t days_b,
      uint8_t *sel, uint8_t sel_r, uint8_t sel_g, uint8_t sel_b, Widget *parent);
    Weekendar(Position position, Size size, char days[TXT_SIZE], Color days_color, uint8_t *sel, Color sel_color, Widget *parent);

    bool manageEvents(Position pointer);
    void display(Screen *screen);

  private:
    void init(uint16_t x, uint16_t y, uint16_t w, uint16_t h, char days[TXT_SIZE], uint8_t days_r, uint8_t days_g, uint8_t days_b,
    uint8_t *sel, uint8_t sel_r, uint8_t sel_g, uint8_t sel_b);
    void updateSel(uint8_t sel);
    void updateDaysColor();

    std::vector<Button> m_button;

    uint8_t *m_sel;
    Color m_sel_color;
    Color m_days_color;
};

#endif //WEEKENDAR_H
