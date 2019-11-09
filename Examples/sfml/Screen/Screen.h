#ifndef SCREEN_H
#define SCREEN_H

#include "Position.h"
#include "Colorable.h"

#define SCREEN_WIDTH        320
#define SCREEN_HEIGHT       240

#define SCREEN_COLOR_R  		0
#define SCREEN_COLOR_G  		0
#define SCREEN_COLOR_B  		0

#define TXT_WIDTH           10

//The following inclusions are library dependant
#include <SFML/Graphics.hpp>

class Screen : public Colorable
{
	public:
		Screen();

		void clear();

    void drawRect(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint8_t r, uint8_t g, uint8_t b);
    void drawCircle(uint16_t x, uint16_t y, uint16_t r);
    void drawLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);
    void drawText(char txt[TXT_WIDTH], uint16_t x, uint16_t y, uint8_t r, uint8_t g, uint8_t b);

		void refresh();

    Position getPointer();

	private:
    //The following members/methods are library dependant
    sf::RenderWindow *m_window;
    sf::Event m_event;
		sf::Font m_font;
};

#endif //SCREEN_H
