#ifndef PROGRESSBAR_H
#define PROGRESSBAR_H

#include "TextBox.h"

class Widget;

#define VAL_WIDTH 4

class ProgressBar : public TextBox
{
  public:
    ProgressBar();
    ProgressBar(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint8_t r, uint8_t g, uint8_t b, uint8_t *val, Widget *parent);
    ProgressBar(Position position, Size size, Color color, uint8_t *val, Widget *parent);

    void setVal(uint8_t *val);
    void update();

  private:
    char m_txt[VAL_WIDTH];
    uint8_t *m_val;
};

#endif //PROGRESSBAR_H
