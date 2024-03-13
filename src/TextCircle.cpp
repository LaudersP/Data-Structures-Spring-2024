#include <TextCircle.hpp>

TextCircle::TextCircle(sf::Font& font) : _font(font) {
	_text.setFont(font);
}