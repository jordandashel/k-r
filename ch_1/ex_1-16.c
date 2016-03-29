#include <stdio.h>
#define MAXLINE 1000

int readline(char line[], int maxline);

/* print line lengths, contents */
main(){
	int len;
	char line[MAXLINE];

	while ((len = readline(line, MAXLINE)) > 0)
		printf("%3d | %s", len, line);

	return 0;
}

/* readline: read a line into s, return length 
 * renamed from 'getline', because that causes compiler errors */
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
