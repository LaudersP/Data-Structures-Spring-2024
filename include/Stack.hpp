#ifndef STACK_HPP
#define STACK_HPP

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
		~Stack() {
			Clear();
		}

		Iterator begin() {
			return _list.begin();
		}

		Iterator end() {
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
			if (Empty())
				throw std::out_of_range("ERROR: Stack is empty, cannot remove front element!");

			_list.Remove(_list.begin());
		}

		// Function to get the top element without removing it
		T& Top() const {
			if (Empty())
				throw std::out_of_range("ERROR: Stack is empty, cannot access front element!");

			return *(_list.begin());
		}

		// Function to check if stack is empty
		bool Empty() const {
			return _list.Size() == 0 ? true : false;
		}

		// Function to return stack size 
		unsigned int Size() const {
			return _list.Size();
		}

		// Function to remove all stack items
		void Clear() {
			while (!Empty()) {
				Pop();
			}
		}
	};
}

#endif