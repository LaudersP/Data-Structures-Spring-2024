#ifndef UNORDERED_HASH_MAP
#define UNORDERED_HASH_MAP

#include <utility>
#include <functional>
#include <ostream>
#include <sstream>

#include <iostream>

namespace ssud {
	template <class K, class V>
	class UnorderedMap {
	protected:
		// Pointer to the hash map table
		std::pair<K, V>* _tableData;

		// Pointer to the used array
		bool* _tableUsed;

		// Variable to hold the number of elements
		unsigned int _size;

		// Variable to hold the number of slots
		unsigned int _capacity;

		// Hash generator
		std::hash<K> _hashGenerator;

	public:
		// Constructor
		UnorderedMap(const unsigned int maxCapacity = 10) : _size(0), _capacity(maxCapacity) {
			_tableData = new std::pair<K, V>[maxCapacity];
			_tableUsed = new bool[maxCapacity];

			for (unsigned int i = 0; i < maxCapacity; i++)
				_tableUsed[i] = false;
		}

		// Destructor
		~UnorderedMap() {
			delete[] _tableData;
			delete[] _tableUsed;
		}

		// Ostream operator
		friend std::ostream& operator<< (std::ostream& oss, const UnorderedMap& map) {
			oss << map.debug_print(true);
			return oss;
		}

		// Bracket operator
		V& operator[] (const K& key) {
			unsigned int desiredLocation = hashLocation(key);

			// Loop from the desired location to the next empty slot
			while (_tableUsed[desiredLocation] == true) {
				// Check if the key in that slot is the desired key
				if (_tableData[desiredLocation].first == key) {
					return _tableData[desiredLocation].second;
				}

				desiredLocation < _capacity ? desiredLocation++ : desiredLocation = 0;
			}

			// Check if 60% of the capacity is used
			if (_size >= (_capacity * .6))
				grow();

			_tableUsed[desiredLocation] = true;
			_tableData[desiredLocation].first = key;
			_size++;
			return _tableData[desiredLocation].second;
		}

		// Method to get the size of the map
		unsigned int size() const {
			return _size;
		}

		// Method to get the capacity of the map
		unsigned int capacity() const {
			return _capacity;
		}

		// Method used to check if the map contains a keys pair
		bool contains(const K& key) const {
			unsigned int desiredLocation = hashLocation(key);

			// Loop from the desired location to the next empty slot
			while (_tableUsed[desiredLocation] == true) {
				// Check if the key in that slot is the desired key
				if (_tableData[desiredLocation].first == key) {
					return true;
				}

				desiredLocation < _capacity ? desiredLocation++ : desiredLocation = 0;
			}
			
			return false;
		}

		// Method used to find a keys pair
		// EDIT: void to proper type once iterator is created!
		void find(const K& key) const {
			// Find code here ...
		}

		// Method used to remove a pair
		// EDIT: figure out the argument; key or iterator
		void Remove() {
			// Find code here ...
		}

		// Method to debug print the map (empty included)
		std::string debug_print(const bool hideEmpty = false) const {
			std::stringstream oss;
			unsigned int printedItems = 0;

			// Loop an count items in map
			for (unsigned int i = 0; i < _capacity; i++) {
				// Check if slot is used or if empty slots are wanted
				if (_tableUsed[i] == true || !hideEmpty)
					printedItems++;
			}

			oss << "OUTPUT: {";

			// Loop through the map
			for (unsigned int i = 0; i < _capacity; i++) {
				// Check if there is a value
				if (_tableUsed[i] == true) {
					oss << _tableData[i].first << ":" << _tableData[i].second;

					if (--printedItems > 0)
						oss << ", ";
				}
				else {
					// Check if the user wants empty spaces
					if (!hideEmpty) {
						oss << "NULL:0";

						if (--printedItems > 0)
							oss << ", ";
					}
				}
			}

			oss << "}\n\n";
			return oss.str();
		}

	private:
		// Function to hash the key value
		unsigned int hashLocation(const K val) const {
			unsigned int hash = _hashGenerator(val);
			return hash % _capacity;
		}
		
		// Function to grow the map
		void grow() {
			_capacity *= 2;
			std::pair<K, V>* tempData = new std::pair<K, V>[_capacity];
			bool* tempUsed = new bool[_capacity];

			// Loop through original map
			for (unsigned int i = 0; i < (_capacity / 2); i++) {
				// Check that the current spot is filled
				if (!_tableUsed[i])
					continue;

				unsigned int newLocation = hashLocation(_tableData[i].first);

				// Loop starting at the desired location
				while (tempUsed[newLocation] != false) {
					// Check if there is an item in this slot
					if (tempData[newLocation].first == "") {
						tempData[newLocation].first = _tableData[i].first;
						tempData[newLocation].second = _tableData[i].second;
						tempUsed[newLocation] = true;

						break;
					}

					newLocation <= _capacity ? newLocation++ : newLocation = 0;
				}
			}

			delete[] _tableData;
			delete[] _tableUsed;

			_tableData = tempData;
			_tableUsed = tempUsed;
		}
	};
}

#endif