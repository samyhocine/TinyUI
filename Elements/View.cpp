#include "View.h"

View::View() : Widget()
{
}

View::View(uint16_t x, uint16_t y, uint16_t w, uint16_t h) :
  Widget(x, y, w, h, nullptr)
{
}
