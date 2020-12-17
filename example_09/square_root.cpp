#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <iostream>

// Function Prototype
double square_root(double n);

// Function body
double square_root(double n)
{
	const double ERROR = std::pow(2, -30);

	double min = 0.0;
	double max = std::max(1.0, n);

	double mid;
	double guess_result;

	for ( bool loop_intialized = false; 
	      std::abs(guess_result - n) > ERROR;
              mid = (max + min) / 2, guess_result = mid * mid
	    )
	{
		// This section exists to ensure that our update is run before utilization of mid and guess_result
		if (not loop_intialized)
		{
			loop_intialized = true;
			continue;
		}

		if (guess_result > n)
		{
			max = mid;
		}
		else
		{
			min = mid;
		}
	}

	return mid;
}

int main(int argc, char **argv)
{
	std::cout << "Enter number to be square rooted: ";
	double input;
	std::cin >> input;

	double test = square_root(input);
	std::cout << "Square root of (" << input << ") is " << test << std::endl;
	return EXIT_SUCCESS;
}
