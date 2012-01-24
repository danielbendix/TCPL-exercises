#include <stdio.h>

#define MAXLINE 1000
#define IN 1
#define OUT 0

int getln(char s[], int lim);
void decomment(char s[]);

int main()
{
	char line[MAXLINE];
	
	getln(line, MAXLINE);
	
	decomment(line);
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

/* decomment: remove comments from a c program */
void decomment(char s[])
{
	int i, qstate, state, comlength, uchars;
	qstate = state = comlength = uchars = 0;
	for (i = 0; s[i] != '\0'; ++i) {
		if (!qstate) {
			if (!state) {
				if (s[i] == '/' && s[i + 1] == '*') {
					++i;
					uchars += 2;
					state = IN;
				} 
				else {
					if ((s[i] == '"' || s[i] == '\'') && s[i - 1] != '\\')
						qstate = IN;
					s[i - uchars] = s[i];
				}
			}
			else {
				if (s[i] == '*' && s[i + 1] == '/') {
					i++;
					uchars += 2;
					state = OUT;
				}
				else {
					++uchars;
				}
			}
		}
		else {
			s[i - uchars] = s[i];
			if ((s[i] == '"' || s[i] == '\'') && s[i - 1] != '\\')
				qstate = OUT;
		}
	}
	s[i - uchars] = '\0';
}
/* could be done better by looping through quotes and characters inside the main loop. */
