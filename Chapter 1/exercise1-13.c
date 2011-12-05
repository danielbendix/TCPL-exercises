#include <stdio.h>

#define IN 1
#define OUT 0
#define MWL 20

/* count length of words and make histogram of these */
main()
{
	int c, wl, mwo, state, i, j;
	int wordl[MWL];
	
	wl = mwo = 0;
	state = OUT;
	
	for (i = 0; i < MWL; ++i)
		wordl[i] = 0;
	
	while ((c = getchar()) != EOF)
	{
		if (c == ' ' || c == '\n' || c == ',' || c == '.' || c == '\t')
		{
			if (state == IN)
			{
				if (wl > 0)
					++wordl[wl-1];
				wl = 0;
				state = OUT;
			}
		} else {
			++wl;
			state = IN;
		}
	}
	
	for (i = 0; i < MWL; ++i)
	{
		if (mwo < wordl[i])
			mwo = wordl[i];
	}
	
	
	for (i = mwo; i > 0; --i)
	{
		printf("%2d:", i);
		for (j = 0; j < MWL; ++j)
		{
			if ( (wordl[j] - i) >= 0)
			{
				printf(" | ");
			} else {
				printf("   ");
			}
			
		}
		printf("\n");
	}
	
	printf("   ");
	
	for (i = 1; i <= MWL; ++i)
	{
		printf("%2d ", i);
	}
	
	printf("\n");
}