#include <iostream>
#include "person.h"

//using namespace std;
//using namespace test;

int main(int argc, char** argv)
{
    test::Person p;       // This calls the (default) constructor.  Note: x is uninitialized
    p.y = 14;
    p.meth2();

    test::Person q(100, 101, "Bob");
    test::Person r = test::Person(102, 103, "Sue");    // Makes it an then copies it (slightly slower)

    std::cout << "r's name is " << r.get_name() << "\n";

    // In C++, streams are used for output (<<) and input (>>)
    int x = 42;
    float f = 3.14f;
    int* xptr = &x;

    *xptr = 43;         // de-reference xptr to (indirectly) change x to 43

    test::Person* pptr;
    pptr = &p;
    pptr->meth2();
    (*pptr).meth2();        // This line has the same effect as the line before.
    pptr = &r;
    pptr->meth2();          // Call meth2 through r (indirectly)

    std::cout << "dynamic malloc....";
    pptr = (test::Person*)malloc(sizeof(test::Person));     // Make space on the heap for
                            // one Person object and make pptr hold the address (there is NO OTHER WAY
                            // to access this new Person!).  Since malloc was used, no constructor gets called
    pptr->y = 63;
    free(pptr);             // free up the space.  No destructor gets called
    std::cout << "done!\n";

    pptr = new test::Person(16, 17, "Joe");     // This does C++ style dynamic allocation (does use constructor)
    //pptr = new test::Person();
    pptr->y = 18;
    delete pptr;                                // This does C++ style dynamic freeing (and calls the destructor)

    // The c style output of all three values
    //printf("Hello World %d:%f:%p\n", x, f, xptr);
    // Same thing, but using C++-style streams
    std::cout << "Hello World " << x << ":" << f << ":" << xptr << "\n";

    return 0;
}