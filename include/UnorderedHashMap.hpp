#ifndef UNORDERED_HASH_MAP
#define UNORDERED_HASH_MAP

#include <utility>
#include <functional>
#include <ostream>
#include <sstream>

#include <iostream>

namespace ssuds {
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
		/**
		* @brief Nested class for iterator functionality.
		*/
		class UnorderedMapIterator {
		protected:
			/**
			* @brief Pointer to an UnorderedMap.
			*/
			UnorderedMap* _ptr;

			/**
			* @brief Variable to hold the iterator's index.
			*/
			int _index;

			/**
			* @brief Function to move _index to the next valid slot.
			*/
			void moveIndex() {
				// Increment while index is under capacity, and slot is NOT used
				while (_index < _ptr->_capacity && _ptr->_tableUsed[_index] != true) {
					_index++;
				}
			}

		public:
			/**
			* @brief Iterator instance constructor.
			*
			* @param map The UnorderedMap to iterate over.
			* @param i The initial index.
			*/
			UnorderedMapIterator(UnorderedMap* map, int i) : _ptr(map), _index(i) {
				moveIndex();
			}

			// === Operator Overloads ===s
			/**
			* @brief Dereference operator.
			*
			* @return The pair at the current index.
			*/
			std::pair<K, V>& operator*() const {
				return _ptr->_tableData[_index];
			}

			/**
			* @brief Increment operator.
			*
			* @return A reference to the iterator after incrementing.
			*/
			UnorderedMapIterator& operator++() {
				++_index;
				moveIndex();
				return *this;
			}

			/**
			* @brief Equal operator.
			*
			* @param other The other iterator to compare with.
			*
			* @return True if the iterators are equal, false otherwise.
			*/
			bool operator==(const UnorderedMapIterator& other) const {
				return _index == other._index || _ptr == other._ptr;
			}

			/**
			* @brief Not equal operator.
			*
			* @param other The other iterator to compare with.
			*
			* @return True if the iterators are not equal, false otherwise.
			*/
			bool operator!=(const UnorderedMapIterator& other) const {
				return _index != other._index || _ptr != other._ptr;
			}

			/**
			* @brief Getter for index.
			*
			* @return The current index.
			*/
			unsigned int index() const {
				return _index;
			}
		};

		/**
		* @brief Constructor for the UnorderedMap class.
		*
		* @param maxCapacity The maximum capacity of the map. Default value is 10.
		*/
		UnorderedMap(const unsigned int maxCapacity = 10) : _size(0), _capacity(maxCapacity) {
			_tableData = new std::pair<K, V>[maxCapacity];
			_tableUsed = new bool[maxCapacity];

			for (unsigned int i = 0; i < maxCapacity; i++)
				_tableUsed[i] = false;
		}

		/**
		* @brief Destructor for the UnorderedMap class.
		*
		* Deletes the dynamically allocated memory for _tableData and _tableUsed.
		*/
		~UnorderedMap() {
			delete[] _tableData;
			delete[] _tableUsed;
		}

		/**
		* @brief Overloads the output stream operator for the UnorderedMap class.
		*
		* @param oss The output stream object.
		* @param map The UnorderedMap object to be output.
		*
		* @return The output stream object.
		*/
		friend std::ostream& operator<< (std::ostream& oss, const UnorderedMap& map) {
			oss << map.debug_print(true);
			return oss;
		}

		/**
		* @brief Overloads the subscript operator for the UnorderedMap class.
		*
		* @param key The key to access the value.
		*
		* @return The value associated with the key.
		*/
		V& operator[] (const K& key) {
			unsigned int desiredLocation = hashLocation(key);

			// Loop from the desired location to the next empty slot
			while (_tableUsed[desiredLocation] == true) {
				// Check if the key in that slot is the desired key
				if (_tableData[desiredLocation].first == key) {
					return _tableData[desiredLocation].second;
				}

				desiredLocation = (desiredLocation + 1) % _capacity;
			}

			// Check if 60% of the capacity is used
			if (_size >= (_capacity * 0.6))
				grow();

			_tableUsed[desiredLocation] = true;
			_tableData[desiredLocation].first = key;
			_size++;
			return _tableData[desiredLocation].second;
		}

		/**
		* @brief Method to get the size of the map.
		*
		* @return The number of elements in the map.
		*/
		unsigned int size() const {
			return _size;
		}

		/**
		* @brief Method to get the capacity of the map.
		*
		* @return The maximum number of elements the map can hold.
		*/
		unsigned int capacity() const {
			return _capacity;
		}

		/**
		* @brief Method used to check if the map contains a key-value pair.
		*
		* @param key The key to search for.
		*
		* @return True if the key is found, false otherwise.
		*/
		bool contains(const K& key) const {
			int result = locateKey(key);

			// Check if the key was located
			if (result == -1)
				return false;
			else
				return true;
		}

		/**
		* @brief Method used to find a key-value pair.
		*
		* @param key The key to search for.
		*
		* @return An iterator pointing to the found key-value pair, or end() if not found.
		*/
		UnorderedMapIterator find(const K& key) const {
			int result = locateKey(key);

			// Check if the key was located
			if (result == -1)
				return end();
			else
				return UnorderedMapIterator(const_cast<UnorderedMap*>(this), result);
		}

		/**
		* @brief Method used to remove a pair.
		*
		* @param iter The iterator pointing to the pair to be removed.
		*/
		void remove(const UnorderedMapIterator& iter) {
			int index = iter.index();

			// Check for a valid index and that the slot is used
			if (index >= 0 && index < _capacity && _tableUsed[index]) {
				_tableUsed[index] = false;
				_size--;

				removeRehash();
			}
		}

		/**
		* @brief Method to debug print the map (empty included).
		*
		* @param hideEmpty Whether to hide empty slots or not.
		*
		* @return A string representation of the map.
		*/
		std::string debug_print(const bool hideEmpty = false) const {
			std::stringstream oss;
			unsigned int printedItems = 0;

			// Loop an count items in map
			for (unsigned int i = 0; i < _capacity; i++) {
				// Check if slot is used or if empty slots are wanted
				if (_tableUsed[i] == true || !hideEmpty)
					printedItems++;
			}

			oss << "{";

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

			oss << "}";
			return oss.str();
		}

		/**
		* @brief Method to get the beginning of the iterator.
		*
		* @return An iterator pointing to the beginning of the map.
		*/
		UnorderedMapIterator begin() {
			UnorderedMapIterator iter(this, 0);

			return iter;
		}

		/**
		* @brief Method to get the end of the iterator.
		*
		* @return An iterator pointing to the end of the map.
		*/
		UnorderedMapIterator end() const {
			return UnorderedMapIterator(const_cast<UnorderedMap*>(this), _capacity);
		}


	private:
		/**
		* @brief Calculates the hash location for a given key.
		*
		* @param val The key to calculate the hash for.
		*
		* @return The hash location for the key.
		*/
		unsigned int hashLocation(const K val) const {
			unsigned int hash = _hashGenerator(val);
			return hash % _capacity;
		}
		
		/**
		* @brief Grows the map by doubling its capacity.
		*/
		void grow() {
			unsigned int oldCapacity = _capacity;
			_capacity *= 2;
			std::pair<K, V>* oldTableData = _tableData;
			bool* oldTableUsed = _tableUsed;

			_tableData = new std::pair<K, V>[_capacity];
			_tableUsed = new bool[_capacity];

			for (unsigned int i = 0; i < _capacity; i++)
				_tableUsed[i] = false;

			_size = 0;

			for (unsigned int i = 0; i < oldCapacity; i++) {
				if (oldTableUsed[i])
					(*this)[oldTableData[i].first] = oldTableData[i].second;
			}

			delete[] oldTableData;
			delete[] oldTableUsed;
		}

		/**
		* @brief Locates a key in the map.
		*
		* @param key The key to locate.
		*
		* @return The index of the key in the map, or -1 if not found.
		*/
		int locateKey(const K& key) const {
			unsigned int desiredLocation = hashLocation(key);

			// Loop from the desired location to the next empty slot
			while (_tableUsed[desiredLocation] == true) {
				// Check if the key in that slot is the desired key
				if (_tableData[desiredLocation].first == key) {
					return desiredLocation;
				}

				desiredLocation = (desiredLocation + 1) % _capacity;
			}

			return -1;
		}

		/**
		* @brief Rehashes the map after a removal.
		*/
		void removeRehash() {
			std::pair<K, V>* oldTableData = _tableData;
			bool* oldTableUsed = _tableUsed;
			unsigned int oldCapacity = _capacity;

			_tableData = new std::pair<K, V>[_capacity];
			_tableUsed = new bool[_capacity];

			_size = 0;

			// Loop through the old map
			for (unsigned int i = 0; i < oldCapacity; i++) {
				// Check if the old map slot is filled
				if (oldTableUsed[i] == true)
					(*this)[oldTableData[i].first] = oldTableData[i].second;
			}

			delete[] oldTableData;
			delete[] oldTableUsed;
		}
	};
}

#endif