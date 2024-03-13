#ifndef WORD_DRAWER_HPP
#define WORD_DRAWER_HPP

#include <SFML/Graphics/Font.hpp>
#include <string>
#include <fstream>

class WordDrawer {
// === Attributes ===
private:
	std::ifstream _SCOWL;
	sf::Font _font;

// === Functions ===
public:
	WordDrawer(const std::string& wordListPath, const sf::Font& font);
	~WordDrawer();
};

#endif