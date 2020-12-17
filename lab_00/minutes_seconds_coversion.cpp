#include <cstdlib>
#include <iostream>

int main (int argc, char** argv)
{
	short user_minutes = -1;
	std::cout << "Please enter number of minutes to convert to seconds:";
	std::cin >> user_minutes;
	short product = user_minutes * 60;
	std::cout << user_minutes << " minute is " << product << " seconds" << std::endl;

	return EXIT_SUCCESS;
}
