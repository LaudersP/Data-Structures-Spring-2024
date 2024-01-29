#include <Array_List.hpp>
#include <iostream>

ssuds::ArrayList::ArrayList() {
	_size = 0;
	_capacity = _capacityMin;

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

int ssuds::ArrayList::Find(std::string s, unsigned int index) const {
	// Check that 'index' is in range
	if (index >= 0 && index < _size) {
		// Loop through the list
		for (unsigned int i = index; i < _size; i++) {
			// Check if the string has been found
			if (_data[i] == s) {
				// Return index
				return i;
			}
		}

		// String was not found
		return -1;
	}
	else {
		throw std::out_of_range("Provided position is out of range!");
	}
}

void ssuds::ArrayList::Remove(const unsigned int index) {
	// Check that 'index' is in range
	if (index >= 0 && index < _size) {
		// Loop from the desired index to the end of the list
		for (unsigned int i = index; i < _size; i++) {
			_data[i] = _data[i + 1];
		}

		// Decrease list size
		_size--;

		// Check if list can be shrunk
		if ((_capacity / 2) == _size) {
			// Half capacity
			_capacity /= 2;

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
	}
	else {
		throw std::out_of_range("Provided position is out of range!");
	}
}

int ssuds::ArrayList::Remove_All(std::string s) {
	// Variable to hold the position of 's' found for removal
	//   prevents unneeded loops through the array. Loops once
	int cur_index = 0;

	// Number of strings removed from the array
	int num_removed = 0;

	// While 'cur_index' is in range of the array's size
	while (cur_index >= 0 && cur_index < _size) {
		// Find The next occurence
		cur_index = Find(s, cur_index);

		// If the occurence if found
		if (cur_index >= 0) {
			// Remove the string at the found index
			Remove(cur_index);

			// Increase the removed count
			num_removed++;
		}
	}
	return num_removed;
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

void ssuds::ArrayList::Clear() {
	// Free up allocated memory
	delete[] _data;

	// Set the list variables to default values
	_size = 0;
	_capacity = _capacityMin;

	// Allocate memory for the array
	_data = new std::string[_capacity];
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