#include <stdio.h>

#define MAXLINE 1000
#define TABSTOP 4

int getln(char s[], int lim);
void entab(char s[]);

int main()
{
	int i;
	char line[MAXLINE];
	for (i = 0; i < 10; ++i) {
		line[i] = 'a';
	}
	for ( ; i < 20; ++i) {
		line[i] = ' ';
	}
	for ( ; i < 30; ++i) {
		line[i] = 'b';
	}
	line[i] = '\0';
	line[i + 100] = '\0';
	entab(line);
	printf("%s", line);
	
	return 0;
}

/* getln:  read a line into s, return length */
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

/* entab:  substitute several consecutive spaces with tabs */
void entab(char s[])
{
	int i, j, spaces, tabs, ublanks;
	spaces = tabs = ublanks = 0;
	
	for (i = 0; s[i] != '\0'; ++i) {
		if (s[i] == ' ') {
			s[i - ublanks] = s[i];
			++spaces;
		}
		else {
			if (spaces > 3) {
					tabs = spaces / TABSTOP;
				for (j = tabs - 1 ; j >= 0; --j) {
					s[i + j - tabs * TABSTOP ] = '\t';
				}
				ublanks += tabs * (TABSTOP - 1);
			}
			spaces = 0;
			s[i - ublanks] = s[i];
		}
	}
	s[i - ublanks] = s[i];
}