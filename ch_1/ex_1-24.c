#include <stdio.h>

#define	MAXLINE	1000
#define MISMATCH	1

int readline(char line[], int maxline);
int mismatch(char line[], char open, char close);
int occurances(char line[], char character);

/* A program to detect rudimentary syntax errors in a C program such as 
 * mismatched quotes, parens, brackets, etc. 
 *
 * Does not account for unbalanced parens, brackets, etc. in strings */
main()
{
	int len, line_num;
	char line[MAXLINE];

	while ((len = readline(line, MAXLINE)) != 0) {
		++line_num;
		if (mismatch(line, '(', ')') == MISMATCH) {
			printf("Mismatched parenthesis ");
			printf("on line %i\n", line_num);
		}
		if (mismatch(line, '[', ']') == MISMATCH) {
			printf("Mismatched square brackets ");
			printf("on line %i\n", line_num);
		}
		if (occurances(line, '"') % 2 != 0) {
			printf("Mismatched quotes ");
			printf("on line %i\n", line_num);
		}
	}
}

/* occurances: return number of occurances of c in s */
int occurances(char s[], char c)
{
	int occurances, ch, i;

	occurances = i = 0;
	while ((ch = s[i]) != '\0') {
		if (ch == c)
			++occurances;
		++i;
	}
	return occurances;
}

/* mismatch: return MISMATCH if there is an unequal number of open and 
 * close. Return 0 if there is. */
int mismatch(char s[], char open, char close)
{
	int n_open, n_close;

	n_open = occurances(s, open);
	n_close = occurances(s, close);

	if (n_open == n_close)
		return 0;
	return MISMATCH;
}

/* readline: read a line into s, return length */
int readline(char s[], int lim)
{
	int c, i;

	for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i) {
		s[i] = c;
	}
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}
