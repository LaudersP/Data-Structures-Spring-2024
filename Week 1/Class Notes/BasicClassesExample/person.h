#include <string>

// A DECLARATION of a new class (DEFINITION is in person.cpp)
class Person {
// This is an ACCESS MODIFIER.  Everything after this is protected
// There are 3 choices: public, private, protected
//    public: we can access it in the class and outside the class\
//    protected: we can access it in this class and inherited classes
//    private: we can access it in this class but not in inherited classes
//		(Private is the default)
//   (for now public vs. private is the main distinction)
protected:
	int _x;		// An attribute
	std::string _name;
	void Meth1();	// A method
public:
	// Constructor. Gets called automatically when making a new instance
	//	of the class. It is a method, but doesn't have a return type and
	//	must have the same name as the class.
	Person();

	// Can OVERLOAD a method (provide an "alternative" constructor)
	Person(int start_x, int start_y, std::string start_name);

	// Deconstructor. It gets automatically when an object of the class is
	//	destroyeed, Can be called directly, but usually not
	~Person();

	// A GETTER is a method to (indirectly) access an attribute
	std::string Get_Name();

	int y;		// An attribute
	void Meth2();	// Another method
protected:
};


// This is a FUNCTION declaration
void func();
