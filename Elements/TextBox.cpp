#include "TextBox.h"
#include "Widget.h"

TextBox::TextBox() : Box()
{
  setText((char *) " ");
  setTextColor(0, 0, 0);
}

TextBox::TextBox(uint16_t x, uint16_t y, uint16_t w, uint16_t h, char txt[TXT_SIZE], Widget *parent) :
  Box(x, y, w, h, parent)
{
  setText(txt);
  setColor(0, 0, 0);
  setTextColor(255, 255, 255);
}

TextBox::TextBox(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint8_t r, uint8_t g, uint8_t b, char txt[TXT_SIZE], uint8_t txt_r, uint8_t txt_g, uint8_t txt_b, Widget *parent = nullptr) :
  Box(x, y, w, h, r, g, b, parent)
{
  setText(txt);
  setTextColor(txt_r, txt_g, txt_b);
}

TextBox::TextBox(Position position, Size size, char txt[TXT_SIZE], Widget *parent) :
  Box(position, size, parent)
{
  setText(txt);
  setColor(0, 0, 0);
  setTextColor(255, 255, 255);
}

TextBox::TextBox(Position position, Size size, Color color, char txt[TXT_SIZE], Color txt_color, Widget *parent) :
  Box(position, size, color, parent)
{
  setText(txt);
  setTextColor(txt_color);
}

void TextBox::setText(char txt[TXT_SIZE])
{
  for(uint8_t i = 0; i < TXT_SIZE; i++)
    m_txt[i] = txt[i];
}

char* TextBox::getText()
{
  return m_txt;
}

void TextBox::setTextColor(uint8_t r, uint8_t g, uint8_t b)
{
  m_txt_color.r = r;
  m_txt_color.g = g;
  m_txt_color.b = b;
}

void TextBox::setTextColor(Color color)
{
  m_txt_color = color;
}

uint8_t TextBox::getTextRColor()
{
  return m_txt_color.r;
}

uint8_t TextBox::getTextGColor()
{
  return m_txt_color.g;
}

uint8_t TextBox::getTextBColor()
{
  return m_txt_color.b;
}

Color TextBox::getTextColor()
{
  return m_txt_color;
}
