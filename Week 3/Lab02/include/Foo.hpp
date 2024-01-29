#ifndef FOO_H
#define FOO_H

#include <ostream>
#include <string>

namespace testing {
	class Foo {
	protected:
		/// Signed integer attribute
		int _intAttribute;

		/// String attribute
		std::string _stringAttribute;
	public:
		/***************************************************************************//**
		* @brief Constructor of Foo class.
		*
		* Initializes default values for Foo.
		******************************************************************************/
		Foo();

		/***************************************************************************//**
		* @brief Custom constructor of Foo class.
		*
		* Initializes user values for Foo.
		******************************************************************************/
		Foo(const int intValue, std::string stringValue);

		/***************************************************************************//**
		* @brief Gets the current integer value from Foo.
		*
		* @return The current value of integer held in Foo.
		******************************************************************************/
		int Get_Int_Value() const;

		/***************************************************************************//**
		* @brief Gets the current string from Foo.
		*
		* @return The current string held in Foo.
		******************************************************************************/
		std::string Get_String_Value() const;

		/***************************************************************************//**
		* @brief Set the current integer value held in Foo.
		*
		* @param The desired new value of the integer to be held in Foo.
		******************************************************************************/
		void Set_Int_Value(const int newValue);

		/***************************************************************************//**
		* @brief Set the current string held in Foo.
		*
		* @param The desired new string to be held in Foo.
		******************************************************************************/
		void Set_String_Value(std::string newString);

		/***************************************************************************//**
		* @brief Output the array in a Python like format
		*
		* @param os Stream the array should be outputted via.
		*
		* @param a Array output will be from.
		*
		* @return The array in Python like format via chosen stream.
		******************************************************************************/
		friend std::ostream& operator<< (std::ostream& os, const Foo& foo);
	};
}

#endif