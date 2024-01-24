#ifndef ARRAY_LIST_V2_H
#define ARRAY_LIST_V2_H

#include <ostream>
#include <iostream>

namespace ssuds {
	template <class L>

	class ArrayListV2 {
	protected:
		/// The number of USED slots in the array
		unsigned int _size;

		/// Minimum number of AVAILABLE slots in the array
		static const unsigned int _capacityMinimum = 1;

		/// The number of AVAILABLE slots in the array
		unsigned int _capacity;

		/// Pointer to array
		L* _data;

		/***************************************************************************//**
		* @brief Doubles the capacity of the array list.
		*
		* Increase the capacity of the array list by doubling it, much more efficent
		* way then adding one spot at a time and transferring the old array over.
		******************************************************************************/
		void Grow() {
			// Double the capacity of the list
			_capacity *= 2;

			// Allocate memory for the new array
			L* tempData = new L[_capacity];

			// Copy over the data from the old array
			for (unsigned int i = 0; i < _size; i++) {
				tempData[i] = _data[i];
			}

			// Unallocate the old array
			delete[] _data;

			// Set the '_data' pointer to 'tempData'
			_data = tempData;
		}

	public:
		/***************************************************************************//**
		* @brief Constructor of ArrayList class.
		*
		* Initializes default values for ArrayList.
		******************************************************************************/
		ArrayListV2() {
			// Set defualt values
			_size = 0;
			_capacity = _capacityMinimum;

			// Allocate memory for the array
			_data = new L[_capacity];
		}

		/***************************************************************************//**
		* @brief Copy constructor of ArrayList class.
		*
		* Copies arrays for ArrayListV2.
		******************************************************************************/
		ArrayListV2(const ArrayListV2& other) {
			_size = other._size;
			_capacity = other._capacity;

			_data = new L[_capacity];

			for (unsigned int i = 0; i < other._size; i++) {
				_data[i] = other[i];
			}
		}

		/***************************************************************************//**
		* @brief Destructor of ArrayList class.
		*
		* Deallocates memory used for ArrayList.
		******************************************************************************/
		~ArrayListV2() {
			// Unallocate memory used by the array
			delete[] _data;
		}

		/***************************************************************************//**
		* @brief Append a item to the end of the array.
		*
		* @param s The item to be appended.
		******************************************************************************/
		void Append(const L& item) {
			// Check if the list capacity needs to be expanded
			if (_size == _capacity) {
				Grow();
			}

			// Add 'item' to the end
			_data[_size] = item;

			// Increase array size
			_size++;
		}

		/***************************************************************************//**
		* @brief Gets the current AVALIABLE slots of the array list.
		*
		* @return The current AVALIABLE slots of the list.
		******************************************************************************/
		unsigned int Capacity() const {
			return _capacity;
		}

		/***************************************************************************//**
		* @brief Gets the current USED spots of the array list.
		*
		* @return The current USED spots of the list.
		******************************************************************************/
		unsigned int Size() const {
			return _size;
		}

		/***************************************************************************//**
		* @brief Insert a item at a set position in the array.
		*
		* @param s The item to be inserted.
		* @param position The index for the item to be inserted at.
		******************************************************************************/
		void Insert(const L& item, const unsigned int index) {
		//void Insert(const L& item, unsigned int index) {
			// Check that index is in range of the array
			if (index >= 0 && index < _size) {
				// Check that the array is capable of insertion
				// 1. If the array is empty
				// 2. If the position will be the last slot
				if ((_size == 0 && _capacity == _capacityMinimum) || (index == (_size + 1))) {
					// Append the item instead
					Append(item);

					return;
				}

				// === Insertion ===
				// Check if the array need to be grown
				if (_size == _capacity) {
					Grow();
				}

				// Increase the array size
				_size++;

				// Loop through the back items of the array until reaching 'index'
				for (unsigned int i = _size; i > index; i--) {
					// Copy everything one spot right in the array so the 'index' is empty
					_data[i] = _data[i - 1];
				}

				// Insert item
				_data[index] = item;
			}
			else {
				throw std::out_of_range("Provided position is out of range!");
			}
		}

		/***************************************************************************//**
		* @brief Clears the array and resets it back to the beginning values.
		*
		* Similar to the destructor but meant to be used during list's lifetime.
		******************************************************************************/
		void Clear() {
			// Unallocate array memory
			delete[] _data;

			// Reset variables to defaule
			_size = 0;
			_capacity = _capacityMinimum;

			// Allocate memory for array
			_data = new L[_capacity];
		}

		/***************************************************************************//**
		* @brief Gets a item at a defined index.
		*
		* @param index The position of the desired item.
		*
		* @return The a referene of the item at position of the index value.
		******************************************************************************/
		L& operator[](const unsigned int index) const {
			// Check that 'index' is in range
			if (index >= 0 && index < _size) {
				// Return the irem at position 'index'
				return _data[index];
			}
			else {
				throw std::out_of_range("Provided position is out of range!");
			}
		}

		/***************************************************************************//**
		* @brief Find a item in the array, with a optional starting location.
		*
		* @param s Item to be found.
		* @param index Desired starting position (optional).
		*
		* @return Index the item is found at or -1 if not found.
		******************************************************************************/
		int Find(const L& item, const unsigned int index = 0) const {
			// Check that the 'index' is in range
			if (index >= 0 && index < _size) {
				// Loop through the array
				for (unsigned int i = index; i < _size; i++) {
					// Check that 'item' has been found
					if (_data[i] == item) {
						// Return found index position
						return i;
					}
				}

				// 'item' was not found
				return -1;
			}
			else {
				throw std::out_of_range("Provided position is out of range");
			}
		}

		/***************************************************************************//**
		* @brief Remove a item at a given index position.
		*
		* @param index Position of the item to remove.
		******************************************************************************/
		void Remove(const unsigned int index) {
			// Check that 'index' is in range
			if (index >= 0 && index < _size) {
				// Loop from the desired index to the end of the array
				for (unsigned int i = index; i < _size; i++) {
					// Copy everything one spot left in the array
					_data[i] = _data[i + 1];
				}

				// Decrease the array size
				_size--;

				// Check if the array can be shrunk
				if ((_capacity / 2) == _size) {
					// Half the array's capacity
					_capacity /= 2;

					// Allocate memory for the new array
					L* tempData = new L[_capacity];

					// Copy over the old data
					for (unsigned int i = 0; i < _size; i++) {
						tempData[i] = _data[i];
					}

					// Delete the old array
					delete[] _data;

					// Set the '_data' pointer to the 'tempData' pointer
					_data = tempData;
				}
			}
			else {
				throw std::out_of_range("Provided position is out of range!");
			}
		}

		/***************************************************************************//**
		* @brief Remove all instances of a desired item from the array.
		*
		* @param s Item to find and remove from the entire array.
		*
		* @return The number of times the given item was removed.
		******************************************************************************/
		int Remove_All(const L& item) {
			// Variable to hold the position of the 'item' found for removal
			//	prevents unneeded loops through the array. Loops once now.
			unsigned int cur_index = 0;

			// Number of items removed from the array
			unsigned int num_removed = 0;

			// While 'cur_index' is in range of the array's size
			while (cur_index >= 0 && cur_index < _size) {
				// Find the next occurence
				cur_index = Find(item, cur_index);

				// If the occurence is found
				if (cur_index >= 0) {
					// Remove the item at the found index
					Remove(cur_index);

					// Increase the removed count
					num_removed++;
				}
			}

			return num_removed;
		}

		/***************************************************************************//**
		* @brief Output the array in a Python like format
		*
		* @param os Stream the array should be outputted via.
		*
		* @param a Array output will be from.
		*
		* @return The array in Python like format via chosen stream.
		******************************************************************************/
		friend std::ostream& operator<< (std::ostream& os, const ArrayListV2& a) {
			for (unsigned int i = 0; i < a.Size(); i++) {
				if (i == 0) {
					os << "[" << a[i];
				}
				else if (i == (a.Size() - 1)) {
					os << ", " << a[i] << "]" << std::endl;
				}
				else {
					os << ", " << a[i];
				}
			}

			return os;
		}

		/***************************************************************************//**
		* @brief 'Deep-copy' the array to another instance.
		*
		* @param other Array to copy from.
		*
		* @return The new copy of the array.
		******************************************************************************/
		ArrayListV2& operator= (const ArrayListV2& other) {
			_size = other._size;
			_capacity = other._capacity;

			delete[] _data;

			// Allocate memory for the new 'deep-copy'
			_data = new L[_capacity];

			// Loop through copying array
			for (unsigned int i = 0; i < other.Size(); i++) {
				// Copy over old data
				_data[i] = other[i];
			}

			return *this;
		}
	};
}

#endif