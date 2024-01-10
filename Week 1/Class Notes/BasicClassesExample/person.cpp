// Put DEFINITION of the methods / functions here
#include "person.h"
#include <iostream>

// Default Constructor
Person::Person() {
	std::cout << "This is the default constructor" << std::endl;
}

// Alternative Constructor
Person::Person(int start_x, int start_y, std::string start_name) : _x(start_x), y(start_y), _name(start_name) {
	// Set our ATTRIBUTES (x and y) to the values of these PARAMETERS.
	// Remeber that parameters go away when the function ends
	// _x = start_x;			// Note that here, x, y, and name are allocated before this method
	// y = start_y;				// starts
	// _name = start_name;		

	std::cout << "This is the constructor that takes arguments" << std::endl;
}

Person::~Person() {
	std::cout << "This is the deconstructor of object with x=" << _x << std::endl;
}

std::string Person::Get_Name() {
	return _name;
}

void Person::Meth1() {
	std::cout << "This is method1" << std::endl;
}

void Person::Meth2() {
	// Note how we can access OUR protected member (outside users can't)
	Meth1();
	std::cout << "This is method2" << std::endl;
}


void func()
{
	std::cout << "This is func" << std::endl;
}