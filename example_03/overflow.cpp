#include <cstdlib>
#include <iostream>

int main(int argc, char **argv)
{
#if 0
    unsigned short val1 = 65535;   // variable declaration
    unsigned short val2 = 1; // variable declaration with initialization
    unsigned short sum;

    std::cout << "val1: " << val1 << std::endl;
    std::cout << "val2: " << val2 << std::endl;
    sum = val1 + val2;
    std::cout << "The sum of val1 + val2 is: " << sum << std::endl;
#endif
#if 1
    short val1 = 32767;   // variable declaration
    short val2 = 1; // variable declaration with initialization
    short sum;

    std::cout << "val1: " << val1 << std::endl;
    std::cout << "val2: " << val2 << std::endl;
    sum = val1 + val2;
    std::cout << "The sum of val1 + val2 is: " << sum << std::endl;
#endif
}
