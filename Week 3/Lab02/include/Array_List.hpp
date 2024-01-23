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
		std::string* _data;	///< Pointer to the array of strings.
		unsigned int _size;	///< The number of USED slots in the array list.
		unsigned int _capacity; ///< The number of AVALIABLE slots in the array list.

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
		* @brief Gets the current used spots of the array list.
		*
		* @return The current used spots of the list.
		******************************************************************************/
		unsigned int Size() const;

		/***************************************************************************//**
		* @brief Insert a string at a set position in the list.
		*
		* @param s The string to be inserted.
		* @param position The index for the string to be inserted at.
		******************************************************************************/
		void Insert(std::string s, const unsigned int index);

		/***************************************************************************//**
		* @brief Gets the current avaliable slots of the array list.
		*
		* @return The current avaliable slots of the list.
		******************************************************************************/
		unsigned int Capacity() const;

		/***************************************************************************//**
		* @brief Gets a string at a defined index.
		*
		* @param index The position of the desired string.
		*
		* @return The string at position of the index value.
		******************************************************************************/
		std::string Get(const unsigned int index) const;
	protected:
		void Grow();
	};
}

#endif