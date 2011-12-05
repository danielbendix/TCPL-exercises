#include <stdio.h>

/* count blanks, tabs, and lines */
main()
{
	int c, nb, nt, nl;
	
	nb = 0;
	nt = 0;
	nl = 0;
	while ((c = getchar()) != EOF)
	{
		if (c == ' ')
			++nb;
		
		if (c == '\t')
			++nt;
		
		if (c == '\n')
			++nl;
	}
	
	printf("%d blanks, %d tabs, and %d lines.", nb, nt, nl);
}