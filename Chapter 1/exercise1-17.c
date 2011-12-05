#include <stdio.h>
#define MAXLINE 1000

int getln(char line[], int maxline);
void copy(char to[], char from[]);
void delblanks(char s[]);

/* print longest input line */
main()
{
	int len;
	int max;
	char line[MAXLINE];
	
	
	max = 0;
	while ((len = getln(line, MAXLINE)) > 0)
		if (len > 81) {
			printf("%s\n", line);
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

void delblanks(char s[])
{
	int white, blanks, i;
	white = 0;
	blanks = 0;
	
	for (i = 0; s[i] != '\0'; ++i)
	{
		
	}
	
}