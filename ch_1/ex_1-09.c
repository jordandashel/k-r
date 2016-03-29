#include <stdio.h>

/* program to copy input to output, replacing multiple blanks with a 
 * single blank. */
main()
{
	int c;

	while ((c = getchar()) != EOF) {
		if (c == ' '){
			while ((c = getchar()) == ' ')
				;
			putchar(' ');
		}
		putchar(c);
	}
}
