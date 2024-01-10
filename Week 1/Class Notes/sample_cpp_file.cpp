#include <iostream>

int main() {
    using std::cout;
    using std::endl;

    // Variables
    int x = 42;
    float f = 3.14f;
    int* xptr = &x;

    // C sytle output
    //printf("Hello, World! %d: %f: %p\n", x, f, xptr);

    // C++ style output
    cout << "Hello, World!" << x << ":" << f << ":" << xptr << endl;

    return 0;
}