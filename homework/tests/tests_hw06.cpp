#include <cmath>

#include "hw06.h"
#include "gtest/gtest.h"


TEST(HW06, STRLEN_NORMAL_CASES) {
    const char *tests[] = { "hello",
                            "asdfghjkl;",
                            "AA",
                            "Z",
                            "8n428vnr8hsz09yt2308ysfhvea093auq0r310h30y",
                            " ",
                            "      ",
                            "\t",
                            "\n",
    };

    for (auto&& test : tests) {
        EXPECT_EQ(cppclass::strlen(test), strlen(test));
    }
}

TEST(HW06, STRLEN_CONRNER_CASES) {
    EXPECT_EQ(cppclass::strlen(""), strlen(""));
}
