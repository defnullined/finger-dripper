#include <SFML/Graphics.hpp>
#include "../include/StatusDisplay.h"
#include "../include/constants.h"

using namespace constants;

StatusDisplay::StatusDisplay(sf::Font& font) {
	statusDisplay.setPosition(0, HEIGHT - STATUS_DISPLAY_HEIGHT);
	statusDisplay.setSize(sf::Vector2f(STATUS_DISPLAY_WIDTH, STATUS_DISPLAY_HEIGHT));
	statusDisplay.setFillColor(sf::Color::Blue);
	statusDisplay.setOutlineThickness(2);

	scoreText.setFont(font);
	scoreText.setString(sf::String("Score: "));
	scoreText.setPosition(sf::Vector2f(10, HEIGHT - STATUS_DISPLAY_HEIGHT + 10));
	scoreText.setCharacterSize(25);
}

void StatusDisplay::draw(sf::RenderWindow& window) {
	window.draw(statusDisplay);
	window.draw(scoreText);
}
