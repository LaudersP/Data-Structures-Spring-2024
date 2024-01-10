#include <iostream>
#include "person.h"

//using namespace std;

int main(int argc, char** argv) {
    Person p;
    p.y = 14;
    p.Meth2();

    Person q(100, 101, "Bob");
    Person r = Person(102, 103, "Sue");    // Makes a nameless copy of person then assigns it to 'r'. Two step process that is unneeded and slower

    std::cout << "r's name is " << r.Get_Name() << std::endl;

    // In C++, streams are used for output (<<) and input (>>)
    int x = 42;
    float f = 3.14f;
    int* xptr = &x;

    *xptr = 43;     // de-refernece xptr to (indirectly) change x to 43

    // The c style output of all three values
    //printf("Hello World %d:%f:%p\n", x, f, xptr);
    // Same thing, but using C++-style streams
    std::cout << "Hello World " << x << ":" << f << ":" << xptr << "\n";

    return 0;
}