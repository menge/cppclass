#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>
                   
// Function Prototype
int example(const int &n);

int example(int *n);

// Function Body
int example(const int &n)
{
	n = 10;
	return n-10;
}

int example(int *n)
{
	*n = 10;
	return *n-10;
}

int main (int argc, char** argv)
{
	int foo = 100;

	std::cout << "pre-execution number:" << foo << std::endl;

	example(foo);

	std::cout << "post-execution number:" << foo << std::endl;

	return EXIT_SUCCESS;
}
