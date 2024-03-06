#ifndef QUEUE_H
#define QUEUE_H

#include <Linked_List.hpp>

namespace ssuds {
	template <class T>
	class Queue : private LinkedList<T> {
		// No Attributes

		void enqueue(const T& new_val) {
			this->Append(new_val);
		}

		void dequeue(const T& val) {
			// Remove queue item
		}

		void Top() {
			// Get the top element, without removing it
		}

		void Empty() {
			// Return true if empty
		}
	};
}

#endif