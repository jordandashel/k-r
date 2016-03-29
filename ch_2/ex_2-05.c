#include <stdio.h>

int contains(char c, char s[]);
int any(char s1[], char s2[]);

/* A program to excercise any */
main()
{
	int c, i;
	char s1[1000], s2[1000];

	i = 0;
	printf("Enter a string\n");
	while((c = getchar()) != '\n') {
		s1[i] = c;
		++i;
	}
	i = 0;
	printf("Enter a second string\n");
	while((c = getchar()) != '\n') {
		s2[i] = c;
		++i;
	}
	int location = any(s1, s2);
	printf("first location of a character contained in s2: %i\n", location);
	printf("character: %c\n", s1[location]);
}

/* any: returns the first location of any character in s2 that occurs in s1
 * return -1 otherwise */
int any(char s1[], char s2[])
{
	int i = 0;

	while (s1[i] != '\0')
		if (contains(s1[i], s2))
				return i;
		else
			++i;
	return -1;
}

/* contains: return 1 if c is in s, 0 otherwise */
int contains(char c, char s[])
{
	int i;

	for (i = 0; s[i] != '\0'; ++i)
		if (s[i] == c)
			return 1;

	return 0;
}
