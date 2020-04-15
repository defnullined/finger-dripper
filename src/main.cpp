#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <time.h>
#include "../include/constants.h"
#include "../include/Word.h"
#include "../include/DictionaryHandler.h"
#include "../include/StatusDisplay.h"

using namespace constants;

int main() {
    //srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), TITLE);
    window.setFramerateLimit(FPS); // TODO: poor old cpu support?
    sf::Clock clock;

	// load font
	sf::Font font;
	if (!font.loadFromFile("../resources/fonts/OpenSans-Regular.ttf")) {
  		return 1;
	}

    DictHandler dictionary("../resources/dictionary/test.txt");
    
    // words that are currently displayed on the screen
    std::vector<Word> displayedWords;

    // String to control currently typed word
    sf::String currentEnteredText("");

    // bottom status display
    StatusDisplay status(font);

    sf::Time t = sf::Time::Zero;
    while (window.isOpen()) {
        sf::Time elapsed = clock.restart();
        t += elapsed;

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            // capturing keystrokes
            if(event.type == sf::Event::TextEntered) {
                if(event.text.unicode < 128) {
                    char typedc = static_cast<char>(event.text.unicode);
                    // if a-z or A-Z
                    if(std::isalpha(typedc)) {
                        currentEnteredText += typedc;
                    }
                    // if SPACE
                    else if(typedc == 32) {
                        currentEnteredText.clear();
                    }
                    // if BACKSPACE
                    else if(typedc == 8) {
                        currentEnteredText.erase(currentEnteredText.getSize()-1);
                    }
                }
            }
        }

        window.clear();

        // if x seconds passed and < than y words are displayed, add new word
        if(t.asSeconds() > 1 && displayedWords.size() < 8) {
            std::string w = dictionary.getRandWord();
            Word word(w, font, sf::Color::White, 25);
            displayedWords.push_back(word);
            t = sf::Time::Zero;
        }

        // draw words
        for(int i = 0; i < displayedWords.size(); i++) {
            displayedWords[i].draw(window);
            displayedWords[i].moveX(2.f);
            // erase if out of screen
            if(displayedWords[i].getPos().x > WIDTH - 100) {
                displayedWords.erase(displayedWords.begin() + i);
            }
        }

        //sf::Text cEntText(currentEnteredText, font, 30);
        //window.draw(cEntText);

        status.draw(window);

        window.display();
    }

    return 0;
}
