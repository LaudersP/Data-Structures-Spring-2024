#include "ArrayList.h"

ssuds::ArrayList::ArrayList() {
	_size = 0;
	_data = nullptr;	// Just like NULL, but only assignable to pointers
}

ssuds::ArrayList::~ArrayList() {

}

void ssuds::ArrayList::Append(std::string s) {
	// Two possibilities:
	// 1. We have an empty list
	//		We need to allocate the array to be the size of 1
	//		We need to assign s to the only spot in the array
	//		We need to set mSize to 1
	// 2. We have a list with stuff in it
	//		We need to allocate a temporary array that's one bigger than our current one.
	//		We need to 
	//		We need to free up the old array
	//		We need to make the larger array
}

unsigned int ssuds::ArrayList::Size() {
	return _size;
}
