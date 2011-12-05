#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

int celsius(int fahr);

/* make a table of Fahrenheit-Celsius values */
main()
{
	int fahr;
	
	fahr = LOWER;
	while (fahr <= UPPER)
	{
		printf("%3d %3d\n", fahr, celsius(fahr));
		fahr = fahr + STEP;
	}
	
	return 0;
}

/* convert Fahrenheit to Celsius */
int celsius(int fahr)
{
	return (5.0/9.0) * (fahr-32);
}