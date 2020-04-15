#ifndef STATUS_DISPLAY_H
#define STATUS_DISPLAY_H
#include <SFML/Graphics.hpp>

class StatusDisplay {
	private:
		sf::RectangleShape statusDisplay;
		sf::Text scoreText;
	public:
		StatusDisplay(sf::Font& font);
		void draw(sf::RenderWindow& window);
};

#endif
