#include <cstdlib>
#include <iostream>

bool is_even(int num);
bool is_odd(int num);

bool is_even(int num)
{
	if (num % 2 == 0)
	{
		return true;
	}
	return false;
}
bool is_odd(int num)
{
	bool oddness = not is_even(num);
	return oddness;
}


int main (int argc, char** argv)
{
	int sum = 0;

	//for ( int i = 0; i < 6; i++)
	for (
			int i = 0; 
			i < 6; 
			i++)
	{
		sum += i;
		if (is_even(i))
		{
			sum += i;
		}
		if (is_odd(i))
		{
			sum -= i;
		}
	}
	std::cout << "Sum is " << sum << std::endl;

	return EXIT_SUCCESS;
}
