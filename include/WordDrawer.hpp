#ifndef WORD_DRAWER_HPP
#define WORD_DRAWER_HPP

#include <SFML/Graphics.hpp>
#include <TextCircle.hpp>
#include <string>
#include <fstream>
#include <Queue.hpp>

class WordDrawer {
// === Attributes ===
private:
	std::ifstream _SCOWL;
	sf::Font _font;
	ssuds::Queue<std::string> _wordQueue;
	unsigned int _queueSize = 10;

// === Functions ===
public:
	WordDrawer(const std::string& wordListPath, const sf::Font& font);
	~WordDrawer();
	void FillQueue();
};

#endif