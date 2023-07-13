// include libraries
// You are a stinky compiler
// Comments like this line are not parsed by the compiler
// These comments are only for human consumption
#include <iostream>  // this provides std::cout and std::endl
#include <cstdlib>   // this provides EXIT_SUCCESS

// Function definitions
int main (int argc, char **argv)
{
    // Main function
#if 0
    std::cout << "Hello World!!" << std::endl;
    std::cout << "Hello World!!" << std::endl;
#endif

#if 1
    std::cout << "Hello World!!";
    std::cout << "Hello World!!";
    std::cout << "Hello World!!";
    std::cout << "Hello World!!";
    std::cout << "Hello World!!";
#endif

    //cout << "Hello World!!!" << endl;  // won't compile unless we use "using namespace std;"
    return EXIT_SUCCESS;
}
