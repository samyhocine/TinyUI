#include "InterfaceManager.h"

InterfaceManager::InterfaceManager()
{
  m_screen = new Screen();
}

InterfaceManager::~InterfaceManager()
{
}

void InterfaceManager::addView(View *view)
{
  m_view.push_back(view);
}

void InterfaceManager::addButton(Button *button)
{
  m_button.push_back(button);
}

void InterfaceManager::addProgressBar(ProgressBar *progress_bar)
{
  m_progress_bar.push_back(progress_bar);
}

void InterfaceManager::addWidget(Widget *widget)
{
  m_widget.push_back(widget);
}

void InterfaceManager::display()
{
  m_screen->clear();

  displayButtons();
  displayProgressBars();
  displayWidgets();

  m_screen->refresh();
}

bool InterfaceManager::manageEvents()
{
  bool event_occured = false;
  Position pointer = m_screen->getPointer();

  if ((m_last_pointer.x == pointer.x) && (m_last_pointer.y == pointer.y))
    return event_occured;

  for (uint16_t i = 0; i < m_button.size(); i++)
  {
    if (m_button[i]->getParent()->isVisible())
    {
      if (m_button[i]->isPointerOver(pointer.x, pointer.y))
      {
        m_button[i]->callback();
        event_occured = true;
      }
    }
  }

  for (uint16_t i = 0; i < m_widget.size(); i++)
    if (m_widget[i]->getParent()->isVisible())
      if(m_widget[i]->manageEvents(pointer))
        event_occured = true;

  m_last_pointer = pointer;

  return event_occured;
}

void InterfaceManager::displayButtons()
{
  for (uint16_t i = 0; i < m_button.size(); i++)
    if (m_button[i]->getParent()->isVisible())
      Painter::drawButton(m_screen, m_button[i]);
}

void InterfaceManager::displayProgressBars()
{
  for (uint16_t i = 0; i < m_progress_bar.size(); i++)
  {
    if (m_progress_bar[i]->getParent()->isVisible())
    {
      m_progress_bar[i]->update();
      Painter::drawProgressBar(m_screen, m_progress_bar[i]);
    }
  }
}

void InterfaceManager::displayWidgets()
{
  for (uint16_t i = 0; i < m_widget.size(); i++)
    if (m_widget[i]->getParent()->isVisible())
      m_widget[i]->display(m_screen);
}
