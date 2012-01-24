#include <stdio.h>

#define MAXLINE 1000
#define TABSTOP 4

int getln(char s[], int lim);
void nfp(char s[]);

int main()
{
	int i;
	char line[MAXLINE];
	
	getln(line, MAXLINE);
	
	nfp(line);
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

/* nfp:  fold long lines, for a maximum width of n columns */
void foldline(char s[], int n)
{
	int i, scolumns, wlength, line, length, uchars;
	scolumns = wlength = length = line = 0;
	
	for (i = 0; s[i] != '\0'; ++i) {
		if (s[i] == ' ') {
			if (wlength) {
				if (line + scolumns + wlength > n) {
					s[i - (uchars + scolumns + wlength)] = '\n';
				}
				
				wlength = scolumns = 0;
			}
			++scolumns;
		}
		else if (s[i] == '\t') {
			++scolumns;
		}
		else {
			++wlength;
		}
	}
}

