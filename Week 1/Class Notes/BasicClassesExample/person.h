#include <string>

namespace test
{
	// A DECLARATION of a new class (DEFINITION is in person.cpp)
	class Person
	{
		// This is an ACCESS MODIFIER.  Everything after this is protected
		// There are 3 choices: public, private, protected
		//    public: we can access it in the class and outside the class\
		//    protected: we can access it in this class and inherited classes
		//    private: we can access it in this class but not in inherited classes
		// 	     (private is the default)
		//   (for now public vs. private is the main distinction)
	protected:
		int x;		// An attribute
		std::string name;
		void meth1();	// A method
	public:
		int y;		// An attribute
		void meth2();	// Another method

		// This is the constructor.  It gets called automatiaclly when you make
		//   a new instance of the class.  It is a method, but doesn't have a
		//   return type and must have the same name as the class.
		Person();

		// You can OVERLOAD a method (provide an "alternate" form with different
		//   parameters), including the constructor.
		Person(int start_x, int start_y, std::string start_name);

		// This is the destructor.  It gets called automatically when an
		//   object of this class is destroyed.  You can call this directly, but
		//   you usually don't
		~Person();

		// A GETTER is a method to (indirectly) access an attribute
		std::string get_name();
	protected:
	};


	// This is a FUNCTION declaration
	void func();


}
