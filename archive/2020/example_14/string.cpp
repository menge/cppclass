#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>

int atoi_practice(const char *num)
{
    std::cout << "In function, i have received: " << num << std::endl;
    std::cout << "strlen of num is: " << strlen(num) << std::endl;
    return 0;
}

int main (int argc, char **argv)
{
#if 0
    char str[] = "Hello";
    std::cout << str << std::endl;

    char *foo = str;
    std::cout << foo << std::endl;
    std::cout << &foo << std::endl;
    printf("%p\n", &foo);
    printf("%p\n", foo);
    printf("%s\n", foo);
    std::cout << *foo << std::endl;
    std::cout << foo[0] << std::endl;
    std::cout << foo[1] << std::endl;
    std::cout << *(foo+1) << std::endl;

    char *foo2 = foo;
    //foo++;
    //str++;
    //(*foo2)++;
    //foo2[0]++;
    std::cout << foo << std::endl;
    std::cout << foo2 << std::endl;

    //foo[2] = 'p';
    std::cout << foo << std::endl;

    std::cout << str << std::endl;
#endif

#if 0
    char str2[] = "Alfred";
    //char str2[] = "AlfredAlfredAlfredAlfredAlfredAlfredAlfredAlfredAlfredAlfredAlfredAlfredAlfredAlfredAlfredAlfredAlfred";
    char str3[] = "Alfreg";

    char *bar = str2;

    //bool same = (str2 == str3); // false
    //bool same = (str2 == bar);  // true
    int same = strcmp(str3, str2);
    std::cout << same << std::endl;

    char *borf = str2;
    borf++;

    // str2++; THIS ISN'T ALLOWED

    std::cout << borf << std::endl;

    {
        char foo[64];
        char *bar = foo;
        strncpy(bar, str2, sizeof(foo));

        std::cout << bar << std::endl;
    }
#endif
#if 0
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
#endif
#if 0
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
#endif
    {
        char animal1[] = "fira";
        char animal2[] = "fire";
        int result = strcmp(animal1, animal2);

#if 0
        1286981659613891899
        1 digit - 10    -- 10**1
        2 digit - 100   -- 10**2
        3 digit - 1000  -- 10**3
        4 digit - 10000 -- 10**4

        1 binary digit, 0, 1              - 2
        2 binary digit, 00, 01, 10, 11    - 4
        3 binary digit, 00, 01, 10, 11... - 8
        4 binary digit, 00, 01, 10, 11... - 16
        5 binary digit, 00, 01, 10, 11... - 32
        6 binary digit, 00, 01, 10, 11... - 64
        7 binary digit, 00, 01, 10, 11... - 128
        8 binary digit, 00, 01, 10, 11... - 256

        abcdefghijklmnopqrstuvwxyz
        ABCDEFGHIJKLMNOPQRSTUVWXYZ
        1234567890
        !@#$%^&*()

        ASCII

        std::cout << result << std::endl;
#endif
    }
#if 0
    {
        char foo[] = "Hello I am 27 years old";

        std::cout << foo << std::endl;

        //foo[11] = 51;
        //foo[11] = 0x33;
        foo[11] = '3';

        std::cout << foo << std::endl;
    }
    {
        char foo[] = "fire";
        char foo2[] = "fira";


        int difference = foo[3] - 'a';

        std::cout << difference << std::endl;
        std::cout << strcmp(foo2, foo) << std::endl;

        char animal1[] = "aardvark";
        char animal2[] = "zebra";

        std::cout << strcmp(animal1, animal2) << std::endl;
    }
    {
        std::string number;

        std::cin >> number;
        std::cout << "I got number to be: " << number << std::endl;
        int num = atoi_practice(number.c_str());
    }
#endif
}
