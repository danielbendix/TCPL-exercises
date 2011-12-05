#include <stdio.h>

/* copy input to output, replacing each tab by \t, each backspace by \b, and each backslash by \\ */
main()
{
	int c, np;
	
	while ((c = getchar()) != EOF)
	{
		np = 1;
		if (c == '\t')
		{
			putchar('\\');
			putchar('t');
			np = 0;
		}
		
		if (c == '\b')
		{
			putchar('\\');
			putchar('b');
			np = 0;
		}
		
		if (c == '\\')
		{
			putchar('\\');
			putchar('\\');
			np = 0;
		}
		
		if (np)
		{
			putchar(c);
		}
	}
}