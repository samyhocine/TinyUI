#include <unwind-cxx.h>
#include <ArduinoSTL.h>
#include <system_configuration.h>

#include <TinyUI.h>

volatile char weekendar_txt[TXT_SIZE] = "LMMJVSD\0";

volatile uint8_t cfg = 0;
volatile uint8_t batt_lvl = 25;
volatile uint8_t weekendar_sel_0 = 0;

void foo()
{
  cfg = 1 - cfg;
}

volatile InterfaceManager *interface_manager;
volatile View *view;
volatile Button *button_0;
volatile ProgressBar *progress_bar_0;
volatile Weekendar *weekendar_0;

void setup() {
  
  interface_manager = new InterfaceManager();
  view = new View(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
  button_0 = new Button(30, 80, 40, 20, (char *) "Launch", foo, view);
  progress_bar_0 = new ProgressBar(SCREEN_WIDTH/2, 25, 50, 20, 0, 127, 0, &batt_lvl, view);
  weekendar_0 = new Weekendar(150, 80, 100, 20, weekendar_txt, 125, 125, 125, &weekendar_sel_0, 0, 50, 200, view);

  view->setVisible();
  button_0->setColor(255, 10, 10);

  interface_manager->addView(view);
  interface_manager->addButton(button_0);
  interface_manager->addProgressBar(progress_bar_0);
  interface_manager->addWidget(weekendar_0);
  interface_manager->display();
}

void loop() {

    if(interface_manager->manageEvents())
      interface_manager->display();

    if (cfg)
    {
      batt_lvl = 50;
      button_0->setColor(10, 255, 10);
    }
    else
    {
        batt_lvl = 20;
        button_0->setColor(255, 10, 10);
    }

}
