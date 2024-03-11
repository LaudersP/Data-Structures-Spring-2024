#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <ostream>

namespace ssuds {
	template <class L>
	class LinkedList {
	protected:
		class _Node {
		public:
			// Variable to hold the data inside the node
			L _data;

			// Variable to hold the next node address
			_Node* _next;

			// Variable to hold the previous node address
			_Node* _prev;

			/***************************************************************************//**
			* @brief Constructor of internal _Node class.
			*
			* Initializes default values for internal _Node class..
			******************************************************************************/
			_Node() {
				// Set default values
				_data = NULL;
				_next = nullptr;
				_prev = nullptr;
			} 

			/***************************************************************************//**
			* @brief Override constructor of internal _Node class.
			*
			* Initializes default values with data being set to a provided value.
			******************************************************************************/
			_Node(const L& data) {
				// Set default with provided values
				_data = data;
				_next = _prev = nullptr;
			}
		};

		// Variable to hold the starting node address
		_Node* _start;

		// Variable to hold the ending node address
		_Node* _end;

		// Variable to hold the size of the linked list
		unsigned int _size;
	public:
		class LinkedListIterator {
		protected:
			// Pointer to an LinkedList node
			_Node* _ptr;

			// Iterator index
			unsigned int _index;
		public:
			/***************************************************************************//**
			* @brief Constructor of internal LinkedListIterator class.
			*
			* Initializes default values for internal LinkedListIterator class.
			******************************************************************************/
			LinkedListIterator() {
				// Set default values
				_ptr = nullptr;
				_index = 0;
			}

			/***************************************************************************//**
			* @brief Override constructor of LinkedListIterator class.
			*
			* Initializes default values when data is provided.
			******************************************************************************/
			LinkedListIterator(_Node* node, unsigned int index) {
				// Set default with provided values
				_ptr = node;
				_index = index;
			}

			/***************************************************************************//**
			* @brief Dereference operator.
			*
			* @return A reference to the "current" value.
			******************************************************************************/
			L& operator*() const {
				return _ptr->_data;
			}

			/***************************************************************************//**
			* @brief Increment operator .
			*
			* Advance iterator to the next value.
			* 
			* @return Iterator.
			******************************************************************************/
			LinkedListIterator& operator++() {
				// Get the node after
				_ptr = _ptr->_next;

				// Increase index
				++_index;

				return *this;
			}

			/***************************************************************************//**
			* @brief Decrement operator.
			*
			* Decrease iterator to the previous value.
			* 
			* @return Iterator.
			******************************************************************************/
			LinkedListIterator& operator--() {
				// Get the node before
				_ptr = _ptr->_prev;
				
				// Decrease index
				--_index;

				return *this;
			}

			/***************************************************************************//**
			* @brief Equal comparison operator.
			*
			* Test if two iterators are equal.
			* 
			* @return Return true if this iterator is iterating through the same LinkedList
			* and is at the same spot as 'other'.
			******************************************************************************/
			bool operator==(const LinkedListIterator& other) const {
				// Return 'TRUE' if they are alike 'other', false if aren't
				return _index == other._index && _ptr == other._ptr;
			}

			/***************************************************************************//**
			* @brief Nonequal comparison operator
			*
			* Test if two iterators are not equal.
			* 
			* @return Return true if this iterator is iterating through a different LinkedList
			* and is at a different spot as 'other'.
			******************************************************************************/
			bool operator!=(const LinkedListIterator& other) const {
				// Return 'TRUE' if they aren't alike 'other', false if are
				return !(*this == other);
			}

			/***************************************************************************//**
			* @brief Function to get the index.
			*
			* Gets the index at the current moment.
			*
			* @return The index.
			******************************************************************************/
			unsigned int Index() const{
				return _index;
			}

			_Node* Pointer() const {
				return _ptr;
			}
		};
		/***************************************************************************//**
		* @brief Constructor of LinkedList class.
		*
		* Initializes default values for LinkedList.
		******************************************************************************/
		LinkedList() {
			// Set default values
			_start = _end = nullptr;
			_size = 0;
		}

		/***************************************************************************//**
		* @brief Deconstructor of LinkedList class.
		*
		* Deallocates memory used for LinkedList.
		******************************************************************************/
		~LinkedList() {
			Clear();
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
				// Variable to hold current node
				_Node* current;

				// See if it would be better the start from the beginning or end
				if (index <= ((_size - 1) / 2)) {
					// Set current to the start address
					current = _start;

					// Loop to 'index'
					for (unsigned int i = 0; i < index; i++) {
						// Get the next node
						current = current->_next;
					}

					return current->_data;
				}
				else {
					// Set current to the end address
					current = _end;

					// Loop to 'index'
					for (unsigned int i = (_size - 1); i > index; i--) {
						// Get the next node
						current = current->_prev;
					}

					return current->_data;
				}
			}
			else {
				throw std::out_of_range("Index is out of range!");
			}
		}

		/***************************************************************************//**
		* @brief Output the LinkedList in a Python like format
		*
		* @param os Stream the LinkedList should be outputted via.
		*
		* @param LL LinkedList output will be from.
		*
		* @return The LinkedList in Python like format via chosen stream.
		******************************************************************************/
		friend std::ostream& operator<< (std::ostream& os, const LinkedList& LL) {
			// Check if the list is empty
			if (LL.Size() == 0) {
				os << "[]";
				return os;
			}

			// Get the beginning node
			_Node* current = LL._start;

			// Print Loop
			for (unsigned int i = 0; i < LL.Size(); i++) {
				if (i == 0) {
					os << "[" << current->_data;
				}
				else if (i == (LL.Size() - 1)) {
					os << ", " << current->_data << "]";
				}
				else {
					os << ", " << current->_data;
				}

				// Get the next node
				current = current->_next;
			}

			return os;
		}

		/***************************************************************************//**
		* @brief Append a item to the end of the LinkedList.
		*
		* @param item The item to be appended.
		******************************************************************************/
		void Append(const L& item) {
			// Create a new node
			_Node* nnode = new _Node(item);

			// Check if this will be the first node
			if (_size == 0) {
				// Set both the start and end pointers to the new node
				_start = _end = nnode;
			}
			// Node will be added 
			else {
				// Make the current last node point to the new node
				_end->_next = nnode;

				// Set the new nodes '_prev' pointer to the current end node
				nnode->_prev = _end;

				// Set the end pointer to the new node
				_end = nnode;
			}

			// Increment the list size 
			_size++;
		}

		/***************************************************************************//**
		* @brief Prepend an item to the beignning of the LinkedList.
		*
		* @param item The item to be prepended.
		******************************************************************************/
		void Prepend(const L& item) {
			// Create a new node
			_Node* nnode = new _Node(item);

			// Check if this will be the first node
			if (_size == 0) {
				// Set both the start and end pointers to the new node
				_start = _end = nnode;
			}
			// Node will be added
			else {
				// Make the new node to point to the current first node
				nnode->_next = _start;

				// Set the current first node to have new node as previous
				_start->_prev = nnode;

				// Set the start pointer to the new node
				_start = nnode;
			}

			// Increment the list size
			_size++;
		}

		/***************************************************************************//**
		* @brief Insert an item at a index in the LinkedList.
		*
		* @param index The position to be inserted.
		* 
		* @param item The item to be inserted.
		******************************************************************************/
		void Insert(unsigned int index, const L& item) {
			// Check 'index' for valid operation
			if (index == 0) {
				Prepend(item);
			}
			else if (index == _size) {
				Append(item);
			}
			else if (index >= 0 && index < _size) {
				// Variable to hold current node
				_Node* current;

				// Create a new node
				_Node* nnode = new _Node(item);

				// See if it would be better the start from the beginning or end
				if (index <= ((_size - 1) / 2)) {
					// Set current to the start address
					current = _start;

					// Loop to 'index'
					for (unsigned int i = 0; i < index - 1; i++) {
						// Get the next node
						current = current->_next;
					}

					// Set the new node previous to the current node
					nnode->_prev = current;

					// Set the new nodes next to that of current nodes
					nnode->_next = current->_next;

					// Set the node following current to point back to new node
					current->_next->_prev = nnode;

					// Set the current next to new node
					current->_next = nnode;
				}
				else {
					// Set current to the end address
					current = _end;

					// Loop to 'index'
					for (unsigned int i = (_size - 1); i > index; i--) {
						// Get the next node
						current = current->_prev;
					}

					// Set the new node nex to current node
					nnode->_next = current;

					// Set the new nodes prev to that of current nodes
					nnode->_prev = current->_prev;

					// Set the node before current to point forward to the new node
					current->_prev->_next = nnode;

					// Set the current prev to new node
					current->_prev = nnode;
				}

				// Increase size
				_size++;
			}
			else {
				throw std::out_of_range("Index is out of range!");
			}
		}

		/***************************************************************************//**
		* @brief Gets the current size of the LinkedList.
		*
		* @return The current spots of the LinkedList.
		******************************************************************************/
		unsigned int Size() const {
			return _size;
		}

		/***************************************************************************//**
		* @brief Clears the LinkedList and resets it back to the beginning values.
		*
		* Is what the destructor uses but meant to be used during list's lifetime.
		******************************************************************************/
		void Clear() {
			// Variable to hold the current node
			_Node* current = _start;

			// Loop through the LinkedList
			while (current != nullptr) {
				// Get the address to the next node
				_Node* next = current->_next;

				// Delete the current node
				delete current;

				// Set the current variable to the next node
				current = next;
			}

			// Reset the other LinkedList variables to default
			_start = _end = nullptr;
			_size = 0;
		}

		/***************************************************************************//**
		* @brief Used to get the beginning of the iterator.
		* 
		* @return The iterator pointing to the beginning of the LinkedList.
		******************************************************************************/
		LinkedListIterator begin() const {
			LinkedListIterator iter(_start, 0);
			return iter;
		}

		/***************************************************************************//**
		* @brief Used to get the ending of the iterator.
		* 
		* @return The iterator pointing to one slot past the end of the LinkedList
		******************************************************************************/
		LinkedListIterator end() const {
			LinkedListIterator iter(nullptr, _size);
			return iter;
		}

		/***************************************************************************//**
		* @brief Used to get the beginning of the reverse iterator.
		*
		* @return The iterator pointing to one slot past the end of the LinkedList
		******************************************************************************/
		LinkedListIterator rbegin() const {
			LinkedListIterator iter(_end, _size - 1);
			return iter;
		}

		/***************************************************************************//**
		* @brief Used to get the ending of the reverse iterator.
		*
		* @return The iterator pointing to one slot past the end of the LinkedList
		******************************************************************************/
		LinkedListIterator rend() const {
			LinkedListIterator iter(nullptr, -1);
			return iter;
		}

		/***************************************************************************//**
		* @brief Used to find an element in the LinkedList.
		* 
		* @param item The item to be located.
		*
		* @return The iterator pointing to the element.
		******************************************************************************/
		LinkedListIterator Find(const L& item) const {
			// Start from the beginning of the LinkedList
			LinkedListIterator it = begin();

			// Iterate through the list
			while (it != end()) {
				// Check the current element
				if (*it == item) {
					return it;
				}

				// Advance the iterator
				++it;
			}

			return end();
		}

		/***************************************************************************//**
		* @brief Used to remove an element from the LinkedList.
		*
		* @param spot The index pointing to the element.
		******************************************************************************/
		LinkedListIterator Remove(const LinkedListIterator& spot) {
			// Check that the list isn't empty
			if (_size == 0) {
				return end();
			}

			_Node* current = spot.Pointer();
			LinkedListIterator next_iter = spot;
			++next_iter;

			// Check if removing the first node
			if (current == _start) {
				_start = current->_next;

				if (_start)
					_start->_prev = nullptr;
				else
					_end = nullptr;

				delete current;
				_size--;

				return next_iter;
			}
			// Check if removing the last node
			else if (current == _end) {
				_end = current->_prev;
				_end->_next = nullptr;

				delete current;

				_size--;

				return end();
			}
			// Removing from the middle
			else {
				current->_prev->_next = current->_next;
				current->_next->_prev = current->_prev;

				delete current;

				_size--;

				return next_iter;
			}

			return spot;
		}
	};
}

#endif