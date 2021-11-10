#include "hw07.h"
#include "gtest/gtest.h"
#include <stdexcept>
#include <iostream>

namespace cppclass
{
TEST(HW07, gcd)
{
    struct TestDefinition {
        int a;
        int b;
        int expected_answer;
    };

    TestDefinition test_defs[] = {
        {1, 1, 1},
        {1, 5, 1},
        {2, 5, 1},
        {2, 4, 2},
        {10, 100, 10},
        {50, 100, 50},
        {42, 56, 14},
        {54, 48, 6},
    };

    {
        for (auto& test : test_defs) {
            EXPECT_EQ(cppclass::Fraction::_gcd(test.a, test.b), test.expected_answer);
        }
    }
}

TEST(HW07, lcm)
{
    struct TestDefinition {
        int a;
        int b;
        int expected_answer;
    };

    TestDefinition test_defs[] = {
        {1, 1, 1},
        {1, 5, 5},
        {5, 1, 5},
        {5, 5, 5},
        {2, 3, 6},
        {7, 11, 77},
        {2, 2, 2},
        {1, 99, 99},
        {4, 7, 28},
        {10, 100, 100},
    };

    {
        for (auto& test : test_defs) {
            EXPECT_EQ(cppclass::Fraction::_lcm(test.a, test.b), test.expected_answer);
        }
    }
}

TEST(HW07, constructor_basic)
{
    struct TestDefinition {
        int numerator;
        int denominator;
    };

    TestDefinition test_defs[] = {
        {1, 1},
        {1, 2},
        {10, 1},
    };

    {
        for (auto& test : test_defs) {
            cppclass::Fraction f = cppclass::Fraction(test.numerator, test.denominator);
            EXPECT_EQ(test.numerator, f._numerator);
            EXPECT_EQ(test.denominator, f._denominator);
        }
    }
}

TEST(HW07, constructor_simplify)
{
    struct TestDefinition {
        int numerator;
        int denominator;
        int expected_numerator;
        int expected_denominator;
    };

    TestDefinition test_defs[] = {
        {2, 2, 1, 1},
        {4, 2, 2, 1},
        {2, 4, 1, 2},
        {3, 9, 1, 3},
        {-3, 9, -1, 3},
        {3, -9, -1, 3},
        {-3, -9, 1, 3},
        {0, 1, 0, 1},
        {0, 100, 0, 1},
        {0, -100, 0, 1},
    };

    {
        for (auto& test : test_defs) {
            cppclass::Fraction f = cppclass::Fraction(test.numerator, test.denominator);
            EXPECT_EQ(test.expected_numerator, f._numerator);
            EXPECT_EQ(test.expected_denominator, f._denominator);
            EXPECT_EQ(cppclass::Fraction::_gcd(f._numerator, f._denominator), 1);
        }
    }
}

TEST(HW07, fraction_equality)
{
    struct TestDefinition {
        int a_numerator;
        int a_denominator;
        int b_numerator;
        int b_denominator;
    };

    TestDefinition test_defs[] = {
        {1, 1, 1, 1},
        {-1, 1, -1, 1},
        {1, -1, -1, 1},
        {1, 1, -1, -1},
        {1, 1, -2, -2},
    };

    {
        for (auto& test : test_defs) {
            cppclass::Fraction a = cppclass::Fraction(test.a_numerator, test.a_denominator);
            cppclass::Fraction b = cppclass::Fraction(test.b_numerator, test.b_denominator);

            EXPECT_TRUE(a == a);
            EXPECT_TRUE(b == b);
            EXPECT_TRUE(a == b);
        }
    }
}

TEST(HW07, fraction_inequality)
{
    struct TestDefinition {
        int a_numerator;
        int a_denominator;
        int b_numerator;
        int b_denominator;
    };

    TestDefinition test_defs[] = {
        {1, 1, 1, 2},
        {-1, 1, -1, 3},
        {1, -1, -1, 4},
        {1, 1, -1, -5},
        {1, 1, -2, -6},
    };

    {
        for (auto& test : test_defs) {
            cppclass::Fraction a = cppclass::Fraction(test.a_numerator, test.a_denominator);
            cppclass::Fraction b = cppclass::Fraction(test.b_numerator, test.b_denominator);

            EXPECT_TRUE(a == a);
            EXPECT_TRUE(b == b);
            EXPECT_TRUE(a != b);
        }
    }
}

TEST(HW07, fraction_add)
{
    struct TestDefinition {
        cppclass::Fraction a;
        cppclass::Fraction b;
        cppclass::Fraction result;
    };

    TestDefinition test_defs[] = {
        {cppclass::Fraction(1,1), cppclass::Fraction(1,1), cppclass::Fraction(2,1)},
        {cppclass::Fraction(1,2), cppclass::Fraction(1,3), cppclass::Fraction(5,6)},
        {cppclass::Fraction(1,10), cppclass::Fraction(1,10), cppclass::Fraction(1,5)},
        {cppclass::Fraction(1,9), cppclass::Fraction(1,9), cppclass::Fraction(2,9)},
        {cppclass::Fraction(1,2), cppclass::Fraction(1,2), cppclass::Fraction(1,1)},
        {cppclass::Fraction(1,2), cppclass::Fraction(2,4), cppclass::Fraction(1,1)},
        {cppclass::Fraction(1,2), cppclass::Fraction(-1,2), cppclass::Fraction(0,1)},
    };

    {
        for (auto& test : test_defs) {
            EXPECT_TRUE(test.a + test.b == test.result);
        }
    }
}

TEST(HW07, fraction_subtract)
{
    struct TestDefinition {
        cppclass::Fraction a;
        cppclass::Fraction b;
        cppclass::Fraction result;
    };

    TestDefinition test_defs[] = {
        {cppclass::Fraction(1,1), cppclass::Fraction(1,1), cppclass::Fraction(0,1)},
        {cppclass::Fraction(1,2), cppclass::Fraction(1,3), cppclass::Fraction(1,6)},
        {cppclass::Fraction(1,2), cppclass::Fraction(1,2), cppclass::Fraction(0,1)},
        {cppclass::Fraction(1,2), cppclass::Fraction(2,2), cppclass::Fraction(-1,2)},
        {cppclass::Fraction(2,9), cppclass::Fraction(1,9), cppclass::Fraction(1,9)},
        {cppclass::Fraction(1,9), cppclass::Fraction(2,9), cppclass::Fraction(-1,9)},
    };

    {
        for (auto& test : test_defs) {
            EXPECT_TRUE(test.a - test.b == test.result);
        }
    }
}

TEST(HW07, fraction_multiply)
{
    struct TestDefinition {
        cppclass::Fraction a;
        cppclass::Fraction b;
        cppclass::Fraction result;
    };

    TestDefinition test_defs[] = {
        {cppclass::Fraction(1,1), cppclass::Fraction(1,1), cppclass::Fraction(1,1)},
        {cppclass::Fraction(1,1), cppclass::Fraction(0,1), cppclass::Fraction(0,1)},
        {cppclass::Fraction(1,2), cppclass::Fraction(3,4), cppclass::Fraction(3,8)},
        {cppclass::Fraction(1,10), cppclass::Fraction(1,10), cppclass::Fraction(1,100)},
        {cppclass::Fraction(1,10), cppclass::Fraction(10,1), cppclass::Fraction(1,1)},
        {cppclass::Fraction(-1,10), cppclass::Fraction(10,1), cppclass::Fraction(-1,1)},
    };

    {
        for (auto& test : test_defs) {
            EXPECT_TRUE(test.a * test.b == test.result);
        }
    }
}

TEST(HW07, fraction_divide)
{
    struct TestDefinition {
        cppclass::Fraction a;
        cppclass::Fraction b;
        cppclass::Fraction result;
    };

    TestDefinition test_defs[] = {
        {cppclass::Fraction(1,1), cppclass::Fraction(1,1), cppclass::Fraction(1,1)},
        {cppclass::Fraction(1,2), cppclass::Fraction(1,2), cppclass::Fraction(1,1)},
        {cppclass::Fraction(10,2), cppclass::Fraction(2,10), cppclass::Fraction(25,1)},
        {cppclass::Fraction(1,10), cppclass::Fraction(2,10), cppclass::Fraction(1,2)},
        {cppclass::Fraction(1,10), cppclass::Fraction(-2,10), cppclass::Fraction(-1,2)},
    };

    {
        for (auto& test : test_defs) {
            EXPECT_TRUE(test.a / test.b == test.result);
        }
    }
}

}
