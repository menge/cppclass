#include <iostream>
#include <iomanip>
#include <cstdlib>

int main(int argc, char **argv)
{
	int user_base;
	int user_cycles;

	std::cout << "Please give me your base: ";
	std::cin >> user_base;

	std::cout << "Please enter the cycles: ";
	std::cin >> user_cycles;
#if 0
user_base :: 50
user_cycles :: 10

50
51
52
53
54
55
56
57
58
59
#endif


#if 0
std::cout << std::setw(20) << "iteration number"
<< std::setw(10) << "user_base"
<< std::setw(20) << "desired result"
<< std::endl;

	for (int count = 0; count < user_cycles; count++)
	{
			<< std::setw(10) << user_base
			<< std::setw(20) << user_base + count
			<< std::endl;
	}
#endif
	for (int x = 0; x <= 12; x++)
	{
		for (int y = 0; y <= 12; y++)
		{
			for (int z = 0; z <= 12; z++)
			{
				std::cout << x << " * " << y << " * " << z << " = " << x*y*z << std::endl;
			}
		}
	}

        while (true)
        {



            // update
        }

        do
        {
            //loop
        } while (cond);

}
