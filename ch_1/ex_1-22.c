#include <stdio.h>

#define	LIMIT	50
#define MAXLINE	1000

int readline(char line[], int maxline);
int last(char line[], int beg, int end);
void printseg(char line[], int beg, int end);

/* A program to fold long lines of input into two or more shorter lines
 * after the _n_th character of input 
 *
 * Can be tested with samplefiles/samplelengths */
main()
{
	int c, i, len, lastspace, start, end;
	char line[MAXLINE];

	while((len = readline(line, MAXLINE)) != 0){
		start = 0;
		end = LIMIT;
		while (end < len) {
			lastspace = last(line, start, end);
			if (lastspace > start){
				printseg(line, start, lastspace);
				putchar('\n');
				start = lastspace + 1;
				end = lastspace + LIMIT;
			} else {
				printseg(line, start, end);
				putchar('-');
				putchar('\n');
				start = end + 1;
				end += LIMIT;
			}
		}
		printseg(line, start, len);
	}
}

/* printseg: print a segment of a line, from start to end */
void printseg(char s[], int start, int end)
{
	int i;

	for (i = start; i < end; ++i)
		putchar(s[i]);
}

/* readline: read a line into s; return the length */
int readline(char s[], int lim)
{
	int c, i;

	for (i=0; i<lim-1 && (c = getchar()) != EOF && c!='\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

/* last: return index of last whitespace character between start and end
 * returns start if no whitespace in range */
int last(char s[], int start, int end)
{
	int i, last;

	last = start;
	for (i = start; s[i] != '\0' && i <= end; ++i)
		if (s[i] == ' ' || s[i] == '\n')
			last = i;

	return last;
}
