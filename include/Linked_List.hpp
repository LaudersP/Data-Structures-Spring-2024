#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <ostream>

namespace ssuds {
	template <class L>
	class LinkedList {
	protected:
		class _Node {
			// Node class code here...
		};
	public:
		/***************************************************************************//**
		* @brief Constructor of LinkedList class.
		*
		* Initializes default values for LinkedList.
		******************************************************************************/
		LinkedList() {
			// Implementation code here...
		}

		/***************************************************************************//**
		* @brief Deconstructor of LinkedList class.
		*
		* Deallocates memory used for LinkedList.
		******************************************************************************/
		~LinkedList() {
			// Implementation code here...
		}

		/***************************************************************************//**
		* @brief Gets a item at a defined index.
		*
		* @param index The position of the desired item.
		*
		* @return The a referene of the item at position of the index value.
		******************************************************************************/
		L& operator[](const unsigned int index) const {
			// Implementation code here...
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
			// Implementation code here...
		}

		/***************************************************************************//**
		* @brief Append a item to the end of the LinkedList.
		*
		* @param s The item to be appended.
		******************************************************************************/
		void Append(const L& item) {
			// Implementation code here...
		}

		/***************************************************************************//**
		* @brief Prepend an item to the beignning of the LinkedList.
		*
		* @param s The item to be prepended.
		******************************************************************************/
		void Prepend(const L& item) {
			// Implementation code here...
		}

		/***************************************************************************//**
		* @brief Gets the current size of the LinkedList.
		*
		* @return The current spots of the LinkedList.
		******************************************************************************/
		unsigned int Size() const {
			// Implementation code here...
		}

		/***************************************************************************//**
		* @brief Clears the LinkedList and resets it back to the beginning values.
		*
		* Similar to the destructor but meant to be used during list's lifetime.
		******************************************************************************/
		void Clear() {
			// Implementation code here...
		}
	};
}

#endif