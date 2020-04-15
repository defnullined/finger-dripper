#ifndef DICT_HANDLER_INCLUDED
#define DICT_HANDLER_INCLUDED

#include <string>
#include <set>

class DictHandler {
	private:
		std::set<std::string> dictionary;
	public:
		DictHandler(const std::string dictfileName);
		std::string getRandWord();
};

#endif
