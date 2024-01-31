#include <iostream>

#define LAB_NUM 2

#if LAB_NUM == 1
/**
* fstream referenced from: Sams Teach Yourself C++ (ISBN13: 978-0-13-733468-1, Pages: 672-675)
* out_of_range exception referenced from: Sams Teach Yourself C++ (ISBN13: 978-0-13-733468-1, Pages: 689-694)
*/

#include <fstream>
#include <Array_List.h>
#include <stdexcept>

#define OUTPUT_FILE_PATH "../../temp/visual_studio2022/ArrayListOutput.txt"

void Tester();
void UserOptions();

int main() {
	// Step 4 Function call
	Tester();

	// Try and catch out of range exceptions
	try {
		// Step 5 Function call
		UserOptions();
	}
	catch (std::out_of_range& e) {
		// Print out of range error
		std::cout << "\nERROR: " << e.what() << std::endl;
	}
}

// Step 4. Function for testing the ArrayList class
void Tester() {
	// Tester instance of ArrayList
	ssuds::ArrayList tester;

	tester.Append("Bob");
	tester.Append("Carl");

	std::cout << tester.Size() << std::endl; // 2
	std::cout << tester.Get(0) << std::endl; // Bob
	std::cout << tester.Get(1) << std::endl; // Carl

	tester.Append("Sam");
	tester.Append("Susan");
	tester.Insert("Jim", 3);
	tester.Append("Jim");

	std::cout << std::endl;
	std::cout << tester.Size() << std::endl; // 6
	std::cout << tester.Get(0) << std::endl; // Bob
	std::cout << tester.Get(1) << std::endl; // Carl
	std::cout << tester.Get(2) << std::endl; // Jim
	std::cout << tester.Get(3) << std::endl; // Sam
	std::cout << tester.Get(4) << std::endl; // Susan
	std::cout << tester.Get(5) << std::endl; // Jim

	tester.Remove_All("Jim");

	std::cout << std::endl;
	std::cout << tester.Size() << std::endl; // 4
	std::cout << tester.Get(0) << std::endl; // Bob
	std::cout << tester.Get(1) << std::endl; // Carl
	std::cout << tester.Get(2) << std::endl; // Sam
	std::cout << tester.Get(3) << std::endl; // Susan

	tester.Remove(0);

	std::cout << std::endl;
	std::cout << tester.Size() << std::endl; // 4
	std::cout << tester.Get(0) << std::endl; // Carl
	std::cout << tester.Get(1) << std::endl; // Sam
	std::cout << tester.Get(2) << std::endl; // Susan

	std::cout << std::endl;
	std::cout << tester.Find("Sam") << std::endl; // 1

	// === File Output ===
	// Open output file
	std::fstream fp(OUTPUT_FILE_PATH, std::ios::out);

	if (fp.is_open()) {
		fp << "Test Strings |" << std::endl;
		fp << "------------------------------------" << std::endl;

		// Loop through the array list
		for (int i = 0; i < tester.Size(); i++) {
			// Output the strings to the txt file
			fp << tester.Get(i) << std::endl;
		}

		fp << "------------------------------------" << std::endl;

		// Close the output file
		fp.close();
	}
}

// Step 5. User menu with save
void UserOptions() {
	// Create an instance of ArrayList
	ssuds::ArrayList List;

	// Variable to hold loop status
	bool done = false;

	// Variable to hold user input
	int userInput;

	do {
		// Print main menu and get input
		do {
			std::cout << std::endl;
			std::cout << "Options |" << std::endl;
			std::cout << "------------------------------------" << std::endl;
			std::cout << " (1) Append" << std::endl;
			std::cout << " (2) Size" << std::endl;
			std::cout << " (3) Insert" << std::endl;
			std::cout << " (4) Clear" << std::endl;
			std::cout << " (5) Get" << std::endl;
			std::cout << " (6) Find" << std::endl;
			std::cout << " (7) Remove" << std::endl;
			std::cout << " (8) Remove All" << std::endl;
			std::cout << " (9) Quit" << std::endl;
			std::cout << "------------------------------------" << std::endl;
			std::cout << " >> ";

			std::cin >> userInput;
		} while ((userInput < 1) || (userInput > 9));

		// Act on the 'userInput'
		switch (userInput) {
		case 1: {
			// Append
			// Variable to hold desired appended string
			std::string input;

			// Get input
			std::cout << std::endl;
			std::cout << "Append |" << std::endl;
			std::cout << "------------------------------------" << std::endl;
			std::cout << " Enter String " << std::endl;
			std::cout << "------------------------------------" << std::endl;
			std::cout << " >> ";
			std::cin >> input;

			// Append user input
			List.Append(input);

			break;
		}
		case 2: {
			// Size
			std::cout << std::endl;
			std::cout << "Append |" << std::endl;
			std::cout << "------------------------------------" << std::endl;
			std::cout << " Size of Array: " << List.Size() << std::endl;
			std::cout << "------------------------------------" << std::endl;

			break;
		}
		case 3: {
			// Insert
			// Variable to hold desired appended string
			std::string input;

			// Variable to hold desired position
			unsigned int index;

			// Get inputs
			std::cout << std::endl;
			std::cout << "Insert |" << std::endl;
			std::cout << "------------------------------------" << std::endl;
			std::cout << " Enter String " << std::endl;
			std::cout << "------------------------------------" << std::endl;
			std::cout << " >> ";
			std::cin >> input;

			std::cout << std::endl;
			std::cout << "Insert |" << std::endl;
			std::cout << "------------------------------------" << std::endl;
			std::cout << " Enter Position " << std::endl;
			std::cout << "------------------------------------" << std::endl;
			std::cout << " >> ";
			std::cin >> index;

			// Append user input
			List.Insert(input, index);

			break;
		}
		case 4: {
			// Clear
			List.Clear();
			std::cout << std::endl;
			std::cout << "Clear |" << std::endl;
			std::cout << "------------------------------------" << std::endl;
			std::cout << " List Cleared! " << std::endl;
			std::cout << "------------------------------------" << std::endl;

			break;
		}
		case 5: {
			//Get
			// Variable to hold index
			unsigned int index;

			std::cout << std::endl;
			std::cout << "Get |" << std::endl;
			std::cout << "------------------------------------" << std::endl;
			std::cout << " Enter Position " << std::endl;
			std::cout << "------------------------------------" << std::endl;
			std::cout << " >> ";
			std::cin >> index;

			std::cout << std::endl;
			std::cout << "Get |" << std::endl;
			std::cout << "------------------------------------" << std::endl;
			std::cout << " String Grabbed: " << List.Get(index) << std::endl;
			std::cout << "------------------------------------" << std::endl;

			break;
		}
		case 6: {
			// Find
			// Variable to hold input string
			std::string input;

			std::cout << std::endl;
			std::cout << "Find |" << std::endl;
			std::cout << "------------------------------------" << std::endl;
			std::cout << " Enter String " << std::endl;
			std::cout << "------------------------------------" << std::endl;
			std::cout << " >> ";
			std::cin >> input;

			if (List.Find(input) != -1) {
				std::cout << std::endl;
				std::cout << "Find |" << std::endl;
				std::cout << "------------------------------------" << std::endl;
				std::cout << " String Found At: " << List.Find(input) << std::endl;
				std::cout << "------------------------------------" << std::endl;
			}
			else {
				std::cout << std::endl;
				std::cout << "Find |" << std::endl;
				std::cout << "------------------------------------" << std::endl;
				std::cout << " String Not Found" << std::endl;
				std::cout << "------------------------------------" << std::endl;
			}

			break;
		}
		case 7: {
			// Remove
			// Variable to hold index
			unsigned int index;

			std::cout << std::endl;
			std::cout << "Remove |" << std::endl;
			std::cout << "------------------------------------" << std::endl;
			std::cout << " Enter Position " << std::endl;
			std::cout << "------------------------------------" << std::endl;
			std::cout << " >> ";
			std::cin >> index;

			List.Remove(index);

			break;
		}
		case 8: {
			// Remove All
			// Variable to hold input string
			std::string input;

			std::cout << std::endl;
			std::cout << "Remove All |" << std::endl;
			std::cout << "------------------------------------" << std::endl;
			std::cout << " Enter String " << std::endl;
			std::cout << "------------------------------------" << std::endl;
			std::cout << " >> ";
			std::cin >> input;

			std::cout << std::endl;
			std::cout << "Remove All |" << std::endl;
			std::cout << "------------------------------------" << std::endl;
			std::cout << " String(s) Removed: " << List.Remove_All(input) << std::endl;
			std::cout << "------------------------------------" << std::endl;

			break;
		}
		case 9: {
			// Check that there are strings in the array that need saving
			if (List.Size() > 0) {
				// Open output file
				std::fstream fp(OUTPUT_FILE_PATH, std::ios::app);

				if (fp.is_open()) {
					fp << std::endl;
					fp << "User Strings |" << std::endl;
					fp << "------------------------------------" << std::endl;

					// Loop through the array list
					for (int i = 0; i < List.Size(); i++) {
						// Output the strings to the txt file
						fp << List.Get(i) << std::endl;
					}

					fp << "------------------------------------" << std::endl;

					// Close the output file
					fp.close();
				}
			}

			done = 1;

			break;
		}
		}
	} while (!done);
}


#elif LAB_NUM == 2
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

#endif