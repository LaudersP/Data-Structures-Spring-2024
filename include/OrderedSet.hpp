#ifndef ORDERED_SET_HPP
#define ORDERED_SET_HPP

#include <iostream>
#include <Array_List_v2.hpp>

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
			bool insert_recursive(const T& val) {
				// Check if 'val' needs to be placed to the left
				if (val < _data) {
					// Check if there is an existing left node
					if (_left == nullptr) {
						_left = new _Node(val);
						return true;
					}
					else
						_left->insert_recursive(val);
				}
				// Check if 'val' needs to be placed to the right
				else if (val > _data) {
					// Check if there is an existing right node
					if (_right == nullptr) {
						_right = new _Node(val);
						return true;
					}
					else
						_right->insert_recursive(val);
				}
				// Duplicated value
				else
					return false;
			}

			// Recursive method to traverse the tree
			void traverse(ssuds::ArrayListV2<T>& values, TraversalType type) const {
				switch (type) {
				case PRE_ORDER:
					values.Append(_data);

					if (_left != nullptr)
						_left->traverse(values, type);

					if (_right != nullptr)
						_right->traverse(values, type);

					break;
				case IN_ORDER:
					if (_left)
						_left->traverse(values, type);

					values.Append(_data);

					if (_right)
						_right->traverse(values, type);

					break;
				case POST_ORDER:
					if (_left)
						_left->traverse(values, type);

					if (_right)
						_right->traverse(values, type);

					values.Append(_data);

					break;
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

		// Ostream operator
		friend std::ostream& operator<<(std::ostream& oss, const OrderedSet<T>& set) {
			ssuds::ArrayListV2<T> values = set.traversal(IN_ORDER);

			// Iterate through 'values'
			for (T& val : values)
				oss << val << " ";

			return oss;
		}

		// Method to get the size of the tree
		unsigned int size() const {
			return _size;
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
				if (_root->insert_recursive(val)) {
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
			_root->traverse(values, type);

			return values;
		}
	};
}

#endif