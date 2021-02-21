#include <cmath>

#include "hw03.h"
#include "gtest/gtest.h"

TEST(HW03, ABS) {
    EXPECT_EQ(cppclass_abs(0), 0);
    EXPECT_EQ(cppclass_abs(1), 1);
    EXPECT_EQ(cppclass_abs(M_PI), M_PI);
    EXPECT_EQ(cppclass_abs(100), 100);
    EXPECT_EQ(cppclass_abs(100.5), 100.5);
    EXPECT_EQ(cppclass_abs(-1), 1);
    EXPECT_EQ(cppclass_abs(-1 * M_PI), M_PI);
    EXPECT_EQ(cppclass_abs(-100.5), 100.5);
}

TEST(HW03, MAX_OF_TWO) {
    // Equal a, b
    EXPECT_EQ(max_of_two_items(0, 0), 0);
    EXPECT_EQ(max_of_two_items(1, 1), 1);
    EXPECT_EQ(max_of_two_items(-10, -10), -10);

    // Positive a, b
    EXPECT_EQ(max_of_two_items(3, 5), 5);
    EXPECT_EQ(max_of_two_items(5, 3), 5);

    // Positive vs zero
    EXPECT_EQ(max_of_two_items(20, 0), 20);
    EXPECT_EQ(max_of_two_items(0, 20), 20);

    // Positive vs negative
    EXPECT_EQ(max_of_two_items(24, -10), 24);
    EXPECT_EQ(max_of_two_items(-10, 24), 24);

    // Negative vs negative
    EXPECT_EQ(max_of_two_items(-10, -6), -6);
    EXPECT_EQ(max_of_two_items(-6, -10), -6);

    // Negative vs zero
    EXPECT_EQ(max_of_two_items(-6, 0), 0);
    EXPECT_EQ(max_of_two_items(0, -6), 0);
}

TEST(HW03, MIN_OF_TWO) {
    // Equal a, b
    EXPECT_EQ(min_of_two_items(0, 0), 0);
    EXPECT_EQ(min_of_two_items(1, 1), 1);
    EXPECT_EQ(min_of_two_items(-10, -10), -10);

    // Positive a, b
    EXPECT_EQ(min_of_two_items(3, 5), 3);
    EXPECT_EQ(min_of_two_items(5, 3), 3);

    // Positive vs zero
    EXPECT_EQ(min_of_two_items(20, 0), 0);
    EXPECT_EQ(min_of_two_items(0, 20), 0);

    // Positive vs negative
    EXPECT_EQ(min_of_two_items(24, -10), -10);
    EXPECT_EQ(min_of_two_items(-10, 24), -10);

    // Negative vs negative
    EXPECT_EQ(min_of_two_items(-10, -6), -10);
    EXPECT_EQ(min_of_two_items(-6, -10), -10);

    // Negative vs zero
    EXPECT_EQ(min_of_two_items(-6, 0), -6);
    EXPECT_EQ(min_of_two_items(0, -6), -6);
}

TEST(HW03, MAX_OF_THREE) {
    // Equal a, b, c
    EXPECT_EQ(max_of_three_items(0, 0, 0), 0);
    EXPECT_EQ(max_of_three_items(1, 1, 1), 1);
    EXPECT_EQ(max_of_three_items(-1, -1, -1), -1);

    // a max
    EXPECT_EQ(max_of_three_items(100, 0, 0), 100);
    EXPECT_EQ(max_of_three_items(100, 99, 98), 100);
    EXPECT_EQ(max_of_three_items(100, -40, 98), 100);
    EXPECT_EQ(max_of_three_items(100, 99, -40), 100);
    EXPECT_EQ(max_of_three_items(-400, -500, -600), -400);
    EXPECT_EQ(max_of_three_items(-400, -600, -500), -400);

    // b max
    EXPECT_EQ(max_of_three_items(0, 100, 0), 100);
    EXPECT_EQ(max_of_three_items(20, 100, 0), 100);
    EXPECT_EQ(max_of_three_items(0, 100, 40), 100);
    EXPECT_EQ(max_of_three_items(-20, 100, 0), 100);
    EXPECT_EQ(max_of_three_items(0, 100, -40), 100);
    EXPECT_EQ(max_of_three_items(-600, -400, -500), -400);
    EXPECT_EQ(max_of_three_items(-500, -400, -600), -400);

    // c max
    EXPECT_EQ(max_of_three_items(0, 0, 100), 100);
    EXPECT_EQ(max_of_three_items(20, 0, 100), 100);
    EXPECT_EQ(max_of_three_items(0, 40, 100), 100);
    EXPECT_EQ(max_of_three_items(-20, 40, 100), 100);
    EXPECT_EQ(max_of_three_items(-20, -40, 100), 100);
    EXPECT_EQ(max_of_three_items(-600, -500, -400), -400);
    EXPECT_EQ(max_of_three_items(-500, -600, -400), -400);
}

TEST(HW03, IS_LEAP_YEAR) {
    EXPECT_EQ(is_leap_year(4), true);
    EXPECT_EQ(is_leap_year(5), false);
    EXPECT_EQ(is_leap_year(6), false);
    EXPECT_EQ(is_leap_year(7), false);
    EXPECT_EQ(is_leap_year(8), true);
    EXPECT_EQ(is_leap_year(9), false);
    EXPECT_EQ(is_leap_year(10), false);
    EXPECT_EQ(is_leap_year(11), false);
    EXPECT_EQ(is_leap_year(12), true);
    EXPECT_EQ(is_leap_year(96), true);
    EXPECT_EQ(is_leap_year(97), false);
    EXPECT_EQ(is_leap_year(98), false);
    EXPECT_EQ(is_leap_year(99), false);
    EXPECT_EQ(is_leap_year(100), false);
    EXPECT_EQ(is_leap_year(101), false);
    EXPECT_EQ(is_leap_year(102), false);
    EXPECT_EQ(is_leap_year(103), false);
    EXPECT_EQ(is_leap_year(104), true);
    EXPECT_EQ(is_leap_year(200), false);
    EXPECT_EQ(is_leap_year(300), false);
    EXPECT_EQ(is_leap_year(400), true);
    EXPECT_EQ(is_leap_year(500), false);
    EXPECT_EQ(is_leap_year(600), false);
    EXPECT_EQ(is_leap_year(700), false);
    EXPECT_EQ(is_leap_year(800), true);
    EXPECT_EQ(is_leap_year(1992), true);
    EXPECT_EQ(is_leap_year(1996), true);
    EXPECT_EQ(is_leap_year(2000), true);
    EXPECT_EQ(is_leap_year(2004), true);
    EXPECT_EQ(is_leap_year(2100), false);
}

TEST(HW03, SIMPLE_CALC) {
    EXPECT_EQ(simple_calc(4, 5, '+'), 9);
    EXPECT_EQ(simple_calc(5, 4, '+'), 9);
    EXPECT_EQ(simple_calc(0, 3, '+'), 3);
    EXPECT_EQ(simple_calc(3, 0, '+'), 3);
    EXPECT_EQ(simple_calc(-5, 5, '+'), 0);
    EXPECT_EQ(simple_calc(5, -5, '+'), 0);
    EXPECT_EQ(simple_calc(-5, -5, '+'), -10);

    EXPECT_EQ(simple_calc(4, 5, '-'), -1);
    EXPECT_EQ(simple_calc(5, 4, '-'), 1);
    EXPECT_EQ(simple_calc(0, 3, '-'), -3);
    EXPECT_EQ(simple_calc(3, 0, '-'), 3);
    EXPECT_EQ(simple_calc(-5, 5, '-'), -10);
    EXPECT_EQ(simple_calc(5, -5, '-'), 10);
    EXPECT_EQ(simple_calc(-5, -5, '-'), 0);

    EXPECT_EQ(simple_calc(4, 5, '*'), 20);
    EXPECT_EQ(simple_calc(5, 4, '*'), 20);
    EXPECT_EQ(simple_calc(0, 3, '*'), 0);
    EXPECT_EQ(simple_calc(3, 0, '*'), 0);
    EXPECT_EQ(simple_calc(-5, 5, '*'), -25);
    EXPECT_EQ(simple_calc(5, -5, '*'), -25);
    EXPECT_EQ(simple_calc(-5, -5, '*'), 25);

    EXPECT_EQ(simple_calc(5, 1, '/'), 5);
    EXPECT_EQ(simple_calc(5, -1, '/'), -5);
    EXPECT_EQ(simple_calc(1, 5, '/'), 0);
    EXPECT_EQ(simple_calc(10, 5, '/'), 2);
    EXPECT_EQ(simple_calc(12, -5, '/'), -2);

    EXPECT_EQ(simple_calc(5, 1, '%'), 0);
    EXPECT_EQ(simple_calc(1, 5, '%'), 1);
    EXPECT_EQ(simple_calc(10, 5, '%'), 0);
    EXPECT_EQ(simple_calc(999, 3, '%'), 0);
    EXPECT_EQ(simple_calc(999, 2, '%'), 1);
    EXPECT_EQ(simple_calc(999, 4, '%'), 3);
}
