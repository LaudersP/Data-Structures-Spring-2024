#ifndef STACK_H
#define STACK_H

#include <Linked_List.hpp>

namespace ssuds {
	template <class T>
	class Stack {
	// Attributes
	protected:
		// LinkedList object
		LinkedList<T> _list;

		// Iterator 
		using Iterator = typename LinkedList<T>::LinkedListIterator;
	public:
		typename LinkedList<T>::LinkedListIterator begin() {
			return _list.begin();
		}

		typename LinkedList<T>::LinkedListIterator end() {
			return _list.end();
		}

	// Functions
	public:
		// Function to add an item to the top of stack
		void Push(const T& new_val) {
			_list.Prepend(new_val);
		}

		// Function to remove an item from the top of stack
		void Pop() {
			_list.remove(_list.begin());
		}

		// Function to get the top element without removing it
		T& Top() {
			// Get the top element, without removing it
		}

		// Function to check if stack is empty
		void Empty() {
			if (_list.Size() == 0)
				return true;
			else
				return false;
		}
	};
}

#endif