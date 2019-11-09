#ifndef BUTTON_H
#define BUTTON_H

#include "TextBox.h"

class Widget;

class Button : public TextBox
{
  public:
    Button();
    Button(uint16_t x, uint16_t y, uint16_t w, uint16_t h, char txt[TXT_SIZE], void (*callback)(), Widget *parent);
    Button(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint8_t r, uint8_t g, uint8_t b,
      char txt[TXT_SIZE], uint8_t txt_r, uint8_t txt_g, uint8_t txt_b, void (*callback)(), Widget *parent);
    Button(Position position, Size size, char txt[TXT_SIZE], void (*callback)(), Widget *parent);
    Button(Position position, Size size, Color color, char txt[TXT_SIZE], Color text_color, void (*callback)(), Widget *parent);

    bool isPointerOver(uint16_t x, uint16_t y);
    bool isPointerOver(Position pointer);
    void callback();

  private:
    void (*m_callback)();
};

#endif //BUTTON_H
