#include <cstdlib>
#include <iostream>

int main(int argc, char **argv)
{
    int val1 = 255;   // variable declaration
    int val2 = 12345; // variable declaration with initialization
    int product;

    std::cout << "val1: " << val1 << std::endl;
    std::cout << "val2: " << val2 << std::endl;

    std::cout << "Please input value 1: ";
    std::cin >> val1;
    std::cout << "Please input value 2: ";
    std::cin >> val2;

    product = val1 * val2;
    // val1 + val2 = sum;  // this won't work because assignments always 
                           // have to be on a single variable on the left side
                           //
    std::cout << "The product of val1 * val2 is: " << product << std::endl;
}
