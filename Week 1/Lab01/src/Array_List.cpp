#include <Array_List.h>
#include <iostream>

ssuds::ArrayList::ArrayList() {
	_data = nullptr;
	_size = 0;
}

ssuds::ArrayList::~ArrayList() {
	delete[] _data;
}

void ssuds::ArrayList::Append(std::string s) {
	// Check for a empty list
	if (_data == nullptr && _size == 0) {
		// === New list ===
		// Set the size of the array list to hold one data item
		_size++;

		// Allocate memory for the array of strings
		_data = new std::string[_size];

		_data[0] = s;
	}
	else {
		// === List already made ===
		// Increase array size
		_size++;

		// Allocate a temporary array
		std::string* tempData = new std::string[_size];

		// Copy over data from the old array
		for (int i = 0; i < (_size - 1); i++) {
			tempData[i] = _data[i];
		}

		// Assign the new string to the temp array
		tempData[_size - 1] = s;

		// Delete the old array
		delete[] _data;

		// Set the '_data' pointer to the 'tempData' pointer
		_data = tempData;
	}

	return;
}

unsigned int ssuds::ArrayList::Size() const {
	return _size;
}

void ssuds::ArrayList::Insert(std::string s, const unsigned int index) {
	// Check that the desired index is in range
	if (index >= 0 && index < _size + 1) {
		// Check that the string is capable of insertion
		//	1. If array list is empty
		//	2. If the position will be the last position of the array
		if ((_data == nullptr && _size == 0) || index == (_size + 1)) {
			// Append value
			Append(s);

			return;
		}
		// Increase array size
		_size++;

		// Allocate a temporary array
		std::string* tempData = new std::string[_size];

		// Check that 'index' is greater than 0
		if (index != 0) {
			// Loop through the array
			for (int i = 0; i < _size; i++) {
				// Copy data from before the insertion index
				if (i < index) {
					tempData[i] = _data[i];
				}
				// Insertion
				else if (i == index) {
					tempData[index] = s;
				}
				// Copy data from after the insertion index
				else if (i > index) {
					tempData[i] = _data[i - 1];
				}
			}
		}
		else {
			// Insertion
			tempData[0] = s;

			// Copy remainder of data
			for (int i = 1; i < _size; i++) {
				tempData[i] = _data[i - 1];
			}
		}

		// Free up old array
		delete[] _data;

		// Assign 'tempData' pointer to '_data'
		_data = tempData;
	}
	else {
		throw std::out_of_range("Provided position is out of range!");
	}

	return;
}

void ssuds::ArrayList::Clear() {
	// Free up allocated memory
	delete[] _data;

	// Set the list variables to default values
	_size = 0;
	_data = nullptr;

	return;
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

int ssuds::ArrayList::Find(std::string s, unsigned int index) const {
	// Check that 'index' is in range
	if (index >= 0 && index < _size) {
		// Loop through the list
		for (int i = index; i < _size; i++) {
			// Check if the string has been found
			if (_data[i] == s) {
				// Return index
				return i;
			}
		}

		// Index was not found, return -1
		return -1;
	}
	else {
		throw std::out_of_range("Provided position is out of range!");
	}
}

void ssuds::ArrayList::Remove(const unsigned int index) {
	// Check that 'index' is in range
	if (index >= 0 && index < _size) {
		// Remove the desired string
		_data[index] = "";

		// Decrease list size
		_size--;

		// Allocate a temporary array
		std::string* tempData = new std::string[_size];

		// Loop through the list
		for (int i = 0; i < _size + 1; i++) {
			if (i < index) {
				tempData[i] = _data[i];
			}
			else if (i > index) {
				tempData[i - 1] = _data[i];
			}
		}

		// Free up old array
		delete[] _data;

		// Assign 'tempData' pointer to '_data'
		_data = tempData;
	}
	else {
		throw std::out_of_range("Provided position is out of range!");
	}

	return;
}

int ssuds::ArrayList::Remove_All(std::string s) {
	// Variable to hold number of instances removed
	int removed = 0;

	// Loop while 's' can still be found
	while (Find(s) != -1) {
		// Remove the string at the found index
		Remove(Find(s));

		// Increase the removed count
		removed++;
	}

	return removed;
}
