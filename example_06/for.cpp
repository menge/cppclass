#include <cstdlib>
#include <iostream>

int main (int argc, char** argv)
{
#if 1
	int i, j;
	for (i = 0, j = 1; i < 2000 and j < 2000; i += 10, j *= 2)
	{
		std::cout << i << " " << j << std::endl;
	}
#endif

#if 0
	for (int i = 0; i < 1000; i++)
	{
		for (int j = 0; j < 2000; j++)
		{
			foo;
		}
	}
#endif
#if 0

	
        int i = 0;
	int j = 1;
	while (i < 2000 and j < 2000)
	{
		std::cout << i << " " << j << std::endl;

		i = i + 10;
		j = j * 2;
	}

	for (double x = 1.0; x < 1000000.0; x *= 1.5)
	{
		//std::cout << x << std::endl;
		printf("%f\n", x);
	}
#endif

#if 0
	int count = 0;
	do
	{
		count += 1;
	} while (count < 10);
#endif
/*
	long long remainder = user_number % candidate;
	104 % 10 -> 4
        104 / 10 -> 10

	q(104) % d(10) -> r(4)
	d*d - q = -4

	q(94) - d*d = -6

	q - d*d = 4



	int p = -1;
	for (p = 0; p < 100; p++)
	{
	}

	p =1000;
	*/
	return EXIT_SUCCESS;
}
