#include <Array_List_v2.hpp>
#include <Foo.hpp>
#include <iostream>

void Tester();

int main() {
	try {
		// Standard test function
		Tester();
	}
	catch (std::out_of_range& e) {
		// Print out of range error message
		std::cout << "\nERROR : " << e.what() << std::endl;
	}
}

// Step 5. Testing code
void Tester() {
	ssuds::ArrayListV2<float> FL;

	FL.Append(3.1f);
	FL.Append(4.2f);
	FL.Append(5.3f);

	std::cout << FL << std::endl; // [3.1, 4.2, 5.3]

	FL.Insert(1.4f, 0);
	FL.Insert(2.5f, 1);

	std::cout << FL << std::endl; // [1.4, 2.5, 3.1, 4.2, 5.3]

	std::cout << "Capacity: " << FL.Capacity() << std::endl; // 8
	std::cout << "Size: " << FL.Size() << std::endl; // 5

	FL.Append(1.4f);
	FL.Remove_All(1.4f);
	std::cout << FL << std::endl; // [2.5, 3.1, 4.2, 5.3]

	FL.Remove(0);
	FL.Remove(2);
	std::cout << FL << std::endl; // [3.1, 4.2]

	std::cout << "Capacity2: " << FL.Capacity() << std::endl; // 2
	std::cout << "Size2: " << FL.Size() << std::endl; // 2

	FL.Clear();
	std::cout << FL << std::endl; // []
	std::cout << "Capacity2: " << FL.Capacity() << std::endl; // 1
	std::cout << "Size2: " << FL.Size() << std::endl; // 0

	std::cout << "\Testing Completed!" << std::endl;
}