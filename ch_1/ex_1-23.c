#include <stdio.h>

/* A program to remove the comments from a C program 
 *
 * Assumes all comments are properly constructed, un-nested, and 
 * never open without closing or close without opening.
 *
 * Intolerant of comments in string literals, or fragements of comment
 * structures in string literals. */
main()
{
	int c, d;

	while ((c = getchar()) != EOF) {
		while (c == '/') {
			if ((d = getchar()) == '*') {
				d = c;
				c = getchar();
				while (d != '*' || c != '/') {
					d = c;
					c = getchar();
				}
				d = c;
				c = getchar();
			} else {
				/* printf(" PUT "); */
				putchar(c);
				c = d;
			}
		}
		putchar(c);
	}
}
