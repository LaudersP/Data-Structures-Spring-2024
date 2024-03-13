#include <iostream>

#define LAB_NUM 0	// 0 Runs GoogleTest

#if LAB_NUM == 0
#include <gtest/gtest.h>

int main() {
	testing::InitGoogleTest();
	return RUN_ALL_TESTS();
}


#elif LAB_NUM == 1
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
	std::cout << tester.Get(2) << std::endl; // Sam
	std::cout << tester.Get(3) << std::endl; // Jim
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
	std::cout << tester.Size() << std::endl; // 3
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


#elif LAB_NUM == 3
#include <Array_List_v2.hpp>
#include <vector>

int main() {
	ssuds::ArrayListV2<float> f;

	f.Append(1.1f);
	f.Append(2.2f);
	f.Append(3.3f);

	// Make an iterator
	ssuds::ArrayListV2<float>::ArrayListIterator fiter;

	fiter = f.begin();

	// Iterator loop
	std::cout << "Manual Iteration 1" << std::endl;

	while (fiter != f.end()) {
		// Get the current values
		float fval = *fiter;
		std::cout << fval << std::endl;

		// Advance the iterator
		++fiter;
	}

	std::cout << std::endl;
	std::cout << "Manual Iteration 2" << std::endl;

	for (int i = 0; i < f.Size(); i++) {
		std::cout << f[i] << std::endl;
	}

	// If above works this will too
	std::cout << std::endl;
	std::cout << "Testing pretty for-each loop" << std::endl;

	for (float temp : f) {
		std::cout << temp << std::endl;
	}
}


#elif LAB_NUM == 4 
#include <Array_List_v2.hpp>
#include <Array_List_Utility.hpp>
#include <fstream>
#include <iostream>
#include <random>
#include <chrono>

#include <thread>

#define OUTPUT_PATH "../../output/results.csv"

void FillArray(ssuds::ArrayListV2<float>& a, unsigned int slotSize);
void SaveOutput(std::ofstream& file, const std::chrono::steady_clock::time_point start, const std::chrono::steady_clock::time_point end, const unsigned int numberOfProcesses = 1);
void GetSamples(ssuds::ArrayListV2<float>& a, ssuds::ArrayListV2<float>& b);

int main() {
	// Open output file
	std::ofstream outputFile(OUTPUT_PATH);

	// Check if the file was opened
	if (!outputFile.is_open()) {
		std::cout << "File NOT Opened!" << std::endl;
		return 1;
	}

	// Output header labels
	outputFile << "Size(),StartingVal,ShuffleT,CopyT,QuickSortT,QuickSortO,BubbleSortT,BubbleSortO,BinarySearchT,BinarySearchO,LinearSearchT,LinearSearchO\n";

	// Automated testing loop
	for (unsigned int testSize = 1000; testSize <= 500000; testSize += 5000) {
		// Correct incorrect testSize
		if (testSize > 1000 && testSize < 10000) {
			testSize -= 1000;
		}

		// Create ArrayList instance
		ssuds::ArrayListV2<float> al;

		// Generate the ArrayList
		FillArray(al, testSize);

		// Starting ending variables for all the testings
		std::chrono::steady_clock::time_point start, end;

		// Elasped time variables for all the testings
		std::chrono::milliseconds elasped;

		// Output Array.Size() 
		outputFile << al.Size();

		// Print Array.Size()
		std::cout << "(" << al.Size() << ")" << std::endl;
		std::cout << "------------------------" << std::endl;

		// Get the starting value
		float startingValue = al[0];

		// Output the starting value
		outputFile << "," << startingValue;

		// Second ArrayList to hold greater sample size for searching algorithms
		ssuds::ArrayListV2<float> sampleData;

		// Get sample
		GetSamples(al, sampleData);


		// ===== Shuffle =====
		// Print Operation
		std::cout << "Shuffle:" << std::endl;

		// Get system start time
		start = std::chrono::steady_clock::now();

		// Perform shuffle
		ssuds::Shuffle(al);

		// Get system end time
		end = std::chrono::steady_clock::now();

		// Output info
		SaveOutput(outputFile, start, end);



		// ===== Copy =====
		// Print Operation
		std::cout << "\nCopy:" << std::endl;

		// Get system start time
		start = std::chrono::steady_clock::now();

		// Copy ArrayList
		ssuds::ArrayListV2<float> al2(al);

		// Get system end time
		end = std::chrono::steady_clock::now();

		// Output info
		SaveOutput(outputFile, start, end);

		

		// Variable to hold the number of swaps for sorting algorithms
		unsigned int swaps = 0;

		// ===== QuickSort =====
		// Print Operation
		std::cout << "\nQuickSort:" << std::endl;

		// Get system start time
		start = std::chrono::steady_clock::now();

		// QuickSort the array
		swaps = ssuds::QuickSort(al, ssuds::SortType::ASCENDING, al.Size());

		// Get system end time
		end = std::chrono::steady_clock::now();

		// Output info
		SaveOutput(outputFile, start, end);

		// Output swaps
		std::cout << "Operations: " << swaps << std::endl;
		outputFile << "," << swaps;



		// ===== BubbleSort =====
		// Print Operation
		std::cout << "\nBubbleSort:" << std::endl;

		// Get system start time
		start = std::chrono::steady_clock::now();

		// QuickSort the array

		swaps = ssuds::BubbleSort(al2, ssuds::SortType::ASCENDING);

		// Get system end time
		end = std::chrono::steady_clock::now();

		// Output info
		SaveOutput(outputFile, start, end);

		// Output swaps
		std::cout << "Operations: " << swaps << std::endl;
		outputFile << "," << swaps;

	

		// Variable to hold number of comparisions for BinarySearch
		long int comparisons = 0;
		long int totalComparisons = 0;

		// ===== BinarySearch =====
		// Print Operation
		std::cout << "\nBinarySearch:" << std::endl;

		// Get system start time
		start = std::chrono::steady_clock::now();

		// Find 'startingValue'
		//ssuds::BinarySearch(al, ssuds::SortType::ASCENDING, startingValue, &comparisons);

		// Find all the sampleData elements for average
		for (unsigned int i = 0; i < sampleData.Size(); i++) {
			ssuds::BinarySearch(al, ssuds::SortType::ASCENDING, sampleData[i], &totalComparisons);
		}

		// Get system end time
		end = std::chrono::steady_clock::now();

		// Output info
		SaveOutput(outputFile, start, end, sampleData.Size());

		// Get correct comparisons
		comparisons = totalComparisons / sampleData.Size();

		// Output swaps
		std::cout << "Operations: " << comparisons << std::endl;
		outputFile << "," << comparisons;


		// Variable to hold number of comparisions for LinearSearch
		long int linearComparisons = 0;
		long int totalLinearComparisons = 0;

		// ===== LinearSearch =====
		// Print Operation
		std::cout << "\nLinearSearch:" << std::endl;

		// Get system start time
		start = std::chrono::steady_clock::now();

		// Find 'startingValue'
		//unsigned int comparisons2 = al2.Find(startingValue);

		// Find all the sampleData elements for average
		for (unsigned int i = 0; i < sampleData.Size(); i++) {
			totalLinearComparisons += al2.Find(sampleData[i]);
		}

		// Get system end time
		end = std::chrono::steady_clock::now();

		// Output info
		SaveOutput(outputFile, start, end, sampleData.Size());

		// Get correct comparisons
		linearComparisons = totalLinearComparisons / sampleData.Size();

		// Output swaps
		std::cout << "Operations: " << linearComparisons << std::endl;
		outputFile << "," << linearComparisons;


		outputFile << "\n";
		std::cout << std::endl;

	}

	outputFile.close();

	return 0;
}

void FillArray(ssuds::ArrayListV2<float>& a, unsigned int slotSize) {
	// Seed/prepare the random generator
	std::random_device generator;
	std::mt19937 mt(generator());

	// Set the random generator ranges
	std::uniform_real_distribution<float> distribution(0.0f, 1.0f);

	// Fill with desired number of elements
	for (unsigned int i = 0; i < slotSize; i++) {
		// Generate float
		float randomized = distribution(mt);

		// Append to list
		a.Append(randomized);
	}
}

void GetSamples(ssuds::ArrayListV2<float>& a, ssuds::ArrayListV2<float>& b) {
	// Get the size of the original array
	unsigned int n = a.Size();

	// Grab 25 percent of that size
	unsigned int sampleSize = n * 0.25;

	// Loop though the front 'sampleSize' of elements
	for (unsigned int i = 0; i < sampleSize; i++) {
		b.Append(a[i]);
	}
}

void SaveOutput(std::ofstream& file, const std::chrono::steady_clock::time_point start, const std::chrono::steady_clock::time_point end, const unsigned int numberOfProcesses) {
	std::chrono::milliseconds elasped;

	// Calculate time
	elasped = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	unsigned long int numMs = elasped.count();

	std::cout << "TIME: " << elasped.count() << std::endl;

	// Check if more than one process was during 'elasped' time
	if (numberOfProcesses != 1) {
		numMs /= numberOfProcesses;
	}

	// Output results
	std::cout << "Completed in: " << numMs << " ms" << std::endl;
	file << "," << numMs;
}


#elif LAB_NUM == 5
#include <Linked_List.hpp>
#include <iostream>

int main() {
	ssuds::LinkedList<int> LL;

	LL.Append(1);
	LL.Append(2);
	LL.Append(3);
	LL.Append(4);
	LL.Append(5);
	LL.Append(7);

	LL.Prepend(0);
	LL.Prepend(-1);
	LL.Prepend(-2);
	LL.Prepend(-4);

	LL.Insert(1, -3);
	LL.Insert(10, 6);

	std::cout << "Original LinkedList: " << LL << std::endl;

	std::cout << "Size: " << LL.Size() << std::endl;

	// ===== Iterator testing ===== 

	// Test iteration (forward)
	std::cout << "Iterating forward:";
	for (int temp : LL) {
		std::cout << temp << " ";
	}
	std::cout << std::endl;

	// Test iteration backward
	std::cout << "Iterating backward: ";
	for (ssuds::LinkedList<int>::LinkedListIterator i = LL.rbegin(); i != LL.rend(); --i) {
		std::cout << *i << " ";
	}
	std::cout << std::endl;

	ssuds::LinkedList<int>::LinkedListIterator results = LL.Find(-3);

	if (results != LL.end()) {
		std::cout << "Element: -3, Found at: " << results.Index() << std::endl;
	}

	results = LL.Find(6);

	if (results != LL.rend()) {
		std::cout << "Element: 6, Found at: " << results.Index() << std::endl;
	}
}


#elif LAB_NUM == 6
#include <SFML/Graphics.hpp>
#include <Stack.hpp>

int main() {
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML Works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}

#endif