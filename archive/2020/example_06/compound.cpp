#include <cstdlib>
#include <iostream>

int main (int argc, char** argv)
{
	double inflation_rate;
	double cost;
	int year_limit;

	std::cout << "Put in inflation rate: ";
	std::cin >> inflation_rate;
	std::cout << "Put in base cost: ";
	std::cin >> cost;
	std::cout << "Put number of years to run: ";
	std::cin >> year_limit;
	
	for (int year = 0; year <= year_limit; year++, cost = cost * (1 + inflation_rate))
	{
		std::cout << "Year " << year << " cost: " << cost << std::endl;
	}
	
	return EXIT_SUCCESS;
}
