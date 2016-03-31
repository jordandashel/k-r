/*
Example 5-5: Rewrite a number of string utility functions using pointers
 */
#include <stdio.h>

void my_strncopy(char *to, char *from, int n);
void my_strncat(char *s, char *t, int n);
int my_strncmp(char *s, char *t, int n);

int main()
{
	char before1[] = "________";
	char after1[] = "--------";
	printf("strncopy 3\n");
	printf("\t before:\t %s\n", before1);
	printf("\t after: \t %s\n", after1);
	my_strncopy(before1, after1, 3);
	printf("\t\t*poof*\n");
	printf("\t before:\t %s\n\n", before1);

	char before2[] = "________";
	char after2[] = "--------";
	printf("strncat 3\n");
	printf("\t before:\t %s\n", before2);
	printf("\t after: \t %s\n", after2);
	my_strncat(before2, after2, 3);
	printf("\t\t*poof*\n");
	printf("\t before:\t %s\n\n", before2);

	
	char first[] = "star wars";
	char second[] = "star trek";

	printf("Do the first %i letters of '%s' match '%s'?\n", 4, first, second);
	int end = my_strncmp(first, second, 4);
	end == 0 ? printf("\tyes\n\n") : printf("\tno\n\n");

	printf("Do the first %i letters of '%s' match '%s'?\n", 6, first, second);
	end = my_strncmp(first, second, 6);
	end == 0 ? printf("\t yes\n\n") : printf("\t no\n\n");
}

void my_strncopy(char *to, char *from, int n)
{
	while (n-- > 0)
		*to++ = *from++;
}

void my_strncat(char *s, char *t, int n)
{
	while (*++s)
		;
	
	while (n-- > 0)
		*s++ = *t++;
	*s = '\0';
}

int my_strncmp(char *s, char *t, int n)
{
	while (n-- > 0)
		if (*s++ != *t++)
			return 1;
	return 0;
}
