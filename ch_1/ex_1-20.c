#include <stdio.h>

#define	TABSTOP	8

/* a program to replace tabs with spaces, up to the nearest tabstop */
main()
{
	int c, col;

	while ((c = getchar()) != EOF){
		if (c == '\t')
			while (col % 8 != 0){
				putchar(' ');
				++col;
			}
		else {
			putchar(c);
			++col;
		}
	}
}
