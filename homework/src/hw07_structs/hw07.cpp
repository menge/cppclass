#include "hw07.h"

#include <algorithm>
#include <stdexcept>

namespace cppclass
{
    Fraction::Fraction(int numerator, int denominator)
    : _numerator(numerator)
    , _denominator(denominator)
    {
        if (_denominator == 0)
        {
            throw std::runtime_error("Attempted to divide by zero");
        }
        _simplify();
    }

    void Fraction::_simplify()
    {
    }

    int Fraction::_gcd(int a, int b)
    {
        return 0;
    }

    int Fraction::_lcm(int a, int b)
    {
        return 0;
    }

    Fraction Fraction::operator+(const Fraction &other) const
    {
        return Fraction(0, 1);
    }

    Fraction Fraction::operator-(const Fraction &other) const
    {
        return Fraction(0, 1);
    }

    Fraction Fraction::operator*(const Fraction &other) const
    {
        return Fraction(0, 1);
    }

    Fraction Fraction::operator/(const Fraction &other) const
    {
        return Fraction(0, 1);
    }

    bool Fraction::operator==(const Fraction &other) const
    {
        return false;
    }

    bool Fraction::operator!=(const Fraction &other) const
    {
        return false;
    }
}
