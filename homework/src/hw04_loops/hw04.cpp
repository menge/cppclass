#include <cmath>
#include <iostream>

#include "hw04.h"

// Pre-conditions: none
// Post-conditions: none
//
//          e.g. x=4, y=0 -> 1
//               x=4, y=1 -> 4
//               x=4, y=2 -> 16
//               x=4, y=3 -> 64/ Returns: returns the pow of x**y (aka x^y, x raised to the y)
unsigned int int_pow(unsigned int x, unsigned int y)
{
    return 0;
}

// Pre-conditions: none
// Post-conditions: none
// Returns: returns the sum of the numbers between [0, .. n]
//
//          if n == 11, the range would be
//              0,1,2,3,4,5,6,7,8,9,10
//
//          And then, you would return the sum of that sequence mentioned above:
//              0+1+2+3+4+5+6+7+8+9+10 -> 55
unsigned int range_sum(unsigned int n)
{
    return 0;
}

// Pre-conditions: none
// Post-conditions: none
// Returns: returns the nth number in the fibonacci sequence
//
//          The fibonacci sequence is defined as:
//              fib(0) = 0
//              fib(1) = 1
//              fib(n) = fib(n-2) + fib(n+1)
//          For example, the sequence would look like:
//              0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ...
unsigned int fibonacci(unsigned int n)
{
    return 0;
}

// Pre-conditions: input will be >= 0.0
// Post-conditions: none
// Returns: returns the cubic root of input calculated via bisection
//
//          Use the bisection algorithm to reduce the guessing space
//          window of where the potential answer could be located at
//
//          if the input is 25, a valid initial window would be [0, 25]
//
//          do note that numbers between [0,1] are a bit special, so think
//          about reasonable windows for those items
//
//          the return value must be within 0.001 of the real answer
//
//          also, the fabs function may be useful for you (floating point
//          absolute value)
//          
double bisect_cubicroot(double input)
{
    return 0.0;
}
