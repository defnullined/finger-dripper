#include <fstream>
#include <iostream>
#include "../include/DictionaryHandler.h"
#include <stdlib.h>
#include <time.h>

DictHandler::DictHandler(const std::string dictfileName) {
	//srand(time(NULL));
	std::ifstream dictFile;
	dictFile.open(dictfileName.c_str());
	if(!dictFile.is_open()) {
		std::cerr << "Unable to open file" << std::endl;
		exit(EXIT_FAILURE);
	}
	// load into set
	for(std::string word; std::getline(dictFile, word);) {
		this->dictionary.insert(word);
	}
	std::cout << "File successfully loaded" << std::endl;
}

std::string DictHandler::getRandWord() {
	std::set<std::string>::iterator it = this->dictionary.begin();
	int rIndex = rand()%this->dictionary.size();
	for(unsigned int i = 0; i < rIndex; ++i) {
		it++;
	}
	return *it;
}
