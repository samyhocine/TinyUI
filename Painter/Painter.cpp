#include "Painter.h"

namespace Painter
{
  void drawButton(Screen *screen, Button *button)
  {
    screen->drawRect(button->getXPosition(), button->getYPosition(),
                     button->getWidth(), button->getHeight(),
                     button->getRColor(), button->getGColor(), button->getBColor());

    screen->drawText(button->getText(),
                     button->getXPosition() + (button->getHeight() >> 3), button->getYPosition() + (button->getHeight() >> 2),
                     button->getTextRColor(), button->getTextGColor(), button->getTextBColor());
  }

  void drawProgressBar(Screen *screen, ProgressBar *progress_bar)
  {
    screen->drawRect(progress_bar->getXPosition(), progress_bar->getYPosition(),
                     progress_bar->getWidth(), progress_bar->getHeight(),
                     0xFF - screen->getRColor(), 0xFF - screen->getGColor(), 0xFF - screen->getBColor());

    screen->drawRect(progress_bar->getXPosition() + 1, progress_bar->getYPosition() + 1,
                     progress_bar->getWidth() - 2, progress_bar->getHeight() - 2,
                     progress_bar->getRColor(), progress_bar->getGColor(), progress_bar->getBColor());

    if (progress_bar->getHeight() >= progress_bar->getWidth())
    {
      screen->drawText(progress_bar->getText(),
                       progress_bar->getXPosition() + (progress_bar->getWidth() >> 2),
                       progress_bar->getYPosition() + progress_bar->getHeight() + 5,
                       progress_bar->getTextRColor(), progress_bar->getTextGColor(), progress_bar->getTextBColor());
    }
    else
    {
      screen->drawText(progress_bar->getText(),
                       progress_bar->getXPosition() + progress_bar->getWidth() + 5,
                       progress_bar->getYPosition() + (progress_bar->getHeight() >> 2),
                       progress_bar->getTextRColor(), progress_bar->getTextGColor(), progress_bar->getTextBColor());
    }
  }
}
