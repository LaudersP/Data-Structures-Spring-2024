#ifndef TEXT_CIRCLE_HPP
#define TEXT_CIRCLE_HPP

#include <SFML/Graphics.hpp>
#include <cmath>

class TextCircle : public sf::Drawable {
// Attributes
private:
	sf::Text _text;
	sf::FloatRect _textBounds;
	sf::CircleShape _circle;
	const unsigned int _fontSize = 22;
	float _textPadding = 5.0f;
	float _circleRadius;
	float _circleX, _circleY;

public:
	static sf::Font circle_font;

// Functions
public:
	TextCircle();
	TextCircle(const std::string text,
		const float x, const float y);
	bool Contains(const sf::Vector2f& point) const;

	TextCircle& operator=(const TextCircle& other);
	void setPosition(float x, float y);

protected:
	void CreateCircle();
	void draw(sf::RenderTarget& window, sf::RenderStates states) const override;
	void CenterText();
	sf::Color RandomColor();
	int Randomize();
};

#endif