#include <iostream>
#include <cstdlib>
#include <cmath>
double hyp (double a,double b);
double hyp (double a,double b)
{
	double c;
	c = a * a + b * b;

	return std::pow(c,0.5);
}

int main(int argc, char **argv)
{
	double s1,s2,s3;
	std::cout << "Please enter side a: ";
	std::cin >> s1;
	std::cout << "Please enter side b: ";
	std::cin >> s2;
       	s3 = hyp (s1,s2);
       	
	std::cout<<"hypotensue is " <<s3<<std::endl;
	return EXIT_SUCCESS;
}
