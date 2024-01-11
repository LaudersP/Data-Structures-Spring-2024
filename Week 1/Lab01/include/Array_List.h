#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include <string>

namespace ssuds {
	/**
	* @brief ArrayList class for dynamic array of strings.
	*
	* This class provides a basic functionality for managing an array of strings with dynamic memory allocation.
	*/
	class ArrayList {
	protected:
		std::string* _data; ///< Pointer to the array of strings.
		unsigned int _size; ///< Size of array.

	public:
		/**
		* @brief Constructor of ArrayList class.
		* 
		* Initializes default values for ArrayList.
		*/
		ArrayList();

		/**
		* @brief Destructor of ArrayList class.
		*
		* Deallocates memory used for ArrayList.
		*/
		~ArrayList();

		/**
		* @brief Append a string to the end of the ArrayList.
		* 
		* @param s The string to be appended.
		*/
		void Append(std::string s);

		/**
		* @brief Gets the current length of the array list.
		* 
		* @return The current lenght of the list.
		*/
		unsigned int Size() const;

		/**
		* @breif Insert a string at a set position in the list.
		* 
		* @param s The string to be inserted.
		* @param position The index for the string to be inserted at.
		*/
		void Insert(std::string s, const unsigned int position);

		/**
		* @breif Clears the list and resets it back to the beginning values.
		* 
		* Similar to the destructor but meant to be used during list's lifetime.
		*/
		void Clear();

		/**
		* @breif Gets a string at a defined index.
		* 
		* @param index The position of the desired string.
		* 
		* @return The string at position of the index value.
		*/
		std::string Get(const unsigned int index) const;

		/**
		* @breif Find a string in the list, with a optional starting location.
		* 
		* @param s String to be found.
		* @param index Desired starting position (optional).
		* 
		* @return Index the string is found at or -1 if not found.
		*/
		int Find(std::string s, unsigned int index = 0) const;

		// FOR TESTING
		std::string GetString(unsigned int pos);
	};
}

#endif