#include <stdio.h>
#define MAXLINE 1000

int getln(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest input line */
main()
{
	int len, totlen;
	int max;
	char line[MAXLINE];
	char templine[MAXLINE];
	char longest[MAXLINE];
	
	
	max = 0;
	totlen = 0;
	while ((len = getln(line, MAXLINE)) > 0)
	{
		if (len < MAXLINE - 1)
			totlen = len;
		while (len == MAXLINE - 1 && line[len-1] != '\n' )
		{
			totlen = totlen + len;
			len = getln(templine, MAXLINE); 
		}
		if (totlen > max) {
			max = totlen;
			copy(longest, line);
		}
	}
	if (max > 0)	/* there was a line */
		printf("%s \n %d", longest, max);
	return 0;
}


/* getline:  read a line into s, return length */
int getln(char s[], int lim)
{
	int c, i;
	
	for (i = 0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}


/* copy:  copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
	int i;
	
	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}