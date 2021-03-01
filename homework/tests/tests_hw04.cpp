#include <cmath>

#include "hw04.h"
#include "gtest/gtest.h"

TEST(HW04, INT_POW) {
    EXPECT_EQ(int_pow(4, 0), 1);
    EXPECT_EQ(int_pow(4, 1), 4);
    EXPECT_EQ(int_pow(4, 2), 16);
    EXPECT_EQ(int_pow(4, 3), 64);
    EXPECT_EQ(int_pow(4, 4), 256);
    EXPECT_EQ(int_pow(2, 0), 1);
    EXPECT_EQ(int_pow(1, 0), 1);
    EXPECT_EQ(int_pow(1, 55), 1);
    EXPECT_EQ(int_pow(5, 3), 125);
}

TEST(HW04, RANGE_SUM) {
    EXPECT_EQ(range_sum(0), 0);
    EXPECT_EQ(range_sum(1), 0);
    EXPECT_EQ(range_sum(2), 1);
    EXPECT_EQ(range_sum(11), 55);
    EXPECT_EQ(range_sum(21), 210);
}

TEST(HW04, FIBONACCI) {
    EXPECT_EQ(fibonacci(0), 0);
    EXPECT_EQ(fibonacci(1), 1);
    EXPECT_EQ(fibonacci(2), 1);
    EXPECT_EQ(fibonacci(3), 2);
    EXPECT_EQ(fibonacci(4), 3);
    EXPECT_EQ(fibonacci(5), 5);
    EXPECT_EQ(fibonacci(6), 8);
    EXPECT_EQ(fibonacci(7), 13);
    EXPECT_EQ(fibonacci(8), 21);
    EXPECT_EQ(fibonacci(9), 34);
    EXPECT_EQ(fibonacci(10), 55);
    EXPECT_EQ(fibonacci(11), 89);
    EXPECT_EQ(fibonacci(12), 144);
    EXPECT_EQ(fibonacci(15), 610);
    EXPECT_EQ(fibonacci(100), 3314859971);
}

TEST(HW04, BISECT_CUBICROOT) {
    double ACCURACY = 0.001;

    EXPECT_NEAR(bisect_cubicroot(1000),   pow(1000, 1.0/3.0),   ACCURACY);
    EXPECT_NEAR(bisect_cubicroot(729),    pow(729, 1.0/3.0),    ACCURACY);
    EXPECT_NEAR(bisect_cubicroot(512),    pow(512, 1.0/3.0),    ACCURACY);
    EXPECT_NEAR(bisect_cubicroot(343),    pow(343, 1.0/3.0),    ACCURACY);
    EXPECT_NEAR(bisect_cubicroot(216),    pow(216, 1.0/3.0),    ACCURACY);
    EXPECT_NEAR(bisect_cubicroot(125),    pow(125, 1.0/3.0),    ACCURACY);
    EXPECT_NEAR(bisect_cubicroot(1000.5), pow(1000.5, 1.0/3.0), ACCURACY);
    EXPECT_NEAR(bisect_cubicroot(1e7),    pow(1e7, 1.0/3.0),    ACCURACY);
    EXPECT_NEAR(bisect_cubicroot(1),      pow(1, 1.0/3.0),      ACCURACY);

    EXPECT_NEAR(bisect_cubicroot(0.5),    pow(0.5, 1.0/3.0),    ACCURACY);
    EXPECT_NEAR(bisect_cubicroot(0.25),   pow(0.25, 1.0/3.0),   ACCURACY);
    EXPECT_NEAR(bisect_cubicroot(0.1),    pow(0.1, 1.0/3.0),    ACCURACY);
}
