#include <stdio.h>

#define MAXLINE 1000
#define TABSTOP 4

void detab(char s[]);

int main()
{
	int i;
	char line[MAXLINE];
	for (i = 0; i < 10; ++i) {
		line[i] = 'a';
	}
	for ( ; i < 15; ++i) {
		line[i] = '\t';
	}
	for ( ; i < 30; ++i) {
		line[i] = 'b';
	}
	detab(line);
	printf("%s", line);
	
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

/* detab:  substitute tabs with spaces. assume that s[] has sufficient space */
void detab(char s[])
{
	int i, j, tabs;
	
	for (i = 0; s[i] != '\0'; ++i) {
		if (s[i] == '\t')
			++tabs;
	}
	
	for ( ; i >= 0; --i) {
		if (s[i] == '\t') {
			--tabs;
			for (j = 0; j < (TABSTOP); ++j) {
				s[i + j + tabs * (TABSTOP-1)] = ' ';
			}
		}
		else {
			s[i + tabs * (TABSTOP-1)] = s[i];
		}
			
	}
}
