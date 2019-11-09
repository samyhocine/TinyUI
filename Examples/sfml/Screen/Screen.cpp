#include "Screen.h"

//The following instanciations are library dependant

Screen::Screen()
{
  m_window = new sf::RenderWindow(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "TinyUI with SFML");
  setColor(SCREEN_COLOR_R, SCREEN_COLOR_G, SCREEN_COLOR_B);
  m_font.loadFromFile("Data/LucidaSansRegular.ttf");
}

void Screen::clear()
{
  m_window->clear(sf::Color(SCREEN_COLOR_R, SCREEN_COLOR_G, SCREEN_COLOR_B));
}

void Screen::drawRect(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint8_t r, uint8_t g, uint8_t b)
{
  sf::RectangleShape rect(sf::Vector2f(w, h));
  rect.setPosition(sf::Vector2f(x, y));
  rect.setFillColor(sf::Color(r, g, b));

  m_window->draw(rect);
}

void Screen::drawText(char txt[TXT_WIDTH], uint16_t x, uint16_t y, uint8_t r, uint8_t g, uint8_t b)
{
  sf::Text text;
  text.setFont(m_font);
  text.setString(txt);
  text.setCharacterSize(TXT_WIDTH);
  text.setPosition(x, y);
  text.setFillColor(sf::Color(r, g, b));
  m_window->draw(text);
}

void Screen::refresh()
{
  m_window->display();
}

Position Screen::getPointer()
{
  Position pos;
  pos.x = 0;
  pos.y = 0;

  m_window->pollEvent(m_event);

  if ((m_event.type == sf::Event::MouseButtonPressed) && (m_event.mouseButton.button == sf::Mouse::Left))
  {
    pos.x = m_event.mouseButton.x;
    pos.y = m_event.mouseButton.y;
  }

  return pos;
}
