#include <iostream>
#include <vector>
#include <map>
#include <assert.h>
#include <stdlib.h>
#include <math.h>

double discount(double base_price, int age, double discount_rate);
double discount(double base_price, int age, double discount_rate)
{
	double discount_per_age;
	 
	if (age <= 6)
	{
		discount_per_age = 1.00;
	}
	if (age < 18 and age >= 7)
	{
		discount_per_age = 0.30;
	}
	if (age < 65 and age >= 18)
	{
		discount_per_age = 0.0;
	}
	if (age >= 65)
	{
		discount_per_age = 0.50;
	}

	discount_rate += discount_per_age;

	if (discount_rate > 1.0)
	{
		discount_rate = 1.0;
	}

	double discount_amount = base_price * discount_rate;
	base_price = base_price - discount_amount;
		
	return base_price;

}

int main (int argc, char **argv)
{
	// normal age
	int age = 20;
	assert(discount(100, age, 0) == 100);
	assert(discount(100, age, 0.10) == 90);
	assert(discount(100, age, 1.00) == 0);
	assert(discount(1000, age, 0) == 1000);
	assert(discount(1000, age, 0.10) == 900);
	assert(discount(1000, age, 1.00) == 0);
	assert(discount(0, age, 0) == 0);
	assert(discount(0, age, 0.10) == 0);
	assert(discount(0, age, 1.00) == 0);
	
	// young kid -- gets 100% discount
	for ( int i = 0; i < 7; i++)
	{
		assert(discount(100, i, 0) == 0);
		assert(discount(100, i, 0.10) == 0);
		assert(discount(100, i, 1.00) == 0);
		assert(discount(1000, i, 0) == 0);
		assert(discount(1000, i, 0.10) == 0);
		assert(discount(1000, i, 1.00) == 0);
		assert(discount(0, i, 0) == 0);
		assert(discount(0, i, 0.10) == 0);
		assert(discount(0, i, 1.00) == 0);
	}

	// adolscent kid (7-17)-- gets 30% discount
	for ( int i = 7; i < 18; i++)
	{
		assert(discount(100, i, 0) == 70);
		assert(discount(100, i, 0.10) == 60);
		assert(discount(100, i, 1.00) == 0);
		assert(discount(1000, i, 0) == 700);
		assert(discount(1000, i, 0.10) == 600);
		assert(discount(1000, i, 1.00) == 0);
		assert(discount(0, i, 0) == 0);
		assert(discount(0, i, 0.10) == 0);
		assert(discount(0, i, 1.00) == 0);
	}

	// senior (65+)-- gets 50% discount
	age = 65;
	assert(discount(100, age, 0) == 50);
	assert(discount(100, age, 0.10) == 40);
	assert(discount(100, age, 1.00) == 0);
	assert(discount(1000, age, 0) == 500);
	assert(discount(1000, age, 0.10) == 400);
	assert(discount(1000, age, 1.00) == 0);
	assert(discount(0, age, 0) == 0);
	assert(discount(0, age, 0.10) == 0);
	assert(discount(0, age, 1.00) == 0);

	return EXIT_SUCCESS;
}
