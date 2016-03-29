#include <stdio.h>
#define MAXLINE	1000
#define LIMIT	80

int readline(char line[], int maxline);

/* A program to print all input lines longer than 80 chaacters */
main()
{
	int len;
	char line[MAXLINE];

	while((len = readline(line, MAXLINE)) > 0)
		if (len > 80)
			printf("%s", line);
	return 0;
}

/* readline: read a line into s, return length */
int readline(char s[], int lim)
{
	int c, i;
	for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
	if (c == '\n'){
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}
