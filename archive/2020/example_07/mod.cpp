#include <cstdlib>
#include <cmath>
#include <iostream>

// Function Prototype
bool isEven(int n);
bool isOdd(int n);

// Function Body
bool isEven(int n)
{
	if (n % 2 == 0)
	{
		return true;
	}
	return false;
}

bool isOdd(int n)
{
	return not isEven(n);
}

int main (int argc, char** argv)
{
	for (int i = 0; i < 100; i++)
	{
		if (isEven(i))
		{
			std::cout << i << " is Even" << std::endl;
		}
	}

	return EXIT_SUCCESS;
}
