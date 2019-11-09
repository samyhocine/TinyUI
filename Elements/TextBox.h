#ifndef TEXTBOX_H
#define TEXTBOX_H

#include "Box.h"

//Because of limited ressources :
#define TXT_SIZE 16

class Widget;

class TextBox : public Box
{
  public:
    TextBox();
    TextBox(uint16_t x, uint16_t y, uint16_t w, uint16_t h, char txt[TXT_SIZE], Widget *parent);
    TextBox(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint8_t r, uint8_t g, uint8_t b,
      char txt[TXT_SIZE], uint8_t txt_r, uint8_t txt_g, uint8_t txt_b, Widget *parent);
    TextBox(Position position, Size size, char txt[TXT_SIZE], Widget *parent);
    TextBox(Position position, Size size, Color color, char txt[TXT_SIZE], Color txt_color, Widget *parent);

    void setText(char txt[TXT_SIZE]);
    void setTextColor(uint8_t r, uint8_t g, uint8_t b);
    void setTextColor(Color color);

    uint8_t getTextRColor();
    uint8_t getTextGColor();
    uint8_t getTextBColor();
    Color getTextColor();

    char* getText();

  private:
    char m_txt[TXT_SIZE];
    Color m_txt_color;
};

#endif //TEXTBOX_H
