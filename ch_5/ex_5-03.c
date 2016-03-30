/*
Excercise 5-3: using pointers, implement a version of 
               strcat(s,t) that appends t to s
*/
#include <stdio.h>

void my_strcat(char *s, char *t);

int main(){
	char s[] = "str";
	char t[] = "cat";

	printf("s: %s\n", s);
	printf("t: %s\n", t);
	my_strcat(s, t);
	printf("**shazam**\n");
	printf("s: %s\n", s);
}

/*
  my_strcat: append t onto s
 */
void my_strcat(char *s, char *t)
{
	while (*s)
		s++;

	while (*t)
		*s++ = *t++;

        *s = '\0';
}
