#include <iostream>
#include <cstdlib>

int main(int argc, char **argv)
{
 	unsigned short earth_years = 0;
	
	std::cout<< "Enter the dogs Earth years: ";
	std::cin>> earth_years;
	unsigned short dogyear = 7 * earth_years;
	std::cout << earth_years << " Earth years is " << dogyear << " dog years." << std::endl;
	return EXIT_SUCCESS;
}
