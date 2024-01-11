#include <iostream>
#include <Array_List.h>

int main() {
	// Create an instance of ArrayList class
	ssuds::ArrayList List;

	List.Append("Bob");
	List.Append("Susan");
	List.Append("Jim");
	List.Insert("Jeff@0", 0);
	List.Insert("Jeff@2", 2);
	List.Insert("Jeff@4", 4);
	List.Insert("Jeff@6", 6);

	// Print strings in the list
	for (int i = 0; i < List.Size(); i++) {
		if (i == 0) {
			std::cout << "[" << List.GetString(i);
		}
		else if (i == (List.Size() - 1)) {
			std::cout << ", " << List.GetString(i) << "]" << std::endl;
		}
		else {
			std::cout << ", " << List.GetString(i);
		}
	}

	// Get a string from the list
	std::cout << List.Get(6) << std::endl;

	// Find 'Bob' in the list
	std::cout << List.Find("Parker") << std::endl;
}