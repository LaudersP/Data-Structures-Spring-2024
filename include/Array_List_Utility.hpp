#ifndef ARRAY_LIST_UTILITY_H
#define ARRAY_LIST_UTILITY_H

#include <Array_List_v2.hpp>
#include <random>

#include <iostream>

namespace ssuds {
	enum class SortType { ASCENDING, DESCENDING };

	// Function for sorting the array list via quick sort method
	template <class T>
	unsigned int QuickSort(ArrayListV2<T>& a) {
		// Implement here...
		// return number of swaps

		//   0    1    2    3    4    5    6
		// [5.5, 3.3, 6.6, 4.4, 2.2, 8.8, 7.7]
		// Left: 0
		// Right: 6
		// Pivot: 4.4 (the thing at the midway index between left and right)
		// swap_index: 0 ( set to left, initially)

		// Step 1. Swap the pivot value so it appears at the end
		//   0    1    2    3    4    5    6
		// [5.5, 3.3, 6.6, 7.7, 2.2, 8.8, 4.4]

		// Step 2. Make one "pass" from left => right
		// i = 0. Nothing to do
		// i = 1. Swap A[1] with A[swap_index], then add 1 to swap_index
		// [3.3, 5.5, 6.6, 7.7, 2.2, 8.8, 4.4]
		// swap_index: 2
		// i = 2. A[2] '6.6' is on the correct side -- Nothing to do
		// i = 3. A[3] '7.7' is on the correct side -- Nothing to do
		// i = 4. A[4] '2.2' is on the wrong side. Swap A[4] with A[swap_index] and add 1
		// [3.3, 2.2, 6.6, 7.7, 5.5, 8.8, 4.4]
		// i = 5. A[5] '8.8' is on the correct side
		// i = 6. A[6] '4.4' is at the pivot value -- swap A[6] with A[swap_index] and add 1
		// [3.3, 2.2, 4.4, 7.7, 5.5, 8.8, 6.6]

		// Done. The swap index - 1 should be returned
	}

	// Function to randomize an array list
	template <class T>
	int BinarySearch(const ArrayListV2<T>& a) {
		// Implement here...
		// return the index of (on of) the occurence(s) of the
		// ... in the array list or -1 if not found
	}

	// Function for sorting the array list via bubble sort method
	template <class T>
	unsigned int BubbleSort(ArrayListV2<T>& a) {
		// Implement here...
		// return number of swaps
	}

	// Function to randomize an array list using the Fisher-Yates algorithm
	template <class T>
	void Shuffle(ArrayListV2<T>& a) {
		// Get the size of the array
		unsigned int n = a.Size();

		// Seed/prepare the random generator
		std::default_random_engine generator;
		std::mt19937 mt(generator); 

		// Shuffle loop
		for (unsigned int i = n - 1; i > 0; --i) {
			// Set the random generator ranges
			std::uniform_int_distribution<unsigned int> distribution(0, i - 1);
			
			// Generate random number number
			unsigned int chosen = distribution(mt);

			// Swap chosen slot with index slot
			// Reference: https://www.geeksforgeeks.org/swap-in-cpp/?ref=header_search
			std::swap(a[i], a[chosen]);
		}
	}
}

#endif