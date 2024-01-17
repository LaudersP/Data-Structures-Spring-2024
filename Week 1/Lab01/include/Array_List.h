/***************************************************************************//**
* @file Array_List.h
* 
* @brief Declaration of the ArrayList class.
******************************************************************************/

#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include <string>

namespace ssuds {
	/***************************************************************************//**
	* @class ArrayList
	* 
	* @brief ArrayList class for dynamic array of strings.
	*
	* This class provides a basic functionality for managing an array of strings with dynamic memory allocation.
	* This includes Appending, Inserting, Clearing, Getting, Finding, Removing, and Resetting of list strings.
	* Along with capabilities to get the length of the list at its current state.
	******************************************************************************/
	class ArrayList {
	protected:
		std::string* _data; ///< Pointer to the array of strings.
		unsigned int _size; ///< Size of array.

	public:
		/***************************************************************************//**
		* @brief Constructor of ArrayList class.
		* 
		* Initializes default values for ArrayList.
		******************************************************************************/
		ArrayList();

		/***************************************************************************//**
		* @brief Destructor of ArrayList class.
		*
		* Deallocates memory used for ArrayList.
		******************************************************************************/
		~ArrayList();

		/***************************************************************************//**
		* @brief Append a string to the end of the ArrayList.
		* 
		* @param s The string to be appended.
		******************************************************************************/
		void Append(std::string s);

		/***************************************************************************//**
		* @brief Gets the current length of the array list.
		* 
		* @return The current lenght of the list.
		******************************************************************************/
		unsigned int Size() const;

		/***************************************************************************//**
		* @brief Insert a string at a set position in the list.
		* 
		* @param s The string to be inserted.
		* @param position The index for the string to be inserted at.
		******************************************************************************/
		void Insert(std::string s, const unsigned int position);

		/***************************************************************************//**
		* @brief Clears the list and resets it back to the beginning values.
		* 
		* Similar to the destructor but meant to be used during list's lifetime.
		******************************************************************************/
		void Clear();

		/***************************************************************************//**
		* @brief Gets a string at a defined index.
		* 
		* @param index The position of the desired string.
		* 
		* @return The string at position of the index value.
		******************************************************************************/
		std::string Get(const unsigned int index) const;

		/***************************************************************************//**
		* @brief Find a string in the list, with a optional starting location.
		* 
		* @param s String to be found.
		* @param index Desired starting position (optional).
		* 
		* @return Index the string is found at or -1 if not found.
		******************************************************************************/
		int Find(std::string s, unsigned int index = 0) const;

		/***************************************************************************//**
		* @brief Remove a string at a given index position.
		* 
		* @param index Position of the string to remove.
		******************************************************************************/
		void Remove(const unsigned int index);

		/***************************************************************************//**
		* @brief Remove all instances of a desired string from the list.
		* 
		* @param s String to find and remove from the entire list.
		* 
		* @return The number of times the given string was removed.
		******************************************************************************/
		int Remove_All(std::string s);
	};
}

#endif