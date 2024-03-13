#ifndef QUEUE_H
#define QUEUE_H

#include <Linked_List.hpp>

namespace ssuds {
	template <class T>
	class Queue : private LinkedList<T> {
	public:
		// Iterator 
		using Iterator = typename LinkedList<T>::LinkedListIterator;

		// Adds element to the end of queue
		void enqueue(const T& new_val) {
			this->Append(new_val);
		}

		// Removes element from the beginning of queue
		void dequeue() {
			// Check if the queue is empty
			if (Empty()) 
				throw std::out_of_range("ERROR) Queue is empty, cannont remove front element!");

			this->Remove(this->begin());
		}

		// Function to get the top element without removing it
		T& Top() const {
			// Check if the queue is empty
			if (Empty()) 
				throw std::out_of_range("ERROR) Queue is empty, cannont access front element!");

			return _start->_data;
		}

		// Function to check if stack is empty
		void Empty() const {
			if (this->Size() == 0)
				return true;
			else
				return false;
		}
	};
}

#endif