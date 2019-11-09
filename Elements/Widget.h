#ifndef WIDGET_H
#define WIDGET_H

#include "../Properties/Moveable.h"
#include "../Properties/Resizeable.h"
#include "../Screen/Screen.h"
#include "../Painter/Painter.h"

class Box;
class TextBox;
class Button;
class ProgressBar;

class Widget : public Moveable, public Resizeable
{
  public:
    Widget();
    Widget(uint16_t x, uint16_t y, uint16_t w, uint16_t h, Widget *parent);
    Widget(Position position, Size size, Widget *parent);

    void setVisible(bool visible = true);
    void hide();
    bool isVisible();

    virtual void display(Screen *screen);
    virtual bool manageEvents(Position pointer);

    void setParent(Widget *parent);
    Widget* getParent();

  private:
    Widget *m_parent;
    bool m_visible;
};

#endif //WIDGET_H
