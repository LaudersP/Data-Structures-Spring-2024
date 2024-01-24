#ifndef FOO_H
#define FOO_H

#include <string>

namespace testing {
	class Foo {
	protected:
		/// Signed integer attribute
		int intAttribute;

		/// String attribute
		std::string stringAttribute;
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
		Foo(const int intValue, std::string stringValue) {
			intAttribute = intValue;

			stringAttribute = stringValue;
		}

		/***************************************************************************//**
		* @brief Gets the current integer value from Foo.
		*
		* @return The current value of integer held in Foo.
		******************************************************************************/
		int Get_Int_Value();

		/***************************************************************************//**
		* @brief Gets the current string from Foo.
		*
		* @return The current string held in Foo.
		******************************************************************************/
		std::string Get_String_Value();

		/***************************************************************************//**
		* @brief Set the current integer value held in Foo.
		*
		* @param The desired new value of the integer to be held in Foo.
		******************************************************************************/
		int Set_Int_Value(const int newValue);

		/***************************************************************************//**
		* @brief Set the current string held in Foo.
		*
		* @param The desired new string to be held in Foo.
		******************************************************************************/
		std::string Set_String_Value(std::string newString);
	};
}

#endif