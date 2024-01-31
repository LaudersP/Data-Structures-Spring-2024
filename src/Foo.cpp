#include <Foo.hpp>

// Default Constructor
testing::Foo::Foo() {
	// Set attributes to default values
	_intAttribute = 0;
	_stringAttribute = "";
}

testing::Foo::Foo(const int intValue, std::string stringValue) {
	// Set attributes to user defined values
	_intAttribute = intValue;
	_stringAttribute = stringValue;
}

int testing::Foo::Get_Int_Value() const {
	return _intAttribute;
}

std::string testing::Foo::Get_String_Value() const {
	return _stringAttribute;
}

void testing::Foo::Set_Int_Value(const int newValue) {
	_intAttribute = newValue;
}

void testing::Foo::Set_String_Value(std::string newString) {
	_stringAttribute = newString;
}

std::ostream& testing::operator<<(std::ostream& os, const Foo& foo) {
	os << "<FOO:" << foo.Get_Int_Value() << ":" << foo.Get_String_Value() << ">";

	return os;
}
