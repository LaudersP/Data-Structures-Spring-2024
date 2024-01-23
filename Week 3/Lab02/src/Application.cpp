#include <Array_List.hpp>
#include <iostream>

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

	std::cout << "Capacity: " << tester.Capacity() << std::endl;
	std::cout << "Size: " << tester.Size() << std::endl;

	for (unsigned int i = 0; i < tester.Size(); i++) {
		std::cout << "Element: " << tester.Get(i) << std::endl;
	}
}