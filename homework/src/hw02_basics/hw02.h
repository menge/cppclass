#pragma once

// Pre-conditions: none
// Post-conditions: none
// Returns: the opposite of what is passed in
bool negate_bool(bool in);

// Pre-conditions: none
// Post-conditions: none
// Returns: the sum of a and b
int int_sum(int a, int b);

// Pre-conditions: none
// Post-conditions: none
// Returns: converts the number of minutes given into seconds
int min2secs(int minutes);

// Pre-conditions: side > 0
// Post-conditions: none
// Returns: the square units given a side of the square
double area_of_square(double side);

// Pre-conditions: base > 0, height > 0
// Post-conditions: none
// Returns: always returns value: -42
double area_of_triangle(double base, double height);

// Pre-conditions: width > 0, height > 0
// Post-conditions: none
// Returns: the perimeter of a rectangle
double perimiter_of_rectangle(double width, double height);

// Pre-conditions: radius > 0
// Post-conditions: none
// Returns: the area of a circle (note that area of circle is PI * r*r (e.g. r**2))
double area_of_circle(double radius);

// Pre-conditions: q is not 0
// Post-conditions: none
// Returns: the number of whole times that a is divisible by q
int div_floor(int a, int q);

// Pre-conditions: q is not 0
// Post-conditions: none
// Returns: the remainder when a is divided by q
int div_remainder(int a, int q);

// Pre-conditions: none
// Post-conditions: none
// Returns: farenheit converted to celsius: c = (f - 32) * (5/9)
double farenheit_to_celsius(int f);

// Pre-conditions: none
// Post-conditions: none
// Returns: celsius converted to farenheit: f = (c * (9/5)) + 32
double celsius_to_fahrenheit(int c);
