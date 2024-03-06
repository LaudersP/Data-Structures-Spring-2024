#ifndef STACK_H
#define STACK_H

#include <Linked_List.hpp>

namespace ssuds {
	template <class T>
	class Stack {
	protected:
		LinkedList<t> _list;

	public:
		void Push(const T& new_val) {
			_list.Prepend(new_val);
		}

		void Pop(const T& val) {
			// Remove from the stack
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