#include <stdio.h>

void squeeze(char s1[], char s2[]);
int contains(char c, char s[]);

/* A program to excercises squeeze */
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
	squeeze(s1, s2);
	printf("%s\n", s1);
}

/* squeeze: delete all characters from s1 that can me found in s2 */
void squeeze(char s1[], char s2[])
{
	int i, j;

	j = 0;
	
	for (i = 0; s1[i] != '\0'; ++i) {
		if (!contains(s1[i], s2))
			s1[j++] = s1[i];
	}
	s1[j] = '\0';
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
