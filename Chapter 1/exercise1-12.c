#include <stdio.h>

#define IN 1
#define OUT 0

/* takes input and prints every word on a single line */

main()
{
	int c, state, delim;
	
	state = OUT;
	while ((c = getchar()) != EOF)
	{
		if ((c == '\n' || c == ' ' || c == '\t'))
		{
			if (state == IN)
			{
				putchar('\n');
				state = OUT;
			}
		} else {
			putchar(c);
			state = IN;
		}
	}
}