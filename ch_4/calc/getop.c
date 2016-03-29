#include <stdio.h>
#include <ctype.h>

#define	NUMBER	'0'
#define	FUNC	'1'
#define	VAR	'2'

int getch(void);
void ungetch(int);
int collectop(char s[]);

/* getop: get next operator or numeric operand */
int getop(char s[])
{
	int i, c;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	i = 0;

	if (isalpha(c)) {
		int oplength = collectop(s);
		if (oplength == 1)
			return VAR;
		return FUNC;
	}


	if (!isdigit(c) && c != '.') {
		if (c == '-') {		/* negative number or subtraction? */
			int nextchar = getch();
			if (isdigit(nextchar)) {
				ungetch(nextchar); /* negative number */
			} else {
				ungetch(nextchar);
				return c; /* subtraction */
			}
		} else
			return c;	/* not a number */
	}


	if (isdigit(c))		/* collect integer part */
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.')		/* collect fraction part */
		while (isdigit(s[++i] = c = getch()))
			;

	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}

/* collectop: gather operation value and return length of op */
int collectop(char s[])
	{
		int c, i;
		i = 0;
		while (isalpha(s[++i] = c = getch()))
			;
		s[i] = '\0';
		if (c != EOF)
			ungetch(c);
		return i;
	}
