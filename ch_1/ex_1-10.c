#include <stdio.h>

/* this program copies input to output, replacing backspaces, backslashes,
 * and tabs with \b, \\, and \t, respectively */

#define	SPECIAL_CHAR	0
#define NORMAL_CHAR	1

main()
{
	int c, sc;

	while((c = getchar()) != EOF){
		sc = NORMAL_CHAR;
		if (c == '\b'){
			printf("\\b");
			sc = SPECIAL_CHAR;
		}
		if (c == '\\'){
			printf("\\\\");
			sc = SPECIAL_CHAR;
		}
		if (c == '\t'){
			printf("\\t");
			sc = SPECIAL_CHAR;
		}
		if (sc == NORMAL_CHAR)
			putchar(c);
	}
}
