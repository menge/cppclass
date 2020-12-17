#include <cstdlib>
#include <iostream>

int main (int argc, char** argv)
{
	short years;
	std::cout << "Please enter your age: ";
	std::cin >> years;

	short weight;
	std::cout << "Please enter your weight: ";
	std::cin >> weight;

	if (years == 0)
	{
		std::cout << "How are you alive????" << std::endl;
	}
	else if (years == 5)
	{
		std::cout << "You are a five year old!!" << std::endl;
	}
	else if (years <= 17)
	{
		std::cout << "You are a minor." << std::endl;
	}
	else if ((years >= 65) || (weight > 4000))
	{
		std::cout << "Are you a geriatric elephant?" << std::endl;
	}
	else if (years >= 65)
	{
		std::cout << "You are a senior." << std::endl;
	}
	else
	{
		std::cout << "You are an adult." << std::endl;
	}

	return EXIT_SUCCESS;
}
