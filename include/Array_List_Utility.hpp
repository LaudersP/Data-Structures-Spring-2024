// std::swap() Reference: https://www.geeksforgeeks.org/swap-in-cpp/?ref=header_search

#ifndef ARRAY_LIST_UTILITY_H
#define ARRAY_LIST_UTILITY_H

#include <Array_List_v2.hpp>
#include <random>

#include <iostream>

namespace ssuds {
	// Sorting direction
	enum class SortType { ASCENDING, DESCENDING };

	// "Helper" recursion function for QuickSort()
	template <class T>
	void QuickSortRecursion(ArrayListV2<T>& a, SortType order, int leftIndex, int rightIndex, int* swaps) {
		// Only perform when the list is greater than one element
		if (leftIndex < rightIndex) {
			// Get the pivot index
			int pivotIndex = Partition(a, order, leftIndex, rightIndex, swaps);

			// Perform left side sorting
			QuickSortRecursion(a, order, leftIndex, pivotIndex - 1, swaps);

			// Perform right side sorting
			QuickSortRecursion(a, order, pivotIndex + 1, rightIndex, swaps);
		}
	}

	// "Helper" function for QuickSort()
	template <class T>
	int Partition(ArrayListV2<T>& a, SortType order, int leftIndex, int rightIndex, int* swaps) {
		// Get the "middle" index of the ArrayList
		int pivotIndex = ((leftIndex + rightIndex) / 2);

		// Get the pivots value
		T pivotValue = a[pivotIndex];

		// Swap the pivot with the last element
		std::swap(a[pivotIndex], a[rightIndex]);

		// Variable to hold the swap slot index
		int i = leftIndex;

		// Loop through the array elements
		for (int j = leftIndex; j < rightIndex; j++) {
			// Check if the 'SortType' is set for 'ASCENDING'
			if (order == SortType::ASCENDING) {
				// See if the item needs swapped
				if (a[j] <= pivotValue) {	
					// Swap elements
					std::swap(a[i], a[j]);

					// Increase swap slot
					i++;

					// Increase swap count
					(*swaps)++;
				}
			}
			// 'SortType' is set to 'DESCENDING
			else {
				// See if the item needs swapped
				if (a[j] >= pivotValue) {
					// Swap elements
					std::swap(a[i], a[j]);

					// Increase swap slot
					i++;

					// Increase swap count
					(*swaps)++;
				}
			}
		}

		// Swap pivot item in place
		std::swap(a[i], a[rightIndex]);

		// Return last swap location
		return i;
	}

	// Function for sorting the array list via quick sort method
	template <class T>
	void QuickSort(ArrayListV2<T>& a, SortType order, int n, int* swaps) {
		// Call the internal recursion function
		// ... Reason for this is so the user doesnt need to know index range
		QuickSortRecursion(a, order, 0, n - 1, swaps);
	}	

	// Function to randomize an array list
	template <class T>
	int BinarySearch(const ArrayListV2<T>& a, SortType order, const T value, long int* comparisons = nullptr) {
		// Implement here...
		// return the index of (on of) the occurence(s) of the
		// ... in the array list or -1 if not found

		// Variable to hold the length of the array
		unsigned int n = a.Size();

		// Variable to hold the left index of the section
		unsigned int left = 0;

		// Variable to hold the right index of the section
		unsigned int right = n - 1;

		// Loop
		while (left <= right) {
			// Variable to hold the mid point of the section
			unsigned int middle = (left + right) / 2;

			// Check if comparisions are being counted
			if (comparisons != nullptr) {
				(*comparisons)++;
			}

			// Check if the middle slot item is desired value
			if (a[middle] == value) {
				return middle;
			}

			// Check if the 'SortType' is set for 'ASCENDING'
			if (order == SortType::ASCENDING) {
				// Check if 'value' is to the left of 'middle'
				if (value < a[middle]) {
					right = middle - 1;
				}
				// 'value' is to the right of 'middle'
				else {
					left = middle + 1;
				}
			}
			// 'SortType' is set to 'DESCENDING
			else {
				// Check if 'value' is to the left of 'middle'
				if (value > a[middle]) {
					right = middle - 1;
				}
				// 'value' is to the right of 'middle'
				else {
					left = middle + 1;
				}
			}
		}

		return -1;
	}

	// Function for sorting the array list via bubble sort method
	template <class T>
	unsigned int BubbleSort(ArrayListV2<T>& a, SortType order) {
		// Variable to hold swap status 
		bool swapped = false;

		// Variable to hold the number of swaps preformed
		unsigned int swapCount = 0;

		// Variable to hold the lenght of the array
		unsigned int n = a.Size();

		// Check if the 'SortType' is set for 'ASCENDING'
		if (order == SortType::ASCENDING) {
			// Perform (n - 1) loops through the list
			for (unsigned int i = 0; i < (n - 1); i++) {
				// Reset swap status
				swapped = false;

				// Check for out-of-place neighbors
				for (unsigned int j = 0; j < (n - 1 - i); j++) {
					// Check if swap is needed
					if (a[j] > a[j + 1]) {
						// Swap the two elements
						std::swap(a[j], a[j + 1]);

						// Set swap status
						swapped = true;

						// Increase swap count
						swapCount++;
					}
				}

				// End sort if all items are sorted
				if (!swapped) {
					break;
				}
			}
		}
		// 'SortType' is set to 'DESCENDING
		else {
			// Preform (n - 1) loops through the list
			for (unsigned int i = 0; i < (n - 1); i++) {
				// Reset swap status
				swapped = false;

				// Check for out-of-place neighbors
				for (unsigned int j = 0; j < (n - 1 - i); j++) {
					// Check if swap is needed
					if (a[j] < a[j + 1]) {
						// Swap the two elements
						std::swap(a[j], a[j + 1]);

						// Set swap status
						swapped = true;

						// Increase swap count
						swapCount++;
					}
				}

				// End sort if all items are sorted
				if (!swapped) {
					break;
				}
			}
		}
		
		return swapCount;
	}

	// Function to randomize an array list using the Fisher-Yates algorithm
	template <class T>
	void Shuffle(ArrayListV2<T>& a) {
		// Get the size of the array
		unsigned int n = a.Size();

		// Seed/prepare the random generator
		std::random_device generator;
		std::mt19937 mt(generator()); 

		// Shuffle loop
		for (unsigned int i = n - 1; i > 0; i--) {
			// Set the random generator ranges
			std::uniform_int_distribution<unsigned int> distribution(0, i - 1);
			
			// Generate random number number
			unsigned int chosen = distribution(mt);

			// Swap chosen slot with index slot
			std::swap(a[i], a[chosen]);
		}

		return;
	}
}

#endif