#include <stdio.h>
#define	MAXLINE	1000

int length(char s[]);
void reverse(char s[]);
int readline(char line[], int maxline);

/* A program to reverse the lines of its input */
main()
{
	int len;
	char line[MAXLINE];

	while((len = readline(line, MAXLINE)) > 0){
		reverse(line);
		printf("%s", line);
	}
}

/* reverse: reverses the character string s */
void reverse(char s[])
{
	int i, len, swap;

	len = length(s) - 1; /* don't swap the new line */

	for (i = 0; i < len / 2; ++i){
		swap = s[len - i];
		s[len - i] = s[i];
		s[i] = swap;
	}
}

int length(char s[])
{
	int i;
	
	for (i = 0; s[i] != '\n' && s[i] != EOF; ++i)
		;
	return i;
}

/* readline: read a line into s, return the length */
int readline(char s[], int lim)
{
	int c, i;

	for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}
