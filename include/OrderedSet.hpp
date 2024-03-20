#ifndef ORDERED_SET_HPP
#define ORDERED_SET_HPP

#include <iostream>
#include <Array_List_v2.hpp>
#include <Stack.hpp>

namespace ssuds {
	template <class T>
	class OrderedSet {
	public:
		// Enum to hold the traversal type
		enum TraversalType {
			PRE_ORDER,
			IN_ORDER,
			POST_ORDER
		};

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

			// Recursive method to insert a value in the proper placement in the tree
			bool insertRecursive(const T& val) {
				// Check if 'val' needs to be placed to the left
				if (val < _data) {
					// Check if there is an existing left node
					if (_left == nullptr) {
						_left = new _Node(val);
						return true;
					}
					else
						_left->insertRecursive(val);
				}
				// Check if 'val' needs to be placed to the right
				else if (val > _data) {
					// Check if there is an existing right node
					if (_right == nullptr) {
						_right = new _Node(val);
						return true;
					}
					else
						_right->insertRecursive(val);
				}
				// Duplicated value
				else
					return false;
			}

			// Recursive method to traverse the tree
			void traversalRecursive(ssuds::ArrayListV2<T>& values, TraversalType type) const {
				switch (type) {
				case PRE_ORDER:
					values.Append(_data);

					// Check if there is a node left
					if (_left != nullptr)
						_left->traversalRecursive(values, type);

					// Check if there is a node right
					if (_right != nullptr)
						_right->traversalRecursive(values, type);

					break;
				case IN_ORDER:
					// Check if there is a node left
					if (_left != nullptr)
						_left->traversalRecursive(values, type);

					values.Append(_data);

					// Check if there is a node right
					if (_right != nullptr)
						_right->traversalRecursive(values, type);

					break;
				case POST_ORDER:
					// Check if there is a node left
					if (_left != nullptr)
						_left->traversalRecursive(values, type);

					// Check if there is a node right
					if (_right != nullptr)
						_right->traversalRecursive(values, type);

					values.Append(_data);

					break;
				}
			}

			// Recursive method for removing nodes from the tree
			void clearRecursive(_Node* node) {
				if (node == nullptr)
					return;

				clearRecursive(node->_left);
				clearRecursive(node->_right);
				delete node;
			}

			// Recursive method to check if a value is contained in the tree
			bool containsRecursive(const T& val) const {
				// Check if the node is nullptr, if so val is not contained
				if (this == nullptr)
					return false;
				// Check if node data is val, val is contained
				else if (val == _data)
					return true;
				// Check if node data is less than val, go left
				else if (val < _data)
					return _left->containsRecursive(val);
				// Check if node data is greater than val, go right
				else if (val > _data)
					return _right->containsRecursive(val);
			}

			// Recursive method to get the height of the tree
			unsigned int heightRecursive(const _Node* node) const {
				unsigned int leftHeight = 0, rightHeight = 0;

				if(node->_left != nullptr)
					leftHeight = 1 + heightRecursive(node->_left);

				if (node->_right != nullptr)
					rightHeight = 1 + heightRecursive(node->_right);

				return leftHeight > rightHeight ? leftHeight : rightHeight;
			}

			// Recursive method to erase a node of the tree
			_Node* eraseTraversal(const T& val) {
				// Check if the val is current nodes data
				if (val == _data) {
					// Check if node is a leaf
					if (_left == nullptr && _right == nullptr)
						return nullptr;

					// Check for single child nodes
					if (_left == nullptr && _right != nullptr) {
						_Node* replacer = _right;
						delete this;
						return replacer;
					}
					else if (_left != nullptr && _right == nullptr) {
						_Node* replacer = _left;
						delete this;
						return replacer;
					}

					// Node with two children
					_Node* replacer = inorderSuccessor(_right);
					_data = replacer->_data;
					_right = _right->eraseTraversal(replacer->_data);
				}
				// Check if the val is less than current nodes data
				else if (val < _data) {
					_Node* replacer = _left->eraseTraversal(val);
					
					// Check that left wasn't already removed
					if (replacer != _left) {
						delete _left;
						_left = replacer;
					}
				}
				// Check if the val is greater than current nodes data
				else if (val > _data) {
					_Node* replacer = _right->eraseTraversal(val);

					// Check that right wasn't alread
					if (replacer != _right) {
						delete _right;
						_right = replacer;
					}
				}
			}

			private:
				_Node* inorderSuccessor(_Node* node) const {
					_Node* current = node;

					while (current && current->_left != nullptr)
						current = current->_left;

					return current;
				}
		};
		
		// Variable to hold the starting node of the tree
		_Node* _root;

		// Variable to hold the size of the tree
		unsigned int _size;

	public:
		// Class structure to handle iterator
		class Iterator {
		protected:
			// Stack to keep track of node pointers
			ssuds::Stack<_Node*> nodeStack;

			// Pointer to a node
			_Node* _ptr;
		public:
			// Constructor
			Iterator(_Node* node) : _ptr(node) {}

			// Remaining code here...
		};

		// Constructor
		OrderedSet() : _size(0), _root(nullptr) {
			// Empty
		}

		// Destructor
		~OrderedSet() {
			clear();
		}

		// Ostream operator
		friend std::ostream& operator<<(std::ostream& oss, const OrderedSet<T>& set) {
			ssuds::ArrayListV2<T> values = set.traversal(IN_ORDER);

			// Iterate through 'values'
			for (T& val : values)
				oss << val << " ";

			return oss;
		}

		// Method to insert a value into the tree
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
				// Check if something was inserted
				if (_root->insertRecursive(val)) {
					_size++;
					return true;
				}
				// Nothing was inserted
				else
					return false;
				
			}
		}

		// Method to traverse through the tree
		ssuds::ArrayListV2<T> traversal(TraversalType type = IN_ORDER) const {
			// Check that root is not 'nullptr'
			if(_root == nullptr)
				throw std::out_of_range("ERROR: Unable to perform traversal, no root!");

			ssuds::ArrayListV2<T> values;
			_root->traversalRecursive(values, type);

			return values;
		}

		// Method to balance the tree
		void rebalance() {
			// Check that root is not 'nullptr'
			if (_root == nullptr)
				throw std::out_of_range("ERROR: Unable to perform rebalance, no root");

			ssuds::ArrayListV2<T> orderedValues;
			_root->traversalRecursive(orderedValues, ssuds::OrderedSet<T>::IN_ORDER);

			clear();
			balanceRecursive(orderedValues, 0, orderedValues.Size() - 1);
		}

		// Method to clear the tree
		void clear() {
			_root->clearRecursive(_root);
			_root = nullptr;
			_size = 0;
		}

		// Method to get the size of the tree
		unsigned int size() const {
			return _size;
		}

		// Method to check if a value is in the tree
		bool contains(const T& val) const {
			// Check that root is not 'nullptr'
			if (_root == nullptr)
				throw std::out_of_range("ERROR: Unable to perform contain, no root!");

			return _root->containsRecursive(val);
		}

		// Method to get the height of the tree
		unsigned int getHeight() const {
			return _root->heightRecursive(_root);
		}

		// Method for removing a node in the tree
		bool erase(const T& val) {
			// Check that root is not 'nullptr'
			if (_root == nullptr)
				throw std::out_of_range("ERROR: Unable to perform erase, no root!");
			
			// Check that the desired value is in the tree
			if (!contains(val))
				return false;

			_root->eraseTraversal(val) == nullptr ? false : true;
		}

	private:
		// Function to get the middle of two values
		unsigned int getMiddle(const unsigned int start, const unsigned int end) {
			return (start + end) / 2;
		}

		// Function to perform balancing recursive code
		void balanceRecursive(const ssuds::ArrayListV2<T>& values, const int start, const int end) {
			// Check if starting and ending are valid
			if (start > end)
				return;

			int index = getMiddle(start, end);
			insert(values[index]);
			balanceRecursive(values, start, index - 1);
			balanceRecursive(values, index + 1, end);
		}
	};
}

#endif