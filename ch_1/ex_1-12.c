#include <stdio.h>

/* a program that prints one (space delimited) word per line */
main()
{
	int c;

	while ((c = getchar()) != EOF) {
		if (c == ' ')
			putchar('\n');
		else
			putchar(c);
	}
}
