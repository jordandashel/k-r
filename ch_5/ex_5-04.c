/*
Excercise 5-4: using pointers, write a function my_strend(s, t) to check if
               s ends with t
 */
#include <stdio.h>

int strend(char *, char *);

int main() {
	printf("Does 'the end' end with 'end'?\n");
	int end = strend("the end", "end");
	end ? printf("yes\n") : printf("no\n");

	printf("Does 'the ending' end with 'end'?\n");
	end = strend("the ending", "end");
	end ? printf("yes\n") : printf("no\n");

	printf("Does 'the end' end with 'an end'?\n");
	end = strend("the end", "an end");
	end ? printf("yes\n") : printf("no\n");
}

/* strend: return 1 if s ends with t */
int strend(char *s, char *t)
{ 
	int t_len = 0;
	while (*++s)
		;

	while (*++t)
		++t_len;

	while (t_len-- >= 0)
		if (*t-- != *s--)
			return 0;

	return 1;
}
