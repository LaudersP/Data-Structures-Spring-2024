#include <iostream>
#include <Array_List.h>

int main() {
	// Create an instance of ArrayList class
	ssuds::ArrayList List;

	// === Development testing ===
	// Variable to hold the size of the list
	unsigned int listSize = List.Size();

	// Print the size of 'List'
	std::cout << "Size of List: " << listSize << std::endl;

	// Append 'Bob' to the List
	List.Append("Bob");

	// Get the new size of 'List'
	listSize = List.Size();

	// Print the size of 'List'
	std::cout << "Size of List: " << listSize << std::endl;

	// Print strings in the list
	for (int i = 0; i < List.Size(); i++) {
		std::cout << List.GetString(i) << std::endl;
	}

	// Append 'Susan' to the List
	List.Append("Susan");

	// Get the new size of 'List'
	listSize = List.Size();

	// Print the size of 'List'
	std::cout << "Size of List: " << listSize << std::endl;

	// Print strings in the list
	for (int i = 0; i < List.Size(); i++) {
		if (i == 0) {
			std::cout << "[" << List.GetString(i);
		}
		else if (i == (List.Size() - 1)) {
			std::cout << ", " << List.GetString(i) << "]";
		}
		else {
			std::cout << ", " << List.GetString(i);
		}
	}
}