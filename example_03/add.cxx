#include <cstdio>
#include <cstdlib>
#include <iostream>

int main (int argc, char **argv)
{
	short a = -32769;
	short b = 0;

	std::cout << "a = " << a << std::endl;
	std::cout << "Enter first number to add: ";
	std::cin >> a;
	std::cout << "a = " << a << std::endl;

	std::cout << "Enter second number to add: ";
	std::cin >> b;

	short sum = a + b;
	std::cout << a << " + " << b << " = " << sum << std::endl;
	//printf("%i + %i = %i\n", a, b, sum);

	return EXIT_SUCCESS;
}
