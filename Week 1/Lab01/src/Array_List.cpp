#include <Array_List.h>

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
		_size = 1;

		// Allocate memory for the array of strings
		_data = new std::string[_size];

		_data[0] = s;
	}
	else {
		// === List already made ===
		// Increase array size
		_size += 1;

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
}

unsigned int ssuds::ArrayList::Size() {
	return _size;
}



// Using to test
std::string ssuds::ArrayList::GetString(unsigned int pos) {
	return _data[pos];
}
