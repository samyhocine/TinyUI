#ifndef INTERFACE_MANAGER_H
#define INTERFACE_MANAGER_H

#include <vector>

#include "../Elements/Box.h"
#include "../Elements/TextBox.h"
#include "../Elements/Button.h"
#include "../Elements/ProgressBar.h"
#include "../Elements/Widget.h"
#include "../Elements/View.h"

#include "../Widgets/Weekendar.h"

#include "../Painter/Painter.h"

#include "Screen.h"

class InterfaceManager
{
  public:
    InterfaceManager();
    ~InterfaceManager();

    void addView(View *view);
    void addButton(Button *button);
    void addProgressBar(ProgressBar *progress_bar);
    void addWidget(Widget *widget);

    bool manageEvents();

    void displayButtons();
    void displayProgressBars();
    void displayWidgets();
    void display();

  private:
    Screen *m_screen;

    std::vector<View *> m_view;
    std::vector<Button *> m_button;
    std::vector<ProgressBar *> m_progress_bar;
    std::vector<Widget *> m_widget;

    Position m_last_pointer;
};

#endif //INTERFACE_MANAGER_H
