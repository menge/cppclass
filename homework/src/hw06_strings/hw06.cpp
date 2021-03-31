#include "hw06.h"

// Pre-conditions: none
// Post-conditions: none
// Returns: number of bytes in the string pointed to by str,
//          excluding the terminating null byte ('\0')
size_t cppclass::strlen(const char *str)
{
    return 0;
}

// Pre-conditions: none
// Post-conditions: none
// Returns: Searches for the first occurrence of the character c
//          (an unsigned char) in the string pointed to, by the
//          argument str.
//
//          If character doesn't exist, returns nullptr
//
//          Example: str = "asdf", c = 'a',
//                   returns pointer to 0th element of string
//          Example: str = "asdf", c = 'f',
//                   returns pointer to 3rd element of string
//          Example: str = "asdf", c = 'g',
//                   returns nullptr
const char * cppclass::strchr(const char *str, char c)
{
    return nullptr;
}

// Pre-conditions: The strings may not overlap, and the destination
//                 string dest must be large enough to receive the
//                 copy.
// Post-conditions: The strcpy() function copies the string pointed
//                  to by src, including the terminating null byte
//                  ('\0'), to the buffer pointed to by dest.
// Returns: return a pointer to the destination string dest
char * cppclass::strcpy(char *dest, const char *src)
{
    return nullptr;
}

// Pre-conditions: none
// Post-conditions: none
// Returns: The  strstr() function finds the first occurrence of
//          the substring needle in the string haystack.  The
//          terminating null bytes ('\0') are not compared.
//
//          These functions return a pointer to the beginning of
//          the located substring, or nullptr if the substring is
//          not found.
char * cppclass::strstr(const char *haystack, const char *needle)
{
    return nullptr;
}

// Pre-conditions: none
// Post-conditions: none
// Returns: The strspn() function calculates the length (in bytes)
//          of the initial segment of str which consists entirely
//          of bytes in accept.
//
//          Example: str="aardvark", accept="aeiouy" -> 2
//          Example: str="baboon", accept="aeiouy" -> 0
//          Example: str="yak", accept="aeiouy" -> 2
size_t cppclass::strspn(const char *str, const char *accept)
{
    return 0;
}

// Pre-conditions: none
// Post-conditions: none
// Returns: The strcmp() function compares the two strings
//          str1 and str2. It returns an integer less than,
//          equal to, or greater than zero if str1 is found,
//          respectively, to be less than, to  match,  or
//          be greater than str2.
int cppclass::strcmp(const char *str1, const char *str2)
{
    return 0;
}

// Pre-conditions: none
// Post-conditions: str is replaced in-place
// Returns: replaces all characters in passed-in string such
//          that any lower-case characters are translated
//          into upper-case characters.
void cppclass::upper(char *str)
{
}

// Pre-conditions: none
// Post-conditions: str is replaced in-place
// Returns: replaces all characters in passed-in string such
//          that any upper-case characters are translated
//          into lower-case characters.
void cppclass::lower(char *str)
{
}
