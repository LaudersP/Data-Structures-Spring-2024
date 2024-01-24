#include <Array_List.hpp>
#include <iostream>

/*
int main() {
	ssuds::ArrayList tester;

	tester.Append("Bob1");
	tester.Append("Bob2");
	tester.Append("Bob3");
	tester.Append("Bob4");
	tester.Append("Bob6");
	tester.Append("Bob7");
	tester.Append("Bob8");
	tester.Append("Bob9");

	tester.Insert("Bob5", 4);

	std::cout << "Capacity: " << tester.Capacity() << std::endl; // 16
	std::cout << "Size: " << tester.Size() << std::endl; // 9

	std::cout << tester.Find("Bob9") << std::endl; // 8
	std::cout << tester.Find("Bob1", 2) << std::endl; // -1

	for (unsigned int i = 0; i < tester.Size(); i++) {
		if (i == 0) {
			std::cout << "[" << tester.Get(i) << ", ";
		}
		else if (i == (tester.Size() - 1)) {
			std::cout << tester.Get(i) << "]" << std::endl;
		}
		else {
			std::cout << tester.Get(i) << ", ";
		}
	}

	tester.Remove(5); // Removes 'Bob6'

	for (unsigned int i = 0; i < tester.Size(); i++) {
		if (i == 0) {
			std::cout << "[" << tester.Get(i) << ", ";
		}
		else if (i == (tester.Size() - 1)) {
			std::cout << tester.Get(i) << "]" << std::endl;
		}
		else {
			std::cout << tester.Get(i) << ", ";
		}
	}

	std::cout << "Capacity: " << tester.Capacity() << std::endl; // 8
	std::cout << "Size: " << tester.Size() << std::endl; // 8


	tester.Append("Bob6");
	tester.Insert("Bob6", 2);
	tester.Append("Bob6");
	tester.Insert("Bob6", 5);
	tester.Append("Bob6");

	for (unsigned int i = 0; i < tester.Size(); i++) {
		if (i == 0) {
			std::cout << "[" << tester.Get(i) << ", ";
		}
		else if (i == (tester.Size() - 1)) {
			std::cout << tester.Get(i) << "]" << std::endl;
		}
		else {
			std::cout << tester.Get(i) << ", ";
		}
	}

	std::cout << "Capacity: " << tester.Capacity() << std::endl; // 16
	std::cout << "Size: " << tester.Size() << std::endl; // 13

	std::cout << "Bob6 Removed: " << tester.Remove_All("Bob6") << std::endl;

	std::cout << "Capacity: " << tester.Capacity() << std::endl; // 8
	std::cout << "Size: " << tester.Size() << std::endl; // 8
}*/