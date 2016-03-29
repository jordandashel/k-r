#include <stdio.h>

#define	TABSTOP	8

/* A program to replace strings of blanks with the appropriate number of
 * tabs and blanks to acheive the same spacing
 *
 * When the same space can be covered by a tab or a single blank, 
 * preference will be given to the blank, because otherwise, the file will
 * be filled with strange tab placements 
 * can be tested with samplefiles/spacedalign */
main()
{
	int c, i, col, spaces;

	col = spaces = 0;

	while((c = getchar()) != EOF) {
		if (c == '\n')
			col = 0;
		else
			++col;

		if (c == ' ') {
			++spaces;
			if (col % 8 == 0) {
				putchar('\t');
				spaces = 0;
			}
		}
		else {
			for (i = 0; i < spaces; ++i) {
				putchar(' ');
			}
			spaces = 0;
			putchar(c);
		}
	}
}
