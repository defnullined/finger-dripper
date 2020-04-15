#ifndef WORD_H_INCLUDED
#define WORD_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <string>

class Word {
	private:
		sf::Text word;
	public:
		Word(std::string word, const sf::Font& font, sf::Color color, int size);
		void moveX(float dx);
		void draw(sf::RenderWindow& window);
		sf::Vector2f getPos();
};

#endif
