#include <stdio.h>

/*  prints a table of corresponding Celsius
	and Fahrenheit temperatures */

main()
{
	float celsius, fahr;
	int lower, upper, step;

	lower = -100;
	upper = 300;
	step = 20;

	celsius = lower;

	while (celsius <= upper) 
	{
		fahr = (celsius * (9.0/5.0)) + 32.0;
		printf("%4.0f %6.1f\n", celsius, fahr);
		celsius = celsius + step;
	}
}
