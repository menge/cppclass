#pragma once

#include <stddef.h>

namespace cppclass
{
    // Pre-conditions: none
    // Post-conditions: none
    // Returns: number of bytes in the string pointed to by str,
    //          excluding the terminating null byte ('\0')
    size_t strlen(const char *str);

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
    const char * strchr(const char *str, char c);

    // Pre-conditions: The strings may not overlap, and the destination
    //                 string dest must be large enough to receive the
    //                 copy.
    // Post-conditions: The strcpy() function copies the string pointed
    //                  to by src, including the terminating null byte
    //                  ('\0'), to the buffer pointed to by dest.
    // Returns: return a pointer to the destination string dest
    char * strcpy(char *dest, const char *src);

    // Pre-conditions: none
    // Post-conditions: none
    // Returns: The  strstr() function finds the first occurrence of
    //          the substring needle in the string haystack.  The
    //          terminating null bytes ('\0') are not compared.
    //
    //          These functions return a pointer to the beginning of
    //          the located substring, or nullptr if the substring is
    //          not found.
    char * strstr(const char *haystack, const char *needle);

    // Pre-conditions: none
    // Post-conditions: none
    // Returns: The strspn() function calculates the length (in bytes)
    //          of the initial segment of str which consists entirely
    //          of bytes in accept.
    //
    //          Example: str="aardvark", accept="aeiouy" -> 2
    //          Example: str="baboon", accept="aeiouy" -> 0
    //          Example: str="yak", accept="aeiouy" -> 2
    size_t strspn(const char *str, const char *accept);

    // Pre-conditions: none
    // Post-conditions: none
    // Returns: The strcmp() function compares the two strings
    //          str1 and str2. It returns an integer less than,
    //          equal to, or greater than zero if str1 is found,
    //          respectively, to be less than, to  match,  or
    //          be greater than str2.
    int strcmp(const char *str1, const char *str2);

    // Pre-conditions: none
    // Post-conditions: str is replaced in-place
    // Returns: replaces all characters in passed-in string such
    //          that any lower-case characters are translated
    //          into upper-case characters.
    void upper(char *str);

    // Pre-conditions: none
    // Post-conditions: str is replaced in-place
    // Returns: replaces all characters in passed-in string such
    //          that any upper-case characters are translated
    //          into lower-case characters.
    void lower(char *str);
}
