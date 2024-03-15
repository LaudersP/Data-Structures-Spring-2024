// References:
// https://www.sfml-dev.org/tutorials/2.6/graphics-transform.php
// https://en.sfml-dev.org/forums/index.php?topic=5790.0
// https://en.sfml-dev.org/forums/index.php?topic=28175.0
// https://learnsfml.com/basics/graphics/how-to-center-text/#example-code

#include <TextCircle.hpp>

sf::Font TextCircle::circle_font;

TextCircle::TextCircle() {
}

TextCircle::TextCircle(const std::string text,
						const float x, const float y) : _circleX(x), _circleY(y) {
	// Initialize attributes
	_text.setString(text);
	_text.setCharacterSize(_fontSize);
	_text.setFillColor(sf::Color::Black);

	// Create the circle
	CreateCircle();
}

// Function to get the center of the text field
void TextCircle::CenterText() {
	// Get the boundary of the text
	_textBounds = _text.getLocalBounds();

	// Set the origin to the middle of texts boundary
	_text.setOrigin(_textBounds.left + _textBounds.width / 2.0f, 
					_textBounds.top + _textBounds.height / 2.0f);
}

// Function to create a SFML circle
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

// Function to randomize a SFML color
sf::Color TextCircle::RandomColor() {
	// Seed the generator
	srand(time(NULL));

	// Randomize each color channel
	int r = Randomize();
	int b = Randomize();
	int g = Randomize();

	return sf::Color(r, g, b);
}

// Random value from 0 to 255
int TextCircle::Randomize() {
	return rand() % 256;
}

// Draw override function
void TextCircle::draw(sf::RenderTarget& window, sf::RenderStates states) const {
	window.draw(_circle);
	window.draw(_text);
}

// Function to check if a circle is already there
// .. True if circle is there, false if not
bool TextCircle::Contains(const sf::Vector2f& point) const {
	// Get the distance between the x and y cords
	float sideX = point.x - _circle.getPosition().x;
	float sideY = point.y - _circle.getPosition().y;

	// Get the distance between point and circle center
	float distance = std::sqrtf(std::powf(sideX, 2) + std::powf(sideY, 2));

	// Return if the point is within the circle
	return distance <= _circleRadius;
}

// Equla operator
TextCircle& TextCircle::operator=(const TextCircle& other) {
	// Check that they are different
	if (this != &other) {
		_text = other._text;
		_circle = other._circle;
		_circleX = other._circleX;
		_circleY = other._circleY;
		_circleRadius = other._circleRadius;
		_textBounds = other._textBounds;
		_circleRadius = other._circleRadius;

		_text.setFont(circle_font);

		CreateCircle();
	}

	return *this;
}

void TextCircle::setPosition(float x, float y) {
	_circle.setPosition(x, y);
	_text.setPosition(x, y);
}
