#include <stdio.h>

int convert(char c);
int valid(char c);
int htoi(char input[]);

/* A program to excercise the function htoi */
main()
{
	char c, input[1000];
	int i = 0;

	printf("Type in a hex value to convert to decimal.\n");
	while((c = getchar()) != '\n') {
		input[i] = c;
		++i;
	}
	int result = htoi(input);
	printf("result: %x\n", result);
}

/* htoi: convert s to an integer */
int htoi(char s[])
{
	int i;

	int n;
	if (s[0] != '\0' && s[1] != '\0' && s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
		i = 2;
	else
		i = 0;

	for ( ; valid(s[i]); ++i) 
		n = 0x10 * n + (convert(s[i]));
	return n;
}

/* valid: c is a valid character for a hexadecimal integer */
int valid(char c)
{
	return (c>='0' && c<='9')||(c>='A' && c<='F')||(c>='a' && c<='f');
}

/* convert: convert c to its hexadecimal integer value 
 * return -1 if invalid character */
int convert(char c)
{
	if (c >= '0' && c <= '9')
		return c - '0';
	else if (c >= 'a' && c <= 'f')
		return c - 'a' + 0xA;
	else if (c >= 'A' && c <= 'F')
		return c - 'A' + 0xA;
	return -1;
}
