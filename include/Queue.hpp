#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <Linked_List.hpp>

namespace ssuds {
	template <class T>
	class Queue : private LinkedList<T> {
	public:
		// Carry over LinkedList functions
		using LinkedList<T>::Size;
		using LinkedList<T>::Clear;

		// Destructor
		~Queue() {
			Clear();
		}

		// Adds element to the end of queue
		void enqueue(const T& new_val) {
			this->Append(new_val);
		}

		// Removes element from the beginning of queue
		void dequeue() {
			// Check if the queue is empty
			if (Empty()) 
				throw std::out_of_range("ERROR: Queue is empty, cannot remove front element!");

			this->Remove(this->begin());
		}

		// Function to get the top element without removing it
		T& Top() const {
			// Check if the queue is empty
			if (Empty()) 
				throw std::out_of_range("ERROR: Queue is empty, cannot access front element!");

			return *(this->begin());
		}

		// Function to check if stack is empty
		bool Empty() const {
			return this->Size() == 0 ? true : false;
		}
	};
}

#endif