#include <cstdlib>
#include <cstring>
#include <iostream>

int main (int argc, char **argv)
{
    char str[] = "Hello";
    std::cout << str << std::endl;

    char *foo = str;
    std::cout << foo << std::endl;

    foo++;
    std::cout << foo << std::endl;

    foo[2] = 'p';
    std::cout << foo << std::endl;

    std::cout << str << std::endl;

    char str2[] = "Alfred";
    char str3[] = "Alfree";

    char *bar = str2;

    //bool same = (str2 == str3); // false
    //bool same = (str2 == bar);  // true
    int same = strcmp(str2, str3);
    std::cout << same << std::endl;

    char *borf = str2;
    borf++;

    // str2++; THIS ISN'T ALLOWED

    std::cout << borf << std::endl;

    {
        char foo[64];
        char *bar = foo;
        strcpy(bar, str2);

        std::cout << bar << std::endl;
    }
    {
        char foo[] = "David";
        char foo2[] = "Hello World!!";

        std::cout << foo << std::endl;
        std::cout << foo2 << std::endl;

        foo2[5] = '\0';
        std::cout << foo2 << std::endl;

        foo2[5] = '-';
        std::cout << foo2 << std::endl;
    }
    {
        char foo[] = "The Quick Brown Fox Jumped Over The Lazy Dogs";
        std::cout << foo << std::endl;

        foo[15] = '\0';
        std::cout << foo << std::endl;
    }
    {
        char foo[] = "Bumpy Cactus";
        size_t len = strlen(foo);

        std::cout << len << std::endl;
        std::cout << sizeof(foo) << std::endl;
    }
    {
        char animal1[] = "fira";
        char animal2[] = "fire";
        int result = strcmp(animal1, animal2);

        std::cout << result << std::endl;
    }
}
