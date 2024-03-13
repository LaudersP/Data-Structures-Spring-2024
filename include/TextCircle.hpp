#ifndef TEXT_CIRCLE_HPP
#define TEXT_CIRCLE_HPP

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Text.hpp>

class TextCircle : private sf::Drawable {
// Attributes
private:
	sf::Font _font;
	sf::Text _text;

// Functions
public:
	TextCircle(sf::Font& font);
};

#endif