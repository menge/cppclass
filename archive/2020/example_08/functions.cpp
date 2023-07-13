#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>

int g_status = 100;

// Function Prototype
bool isPrime(int n);
bool isPrime2(int n);

// Function Body
bool isPrime(int n)
{
	if (n <= 1)
	{
		return false;
	}
	for (int i = 2; i < n; i++)
	{
		if (n % i == 0)
		{
			return false;
		}
	}
	return true;
}

bool isPrime2(int n)
{
	if (n <= 1)
	{
		return false;
	}
	int limit = std::sqrt(n);
	for (int i = 2; i <= limit; i++)
	{
		if (n % i == 0)
		{
			return false;
		}
	}
	return true;
}

bool isPrime3(int n)
{
	if (i == 100)
	{
		;
	}

	if (n <= 1)
	{
		return false;
	}

	static std::vector<int> primes;

	int limit = std::sqrt(n);
	for (auto it = primes.begin(); it < primes.end(); it++)
	{
		if (n % *it == 0)
		{
			return false;
		}
	}
	primes.push_back(n);
	return true;
}


int main (int argc, char** argv)
{
	for (i = 0; i <= 10000000; i++)
	{
		if (isPrime2(i))
		{
			std::cout << i << std::endl;
		}
	}

	std::cout << "last number:" << i << std::endl;


#if 0
A: 100000000
B: 100000001
C:  99999999
D: 0
E: 100
F: 101
#endif

	return EXIT_SUCCESS;
}
