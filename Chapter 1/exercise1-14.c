#include <stdio.h>

/* count all lower case letters and print a histogram over these */
main()
{
	int c, mlo, i, j;
	int letterl[26];
	
	for (i = 0; i < 26; ++i)
		letterl[i] = 0;
	
	while ((c = getchar()) != EOF)
	{
		if (c >= 'a' && c <= 'z')
		{
			++letterl[c-'a'];
		}
		
		if (c >= 'A' && c <= 'Z')
		{
			++letterl[c-'A'];
		}
	}
	
	for (i = 0; i < 26; ++i)
	{
		if (letterl[i] > mlo)
		{
			mlo = letterl[i];
		}
	}
	
	for (i = mlo; i > 0; --i)
	{
		for (j = 0; j < 26; ++j)
		{
			if ( (letterl[j] - i) >= 0)
			{
				printf(" | ");
			} else {
				printf("   ");
			}
		}
		printf("\n");
	}

	for (i = 'a'; i <= 'z'; ++i)
	{
		printf(" %c ", i);
	}
	
	printf("\n");
}