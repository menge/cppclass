#include <iostream>
#include <cstdlib>

int main(int argc, char** argv)
{
    std::cout << argc << std::endl;
    for (int i = 0; i < argc; i++)
    {
        std::cout << i << ": " << argv[i] << std::endl;
    }
    return EXIT_SUCCESS;
}
