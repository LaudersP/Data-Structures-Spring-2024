// Put DEFINITION of the methods / functions here
#include "person.h"
#include <iostream>

void test::Person::meth1()
{
	std::cout << "This is method1\n";
}

void test::Person::meth2()
{
	// Note how we can access OUR protected member (outside users can't)
	meth1();
	std::cout << "This is method2\n";
}

test::Person::Person()
{
	std::cout << "This is the default constructor\n";
}


test::Person::Person(int start_x, int start_y, std::string start_name) : x(start_x), y(start_y), name(start_name)
{
	std::cout << "This is the constructor that takes arguments\n";
	// Set our ATTRIBUTES (x and y) to the value of these PARAMETERS.
	// Remember that parameters go away when the function ends
	//x = start_x;			// Note that here, x, y, and name are allocated before this method
	//y = start_y;			// starts and THEN we copy over the values here.  You can do
	//name = start_name;		// this a bit more efficiently by using the initializers above
}


test::Person::~Person()
{
	std::cout << "This is the destructor of the object with x=" << x << "\n";
}

std::string test::Person::get_name()
{
	return name;
}

void test::func()
{
	std::cout << "This is func\n";
}