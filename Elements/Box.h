#ifndef BOX_H
#define BOX_H

#include "../Properties/Moveable.h"
#include "../Properties/Resizeable.h"
#include "../Properties/Colorable.h"

class Widget;

class Box : public Moveable, public Resizeable, public Colorable
{
  public:
    Box();
    Box(uint16_t x, uint16_t y, uint16_t w, uint16_t h, Widget *parent);
    Box(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint8_t r, uint8_t g, uint8_t b, Widget *parent);
    Box(Position position, Size size, Widget *parent);
    Box(Position position, Size size, Color color, Widget *parent);

    void setParent(Widget *parent);
    Widget* getParent();

  private:
    Widget *m_parent;
};

#endif //BOX_H
