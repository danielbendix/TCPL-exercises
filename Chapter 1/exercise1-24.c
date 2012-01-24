#include <stdio.h>

#define MAXLINE 1000

int getln(char s[], int lim);
int syntaxcheck(char s[]);

int main()
{
	char line[MAXLINE];
	
	getln(line, MAXLINE);
	
	return syntaxcheck(line);
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


int syntaxcheck(char s[])
{
	int i, index, line;
	index = 0;
	line = 1;
	char quote;
	char braces[MAXLINE];
	
	for (i = 0; s[i] != '\0'; ++i) {
		if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
			braces[index] = s[i];
			++index;
			braces[index] = '\0';
		}
		else if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
			if ((braces[index - 1] + 1) == s[i] || (braces[index - 1] + 2) == s[i]) {
				--index;
				braces[index] = '\0';
			}
			else {
				printf("Error found on line %d: %c did not match %c", line, braces[index - 1], s[i]);
				return 1;
			}
		}
		else if (s[i] == '"' || s[i] == '\'') {
			quote = s[i];
			for (++i ; ; ++i)
				if (s[i] == quote && s[i - 1] !=  '\\')
					break;
		}
		else if (s[i] == '/' && s[i + 1] == '*') {
			for (++i; ; ++i) 
				if (s[i] == '*' && s[i + 1] == '/')
					break;
		}
		else if(s[i] == '\n') {
			++line;
		}
	}
}