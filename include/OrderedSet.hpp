#ifndef ORDERED_SET_HPP
#define ORDERED_SET_HPP

namespace ssuds {
	template <class T>
	class OrderedSet {
	protected:
		// Class structure to handle tree node items
		class _Node {
		public:
			// Variable to hold the data inside the node
			T _data;

			// Variable to hold the left node
			_Node* _left;

			// Variable to hold the right node
			_Node* _right;

			// Constructor
			_Node(const T& val) : _data(val), _left(nullptr), _right(nullptr) {}

			// Recursive function to insert a value in the proper placement in the tree
			bool insert_recursive(const T& val) {
				// Check if 'val' needs to be placed to the left
				if (val < _data) {
					// Check if there is an existing left node
					if (_left == nullptr) {
						_left = new _Node(val);
						return true;
					}
					else {
						_left->insert_recursive(val);
					}
				}
				// Check if 'val' needs to be placed to the right
				else if (val > _data) {
					// Check if there is an existing right node
					if (_right == nullptr) {
						_right = new _Node(val);
						return true;
					}
					else {
						_right->insert_recursive(val);
					}
				}
				// Duplicated value
				else {
					// "Hold" value since it is duplicated
					return false;
				}
			}
		};

		// Variable to hold the starting node of the tree
		_Node* _root;

		// Variable to hold the size of the tree
		unsigned int _size;

	public:
		// Constructor
		OrderedSet() : _size(0), _root(nullptr) {
			// Empty
		}

		// Function to get the size of the tree
		unsigned int size() const {
			return _size;
		}

		// Function to insert a value into the tree
		// .. Return true if the value is added
		bool insert(const T& val) {
			// Check if the list is empty
			if (_size == 0) {
				_root = new _Node(val);
				_size = 1;
				return true;
			}
			// List already has root
			else {
				if (_root->insert_recursive(val)) {
					_size++;
					return true;
				}
				else {
					return false;
				}
				
			}
		}
	};
}

#endif