#include <stdio.h>

/* verify that the expression getchar() != EOF is 0 or 1 */
main()
{
	int c;

	printf("Enter a character\n");
	printf("(will output 0 if EOF, 1 otherwise)\n");
	c = (getchar() != EOF);
	printf("%i", c);
}
