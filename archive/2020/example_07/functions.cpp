#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>

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
	for (int i = 0; i < 10000000; i++)
	{
		if (isPrime3(i))
		{
			std::cout << i << std::endl;
		}
	}

	return EXIT_SUCCESS;
}
