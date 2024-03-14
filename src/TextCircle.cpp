// References:
// https://www.sfml-dev.org/tutorials/2.6/graphics-transform.php
// https://en.sfml-dev.org/forums/index.php?topic=5790.0
// https://en.sfml-dev.org/forums/index.php?topic=28175.0
// https://learnsfml.com/basics/graphics/how-to-center-text/#example-code

#include <TextCircle.hpp>

TextCircle::TextCircle(const sf::Font& font, const std::string text,
						const float x, const float y) : _font(font), _circleX(x), _circleY(y) {
	// Initialize attributes
	_text.setFont(font);
	_text.setString(text);
	_text.setCharacterSize(_fontSize);
	_text.setFillColor(sf::Color::Black);

	// Create the circle
	CreateCircle();
}

void TextCircle::CenterText() {
	// Get the boundary of the text
	_textBounds = _text.getLocalBounds();

	// Set the origin to the middle of texts boundary
	_text.setOrigin(_textBounds.left + _textBounds.width / 2.0f, 
					_textBounds.top + _textBounds.height / 2.0f);
}

void TextCircle::CreateCircle() {
	// Center the text
	CenterText();

	// Get size of circle
	_circleRadius = _textBounds.width / 2.0f + _textPadding;

	// Set the radius of the circle
	_circle.setRadius(_circleRadius);

	// Set the circles color
	_circle.setFillColor(RandomColor());

	// Set the origin for the circle
	_circle.setOrigin(_circleRadius, _circleRadius);

	// Set the position on the screen
	// .. For now in a set place
	_circle.setPosition(_circleX, _circleY);

	// Center the text to the circle
	_text.setPosition(_circle.getPosition());
}

sf::Color TextCircle::RandomColor() {
	// Seed the generator
	srand(time(NULL));

	// Randomize each color channel
	int r = Randomize();
	int b = Randomize();
	int g = Randomize();

	return sf::Color(r, g, b);
}

int TextCircle::Randomize() {
	return rand() % 256;
}

void TextCircle::draw(sf::RenderTarget& window, sf::RenderStates states) const {
	window.draw(_circle);
	window.draw(_text);
}

bool TextCircle::Contains(const sf::Vector2f& point) const {
	// Get the distance between the x and y cords
	float sideX = point.x - _circle.getPosition().x;
	float sideY = point.y - _circle.getPosition().y;

	// Get the distance between point and circle center
	float distance = std::sqrtf(std::powf(sideX, 2) + std::powf(sideY, 2));

	// Return if the point is within the circle
	return distance <= _circleRadius;
}