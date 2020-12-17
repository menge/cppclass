#include <iostream>
#include <stdlib.h>

int main (int argc, char **argv)
{
	//char anthonyAge = 90;
	short anthonyAge = 10;
	const short HORRIBLE_LIE = 3;

	anthonyAge = anthonyAge - HORRIBLE_LIE;

	// TODO: Remember to talk about CRLF -> std::endl
	std::cout << "Hello Anthony!!" << std::endl;
	std::cout << "You are a hard worker at " 
		  << anthonyAge * 2 << " years old" << std::endl;

	return EXIT_SUCCESS;
}
