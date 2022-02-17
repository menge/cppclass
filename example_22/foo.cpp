#include <cstring>
#include <iostream>
#include <string>


int main()
{
#if 0
    char *string1 = "hello world"; INVALID, INVALID
#endif
    char string2[] = "hello moon"; //VALID, INVALID
    char string3[100] = "hello world";// VALID, VALID
#if 0
    char string4[1] = "hello world";   INVALID, VALID
    char &string5[100] = "hello world"; INVALID, VALID
#endif
    int i_array[100] = {50};

    std::cout << sizeof(string3) << std::endl;
    std::cout << strlen(string3+6) << std::endl;
    std::cout << i_array << std::endl;
    std::cout << *i_array << std::endl;
    std::cout << (void *)string3 << std::endl;
    //string3[11] = 's';
    strcat(string3, "s");


    std::cout << string3 << std::endl;
    //std::cout << string3 << std::endl;
    //std::cout << string3+6 << std::endl;

    strncat(string3, "sballs", sizeof(string3) - strlen(string3) - 1);
    std::cout << string2 << std::endl;
    std::cout << string3 << std::endl;

    std::string foo = "hello world";
    std::cout << foo << std::endl;
    std::cout << strlen(foo.c_str()) << std::endl;
    foo = foo + "s";
    std::cout << foo << std::endl;
    std::cout << strlen(foo.c_str()) << std::endl;
}
