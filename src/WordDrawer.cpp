#include <WordDrawer.hpp>

WordDrawer::WordDrawer(const std::string& wordListPath, const sf::Font& font) : _font(font) {
	// Open word list
	_SCOWL.open(wordListPath);
	if (!_SCOWL.is_open())
		throw std::runtime_error("ERROR: Failed to open word list file: " + wordListPath);
}

WordDrawer::~WordDrawer() {
	if (_SCOWL.is_open())
		_SCOWL.close();
}
// Code here...