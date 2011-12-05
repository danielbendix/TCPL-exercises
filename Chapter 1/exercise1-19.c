#include <stdio.h>
#define MAXLINE 1000

int getln(char line[], int maxline);
void copy(char to[], char from[]);
void reverse(char s[]);

/* print longest input line */
main()
{
	int len;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];
	
	max = 0;
	while ((len = getln(line, MAXLINE)) > 0)
		if (len > max) {
			max = len;
			reverse(line);
			copy(longest, line);
		}
	if (max > 0)	/* there was a line */
		printf("%s", longest);
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


/* reverse: reverses a line contained in the string s */
void reverse(char s[])
{
	int length, i;
	for (length = 0; s[length] != '\0' && s[length] != '\n'; ++length) ;
	
	char swap[length + 2];
	
	copy(swap, s);
	
	--length;
	for (i = 0; i <= length; ++i)
		s[i] = swap[length-i];
}
