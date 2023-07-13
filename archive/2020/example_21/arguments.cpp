#include <iostream>
#include <cstdlib>
#include <cassert>

int main (int argc, char **argv)
{
#if 0 // review of double pointers
    char str1[] = "hello"
    char str2[] = "my"
    char str3[] = "name"
    char str4[] = "is"
    char str5[] = "emil"
    char* sentence[] = {str1, str2, str3, str4, str5};

    sentence[0][2] -> 'l'
    sentence[2][0] -> 'n'
    sentence[3][2] -> '\0'
    sentence[3][3] -> ????


  
    //char string[20] = "hello\0asdf";
    char name[100] = "alfred";
    strcpy(name, "poindexter");

    int array[5] = {1, 2, 3, 4, 5};
    array[3] = 0;
    array[4] = 0;
+-+-+-+-+
|a b c d|
+-+-+-+-+
#endif

   srand(1);
   assert(argc == 2);
   long int limit = strtol(argv[1], nullptr, 10);

   for (int i = 0; i < limit; i++)
   {
#if 1
       if (i == 100)
       {
           srand(1);
       }
       std::cout << i << ": " << rand() << std::endl;
#endif
   }
}

