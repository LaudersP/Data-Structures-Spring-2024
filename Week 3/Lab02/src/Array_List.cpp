#include <Array_List.hpp>
#include <iostream>

ssuds::ArrayList::ArrayList() {
	_data = nullptr;
	_size = 0;
	_capacity = 1;

	// Allocate memory for the array
	_data = new std::string[_capacity];
}

ssuds::ArrayList::~ArrayList() {
	delete[] _data;
}

void ssuds::ArrayList::Append(const std::string s) {
	// Check if list capacity needs to be expanded
	if (_size == _capacity) {
		Grow();
	}

	// Add append string
	_data[_size] = s;

	// Increase the number of used spots in the list
	_size++;
}

void ssuds::ArrayList::Grow() {
	// Double the capacity of the list
	_capacity *= 2;

	// Allocate memory for the new array of strings
	std::string* tempData = new std::string[_capacity];

	// Copy over the data from the old array
	for (int i = 0; i < _size; i++) {
		tempData[i] = _data[i];
	}

	// Delete the old array 
	delete[] _data;

	// Set the '_data' pointer to the 'tempData' pointer
	_data = tempData;
}

unsigned int ssuds::ArrayList::Size() const {
	return _size;
}

void ssuds::ArrayList::Insert(std::string s, const unsigned int index) {
	// Check that index is in range of the array
	if (index >= 0 && index < (_size + 1)) {
		// Check that the string is capable of insertion
		// 1. If the array list is empty
		// 2. If the position will be the spot following the last filled slot
		if ((_size == 0 && _capacity == 1) || (index == (_size + 1))) {
			// Append the value
			Append(s);

			return;
		}

		// === Insertion ===
		// Check if the array needs to be grown
		if (_size == _capacity) {
			Grow();
		}

		// Increase array list size
		_size++;

		// Loop through the back items of the array until reaching 'index'
		//    Copy everything one spot right in the array so the 'index' is empty
		for (unsigned int i = _size; i > index; i--) {
			_data[i] = _data[i - 1];
		}

		_data[index] = s;
	}
	else {
		throw std::out_of_range("Provided position is out of range!");
	}
}

unsigned int ssuds::ArrayList::Capacity() const {
	return _capacity;
}

std::string ssuds::ArrayList::Get(const unsigned int index) const {
	// Check that 'index' is in range
	if (index >= 0 && index < _size) {
		// Return the string at the index position of the list
		return _data[index];
	}
	else {
		throw std::out_of_range("Provided position is out of range!");
	}
}