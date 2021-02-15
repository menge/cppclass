#include <cmath>

#include "hw02.h"
#include "gtest/gtest.h"

TEST(HW02, NEGATE_BOOL) {
    EXPECT_EQ (negate_bool(true), false);
    EXPECT_EQ (negate_bool(false), true);
}

TEST(HW02, INT_SUM) {
    EXPECT_EQ (int_sum(0, 0), 0);
    EXPECT_EQ (int_sum(1, 0), 1);
    EXPECT_EQ (int_sum(0, 1), 1);
    EXPECT_EQ (int_sum(2, 2), 4);
    EXPECT_EQ (int_sum(10, -10), 0);
    EXPECT_EQ (int_sum(100, 10), 110);
    EXPECT_EQ (int_sum(-10, -20), -30);
}

TEST(HW02, MIN2SECS) {
    EXPECT_EQ (min2secs(0), 0);
    EXPECT_EQ (min2secs(1), 60);
    EXPECT_EQ (min2secs(2), 120);
    EXPECT_EQ (min2secs(5), 300);
    EXPECT_EQ (min2secs(-1), -60);
}

TEST(HW02, AREA_OF_SQUARE) {
    EXPECT_EQ (area_of_square(1), 1);
    EXPECT_EQ (area_of_square(2), 4);
    EXPECT_EQ (area_of_square(5), 25);
    EXPECT_EQ (area_of_square(9), 81);
    EXPECT_EQ (area_of_square(12), 144);
    EXPECT_EQ (area_of_square(100), 10000);

    EXPECT_EQ (area_of_square(1.5), 2.25);
}

TEST(HW02, AREA_OF_TRIANGLE) {
    EXPECT_EQ (area_of_triangle(1, 1), 0.5);
    EXPECT_EQ (area_of_triangle(2, 1), 1);
    EXPECT_EQ (area_of_triangle(1, 2), 1);
    EXPECT_EQ (area_of_triangle(10, 5), 25);
    EXPECT_EQ (area_of_triangle(3, 100), 150);
}

TEST(HW02, PERIMITER_OF_RECTANGLE) {
    EXPECT_EQ (perimiter_of_rectangle(1, 1), 4);
    EXPECT_EQ (perimiter_of_rectangle(2, 1), 6);
    EXPECT_EQ (perimiter_of_rectangle(2, 9), 22);
    EXPECT_EQ (perimiter_of_rectangle(0.5, 0.25), 1.5);
}

TEST(HW02, AREA_OF_CIRCLE) {
    EXPECT_NEAR (area_of_circle(1), M_PI, pow(2, -40));
    EXPECT_NEAR (area_of_circle(1.5), 2.25 * M_PI, pow(2, -40));
    EXPECT_NEAR (area_of_circle(10), 100 * M_PI, pow(2, -40));
    EXPECT_NEAR (area_of_circle(4.25), 18.0625 * M_PI, pow(2, -40));
}

TEST(HW02, DIV_FLOOR) {
    EXPECT_EQ (div_floor(0, 5), 0);
    EXPECT_EQ (div_floor(1, 5), 0);
    EXPECT_EQ (div_floor(4, 5), 0);
    EXPECT_EQ (div_floor(5, 5), 1);
    EXPECT_EQ (div_floor(6, 5), 1);
    EXPECT_EQ (div_floor(10, 5), 2);
    EXPECT_EQ (div_floor(200, 2), 100);
    EXPECT_EQ (div_floor(201, 2), 100);
}

TEST(HW02, DIV_REMAINDER) {
    EXPECT_EQ (div_remainder(0, 5), 0);
    EXPECT_EQ (div_remainder(1, 5), 1);
    EXPECT_EQ (div_remainder(2, 5), 2);
    EXPECT_EQ (div_remainder(4, 5), 4);
    EXPECT_EQ (div_remainder(5, 5), 0);
    EXPECT_EQ (div_remainder(6, 5), 1);
    EXPECT_EQ (div_remainder(200, 2), 0);
    EXPECT_EQ (div_remainder(201, 2), 1);
    EXPECT_EQ (div_remainder(202, 2), 0);
}

TEST(HW02, FARENHEIT_TO_CELSIUS) {
    EXPECT_NEAR (farenheit_to_celsius(32), 0, pow(2, -40));
    EXPECT_NEAR (farenheit_to_celsius(212), 100, pow(2, -40));
    EXPECT_NEAR (farenheit_to_celsius(33), 0 + (5/9.), pow(2, -40));
    EXPECT_NEAR (farenheit_to_celsius(34), 0 + (10/9.), pow(2, -40));
    EXPECT_NEAR (farenheit_to_celsius(-40), -40, pow(2, -40));
}

TEST(HW02, CELSIUS_TO_FAHRENHEIT) {
    EXPECT_NEAR (celsius_to_fahrenheit(0), 32, pow(2, -40));
    EXPECT_NEAR (celsius_to_fahrenheit(100), 212, pow(2, -40));
    EXPECT_NEAR (celsius_to_fahrenheit(-40), -40, pow(2, -40));
    EXPECT_NEAR (celsius_to_fahrenheit(1), 32 + (9/5.), pow(2, -40));
    EXPECT_NEAR (celsius_to_fahrenheit(2), 32 + (18/5.), pow(2, -40));
}
