#ifndef VIEW_H
#define VIEW_H

#include "Widget.h"

class View : public Widget
{
  public:
    View();
    View(uint16_t x, uint16_t y, uint16_t w, uint16_t h);
};

#endif //VIEW_H
