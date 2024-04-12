#include <text_circle.h>
#include <SFML/Graphics.hpp>
#include <fstream>
#include <sstream>
#include <iostream>


sf::TextCircle::TextCircle()
{
	// Doesn't initialize anything.
}

sf::TextCircle::TextCircle(float x, float y, const Font& font_ref, std::string text)
{
	// Set properties except position of the text object
	mText.setFont(font_ref);
	mText.setString(text);
	mText.setCharacterSize(24);
	mText.setFillColor(sf::Color::Black);

	// Center the text
	// reference: https://stackoverflow.com/questions/14505571/centering-text-on-the-screen-with-sfml
	mTextRect = mText.getLocalBounds();
	mText.setOrigin(mTextRect.left + mTextRect.width / 2.0f,
		mTextRect.top + mTextRect.height / 2.0f);
	mText.setPosition(sf::Vector2f(x, y));

	// Set the position / radius of the circle
	float radius = (mTextRect.width > mTextRect.height ? mTextRect.width : mTextRect.height) / 2.0f + 5;
	mCircle.setPosition(x - radius, y - radius);
	mCircle.setFillColor(sf::Color(rand() % 128 + 127, rand() % 128 + 127, rand() % 128 + 127, 255));
	mCircle.setRadius(radius);
}



void sf::TextCircle::draw(RenderTarget& target, RenderStates states) const
{
	target.draw(mCircle);
	target.draw(mText);
}

void sf::TextCircle::setCircleColor(const sf::Color& c)
{
	mCircle.setFillColor(c);

}

sf::Vector2f sf::TextCircle::get_position() const
{
	return mCircle.getPosition() + sf::Vector2f(mCircle.getRadius(), mCircle.getRadius());
}


std::string sf::TextCircle::get_string() const
{
	return mText.getString();
}

void sf::TextCircle::set_position(const sf::Vector2f& p)
{
	float radius = mCircle.getRadius();
	mCircle.setPosition(p.x - radius, p.y - radius);
	mText.setPosition(p.x, p.y);
}

bool sf::TextCircle::point_inside(sf::Vector2f v) const
{
	sf::Vector2f p = get_position();
	float dist = powf(powf(v.x - p.x, 2.0f) + powf(v.y - p.y, 2.0f), 0.5f);
	return dist <= mCircle.getRadius();
}

void sf::TextCircle::readFromFile(const std::string& file_path, const sf::Font& font, ssuds::ArrayListV2<TextCircle>& nodes, ssuds::Graph<int, float>& edges) {
	std::ifstream file(file_path);

	// Check that the file was properly opened
	if (!file.is_open())
		throw std::exception("ERROR: Could not open the file!\n");

	std::string line;
	//ssuds::ArrayListV2<TextCircle> nodes;
	//ssuds::Graph<int, float> edges;

	// Loop through the file by lines
	while (std::getline(file, line)) {
		std::stringstream dataLine(line);
		std::string type;
		std::getline(dataLine, type, ':');

		// Check if the data line is a node
		if (type == 'n') {
			int id, r, g, b;
			float x, y;
			std::string temp, label;

			std::getline(dataLine, temp, ':');
			id = std::stoi(temp);
			std::getline(dataLine, label, ':');
			std::getline(dataLine, temp, ':');
			r = std::stoi(temp);
			std::getline(dataLine, temp, ':');
			g = std::stoi(temp);
			std::getline(dataLine, temp, ':');
			b = std::stoi(temp);
			std::getline(dataLine, temp, ':');
			x = std::stof(temp);
			std::getline(dataLine, temp, ':');
			y = std::stof(temp);

			sf::Color color(r, g, b);
			TextCircle node(x, y, font, label);
			node.setCircleColor(color);
			nodes.Append(node);
			edges.add_node(id);
		}
		// Check if the data line is a edge
		else if (type == 'e') {
			int startID, endID;
			float value;
			std::string temp;

			std::getline(dataLine, temp, ':');
			startID = std::stoi(temp);
			std::getline(dataLine, temp, ':');
			endID = std::stoi(temp);
			std::getline(dataLine, temp, ':');
			value = std::stof(temp);

			edges.add_edge(startID, endID, value);
		}
		else
			throw std::exception("ERROR: Unknown data type!\n");
	}
}
