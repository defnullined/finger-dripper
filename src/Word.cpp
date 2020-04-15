#include <SFML/Graphics.hpp>
#include <string>
#include "../include/Word.h"
#include <stdlib.h>
#include <time.h>
#include "../include/constants.h"

using namespace constants;

Word::Word(std::string word, const sf::Font& font, sf::Color color, int size) {
	this->word.setFont(font);
	this->word.setString(word);
	this->word.setFillColor(color);
	this->word.setCharacterSize(size);
	// set random position
	int r = rand()%(HEIGHT-50);
	this->word.setPosition(0.f, float(r));
}

void Word::moveX(float dx) {
	this->word.move(dx, 0);
}

void Word::draw(sf::RenderWindow& window) {
	window.draw(word);
}

sf::Vector2f Word::getPos() {
	return this->word.getPosition();
}
