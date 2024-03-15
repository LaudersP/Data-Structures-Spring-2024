// References
// Mouse events: 
// https://en.sfml-dev.org/forums/index.php?topic=15275.0
// https://www.sfml-dev.org/tutorials/2.6/window-events.php

#include <WordDrawer.hpp>

#include <iostream>

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

// Function to ensure there is always 10 words in the queue
void WordDrawer::FillQueue() {
	while (_wordQueue.Size() < _queueSize) {
		std::string line;

		if (std::getline(_SCOWL, line))
			_wordQueue.enqueue(line);
	}
}

std::string WordDrawer::GetWord() {
	std::string word = _wordQueue.Top();

	_wordQueue.dequeue();

	return word;
}
