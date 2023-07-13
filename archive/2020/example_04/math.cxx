#include <cstdio>
#include <cstdlib>
#include <iostream>

int main (int argc, char **argv)
{
	long divisor = 0;

	std::cout << "Enter divisor: ";
	std::cin >> divisor;

	for (int i = 0; i < 12 * divisor; i++)
	{
		long quotient = i / divisor;
		long remainder = i % divisor;
		std::cout << i << " / " << divisor << " = " << quotient << "r" << remainder << std::endl;
	}

	return EXIT_SUCCESS;
}
