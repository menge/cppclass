#include <cmath>
#include <cstring>
#include <string>

#include "hw06.h"
#include "gtest/gtest.h"


TEST(HW06, STRLEN) {
    const char *tests[] = { "hello",
                            "asdfghjkl;",
                            "AA",
                            "Z",
                            "8n428vnr8hsz09yt2308ysfhvea093auq0r310h30y",
                            " ",
                            "      ",
                            "\t",
                            "\n",
                            "",
    };

    for (auto&& test : tests) {
        EXPECT_EQ(cppclass::strlen(test), strlen(test));
    }
}

TEST(HW06, STRCHR) {
    struct StrchrTestType {
        const char* str;
        char c;
    };

    const StrchrTestType tests[] = {
        {"hello", 'h'},
        {"hello", 'e'},
        {"hello", 'l'},
        {"hello", 'o'},
        {"hello", 'a'},
        {"aaaaa", 'a'},
        {"aa aa", ' '},
        {"a", 'a'},
        {"", 'a'},
    };

    for (auto&& test : tests) {
        EXPECT_EQ(cppclass::strchr(test.str, test.c), strchr(test.str, test.c));
    }
}

TEST(HW06, STRCPY) {
    const char *tests[] = {
        "hello",
        "this is a test",
        "aaaaa",
        "",
    };

    for (auto&& test : tests) {
        char buf0[8192];
        char buf1[8192];

        EXPECT_EQ(cppclass::strcpy(buf0, test), strcpy(buf1, test));

        EXPECT_EQ(std::string(buf0), std::string(buf1));
    }
}

TEST(HW06, STRSTR) {
    struct StrstrTestType {
        const char* haystack;
        const char* needle;
    };

    const StrstrTestType tests[] = {
        {"abcba", "abc"},
        {"abcba", "cba"},
        {"abcbacba", "cba"},
        {"abcbacba", "abcb"},
        {"abcbacba", "abcd"},
        {"abcbacba", "a"},
        {"abcbacba", "b"},
        {"abcbacba", "c"},
        {"abcbacba", "d"},
        {"abcbacba", ""},
        {"", ""},
        {"", "a"},
    };

    for (auto&& test : tests) {
        EXPECT_EQ(cppclass::strstr(test.haystack, test.needle), strstr(test.haystack, test.needle));
    }
}

TEST(HW06, STRSPN) {
    struct StrspnTestType {
        const char* str;
        const char* accept;
    };

    const StrspnTestType tests[] = {
        {"aardvark", "aeiouy"},
        {"bat", "aeiouy"},
        {"yak", "aeiouy"},
        {"emptyaccept", ""},
        {"", "abcde"},
        {"aardvark", "a"},
        {"aardvark", "aa"},
        {"aardvark", "aar"},
    };

    for (auto&& test : tests) {
        EXPECT_EQ(cppclass::strspn(test.str, test.accept), strspn(test.str, test.accept));
    }
}

TEST(HW06, STRCMP) {
    struct StrcmpTestType {
        const char* a;
        const char* b;
    };

    const StrcmpTestType tests[] = {
        {"a", "a"},
        {"hello", "hello"},
        {"hello bar", "hello bar"},
        {"upper", "UPPER"},
        {"UPPER", "upper"},
        {"longlong", "long"},
        {"long", "longlong"},
        {"", "empty"},
        {"empty", "empty"},
        {"empty", ""},
        {"", ""},
    };

    for (auto&& test : tests) {
        EXPECT_EQ(cppclass::strcmp(test.a, test.b), strcmp(test.a, test.b));
    }
}

TEST(HW06, UPPER) {
    struct UpperTestType {
        const char* str;
        const char* expected;
    };

    UpperTestType tests[] = {
        {"a", "A"},
        {"A", "A"},
        {"hello", "HELLO"},
        {"hello bar", "HELLO BAR"},
        {"upper", "UPPER"},
        {"UPPER", "UPPER"},
        {"", ""},
        {"empty", "EMPTY"},
        {"MiXeD", "MIXED"},
        {"123454321", "123454321"},
        {"12abcde21", "12ABCDE21"},
    };

    for (auto&& test : tests) {
        char buffer[8192];
        strcpy(buffer, test.str);
        cppclass::upper(buffer);
        EXPECT_EQ(std::string(buffer), std::string(test.expected));
    }
}

TEST(HW06, LOWER) {
    struct LowerTestType {
        const char* str;
        const char* expected;
    };

    LowerTestType tests[] = {
        {"a", "a"},
        {"A", "a"},
        {"HELLO", "hello"},
        {"HELLO BAR", "hello bar"},
        {"lower", "lower"},
        {"LOWER", "lower"},
        {"", ""},
        {"MiXeD", "mixed"},
        {"123454321", "123454321"},
        {"12ABCDE21", "12abcde21"},
    };

    for (auto&& test : tests) {
        char buffer[8192];
        strcpy(buffer, test.str);
        cppclass::lower(buffer);
        EXPECT_EQ(std::string(buffer), std::string(test.expected));
    }
}
