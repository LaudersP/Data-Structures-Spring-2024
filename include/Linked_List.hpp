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
			* Initializes defaule values with data being set to a provided value.
			******************************************************************************/
			_Node(const L& data) {
				// Set default values
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
		* @param s The item to be appended.
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
		* @param s The item to be prepended.
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
	};
}

#endif