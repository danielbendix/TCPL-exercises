#include <stdio.h>
#define MAXLINE 1000

int getln(char line[], int maxline);
void copy(char to[], char from[]);
void removeblanks(char s[]);

/* print longest input line */
main()
{
	int len;
	char line[MAXLINE];

	while ((len = getln(line, MAXLINE)) > 0)
		if (len > 0) {
			removeblanks(line);
			printf("%s", line);
		}
		
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

/* removeblanks:  reduce multiple tabs and spaces to one space */
void removeblanks(char s[])
{
	int i, space, ublanks;
	space = ublanks = 0;
	
	for (i = 0; s[i] != '\0'; ++i)
	{
		if (s[i] == ' ' || s[i] == '\t')
		{
			if (space)
			{
				++ublanks;
			}
			else
			{
				space = 1;
				s[i - ublanks] = ' ';
			}
		}
		else
		{
			space = 0;
			s[i - ublanks] = s[i];
		}
	}
	
	if (i == ublanks + 2)
		s[0] = '\0';
	else
		s[i - ublanks] = '\0';
}