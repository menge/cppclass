#include <cstdlib>
#include <iostream>
#include <iomanip>

// Function Prototype
double interest(double amount, double years, double interest_rate);

// Function body
double interest(double amount, double years, double interest_rate)
{
	std::cout << std::setw(10) << "year"
		  << std::setw(10) << "int rate"
		  << std::setw(10) << "base"
		  << std::setw(10) << "int paid"
		  << std::setw(10) << "new amt"
		  << std::endl;
	double base_cost = amount;
	for (int i = 0; i < years; i++)
	{
		double interest = base_cost * interest_rate;
		double total = interest + base_cost;

		std::cout << std::setw(10) << i
		          << std::setw(10) << interest_rate
		          << std::setw(10) << base_cost
		          << std::setw(10) << interest
		          << std::setw(10) << total
			  << std::endl;

		base_cost = total;
                {
                        i = 100;
                        std::cout << i << std::endl;
                }
                std::cout << i << std::endl;
	}
	return base_cost;
}

int main(int argc, char **argv)
{
	interest(100000,30,0.05);
	return EXIT_SUCCESS;
}
