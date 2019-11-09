#ifndef PAINTER_H
#define PAINTER_H

#include "../Screen/Screen.h"
#include "../Elements/Box.h"
#include "../Elements/TextBox.h"
#include "../Elements/Button.h"
#include "../Elements/ProgressBar.h"

namespace Painter
{
  void drawButton(Screen *screen, Button *button);
  void drawProgressBar(Screen *screen, ProgressBar *progress_bar);
}

#endif //PAINTER_H
