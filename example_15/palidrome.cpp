#include <cassert>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>

bool is_palidrome(const char *str);
bool is_palidrome(const char *str)
{
    const int MAX_STR_LENGTH = 1000;
    char tmp[MAX_STR_LENGTH];
    assert( strlen(str) < MAX_STR_LENGTH-1);
    int i, j;
    for (i = strlen(str)-1, j = 0; i >= 0; i--, j++)
    {
        tmp[j] = str[i];
    }
    tmp[strlen(str)] = '\0';

    if ( strcmp(tmp, str) != 0 )
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool is_palidrome2(const char *str);
bool is_palidrome2(const char *str)
{
    const char *left = str;
    const char *right = str + strlen(str) - 1;

    while (left < right)
    {
        if (*left != *right)
        {
            return false;
        }
        left += 1;
        right -= 1;
    }
    return true;
}

int main (int argc, char **argv)
{
    assert( is_palidrome2("abcdefghijklmnopqrstuvwxyz")             == false);
    assert( is_palidrome2("bob")             == true);
    assert( is_palidrome2("bill")            == false);
    assert( is_palidrome2("radar")           == true);
    assert( is_palidrome2("11111")           == true);
    assert( is_palidrome2("12111")           == false);
    assert( is_palidrome2("11211")           == true);
    assert( is_palidrome2("12321")           == true);
    assert( is_palidrome2("tattarrattat")    == true);
    assert( is_palidrome2("bob is my uncle") == false);
    return EXIT_SUCCESS;
}
