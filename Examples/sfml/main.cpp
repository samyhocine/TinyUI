#include "InterfaceManager.h"

volatile uint8_t cfg = 0;

void foo()
{
  cfg = 1 - cfg;
}

int main(void)
{
  uint8_t batt_lvl = 25, weekendar_sel_0 = 0;
  char weekendar_txt[TXT_SIZE] = "LMMJVSD\0";

  InterfaceManager interface_manager;

  View view(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

  Button button_0(30, 80, 40, 20, (char *) "Launch", foo, &view);
  ProgressBar progress_bar_0(SCREEN_WIDTH/2, 25, 50, 20, 0, 127, 0, &batt_lvl, &view);
  Weekendar weekendar_0(80, 80, 100, 20, weekendar_txt, 25, 25, 25, &weekendar_sel_0, 0, 50, 200, &view);

  view.setVisible();
  button_0.setColor(255, 10, 10);

  interface_manager.addView(&view);
  interface_manager.addButton(&button_0);
  interface_manager.addProgressBar(&progress_bar_0);
  interface_manager.addWidget(&weekendar_0);
  interface_manager.display();

  while(1)
  {
    if(interface_manager.manageEvents())
      interface_manager.display();

    if (cfg)
    {
      button_0.setColor(10, 255, 10);
      batt_lvl = 50;
    }
    else
    {
        batt_lvl = 20;
        button_0.setColor(255, 10, 10);
    }
  }

  return EXIT_SUCCESS;
}
