#pragma once

#include <gtest/gtest_prod.h>

namespace cppclass
{
    class Fraction
    {
    public:
        // Do not allow the declaration of a Fraction without initializing it
        Fraction() = delete;

        // Allow Fractions to be decleared w/ inputs initialized
        // All fractions should be normalized
        // If denominator is 0, throws a std::runtime_error Exception
        Fraction(int numerator, int denominator);

        Fraction operator+(const Fraction &other) const;
        Fraction operator-(const Fraction &other) const;
        Fraction operator*(const Fraction &other) const;
        Fraction operator/(const Fraction &other) const;

        bool operator==(const Fraction &other) const;
        bool operator!=(const Fraction &other) const;

    private:
        int _numerator;
        int _denominator;

        // Post-requisite: _numerator/_denominator  will be changed such that:
        //   * numerator and denominator become simplified
        //   * numerator and denominator are relatively prime
        //     e.g. gcd(numerator, denominator) == 1
        //   * if numerator or denomintor are negative, but not both,
        //     make only numerator negative, and make denominator positive
        //   * if numerator and denominator are both negative, make both
        //     numerator and denominator positive
        //   * if numerator is 0, set denominator to 1
        void _simplify();

        // Returns greatest common divisor between a and b
        // Examples: 1, 1 -> 1
        //           1, 5 -> 1
        //           2, 5 -> 1
        //           2, 4 -> 2
        //           10, 100 -> 10
        //           50, 100 -> 50
        //           42, 56 -> 14
        //           54, 48 -> 6
        static int _gcd(int a, int b);

        // Returns least common multiple between a and b
        // Examples: 1, 1 -> 1
        //           2, 3 -> 6
        //           7, 11 -> 77
        //           2, 2 -> 2
        //           1, 99 -> 99
        //           4, 7 -> 28
        //           10, 100 -> 100
        static int _lcm(int a, int b);

        // friend class for gtest infrastructure
        FRIEND_TEST(HW07, gcd);
        FRIEND_TEST(HW07, lcm);
        FRIEND_TEST(HW07, constructor_basic);
        FRIEND_TEST(HW07, constructor_simplify);
    };
}
