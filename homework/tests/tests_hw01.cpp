#include <cmath>

#include "hw01.h"
#include "gtest/gtest.h"

TEST(HW01, RETURN_TRUE) {
    EXPECT_EQ (return_true(), true);
}

TEST(HW01, RETURN_FALSE) {
    EXPECT_EQ (return_false(), false);
}

TEST(HW01, RETURN_42) {
    EXPECT_EQ (return_42(), 42);
}

TEST(HW01, RETURN_NEG_42) {
    EXPECT_EQ (return_neg_42(), -42);
}

TEST(HW01, RETURN_1P5) {
    EXPECT_EQ (return_1p5(), 1.5);
}

TEST(HW01, RETURN_PI) {
    EXPECT_EQ (return_pi(), M_PI);
}
