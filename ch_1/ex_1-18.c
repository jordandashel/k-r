#include <stdio.h>
#define	MAXLINE	1000

int readline(char line[], int maxline);
int trim(char line[], char trimmed[]);
int lastchar(char s[]);

/* A program to delete trailing blanks, tabs, blank lines */
main()
{
	int i, len, last;
	char line[MAXLINE];

	while ((len = readline(line, MAXLINE)) > 0){
		last = lastchar(line);
		if(last != 0){
			if(line[len-1] == '\n')
				line[++last] = '\n';
			line[++last] = '\0';
			printf("%s", line);
		}
	}
	return 0;
}

/* lastchar: returns the index of the last non-tab/blank character */
int lastchar(char s[])
{
	int i, last;

	last = 0;
	for (i = 0; s[i] != '\n' && s[i] != EOF; i++)
		if (s[i] != ' ' && s[i] != '\t')
			last = i;
	return last;
}

/* readline: read a line into s, return length */
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
