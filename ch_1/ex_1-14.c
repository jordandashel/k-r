#include <stdio.h>

/* A program to display a histogram of the frequency of different 
 * characters in the input. 
 *
 * I have chosen to ignore non-alpha characters */
main(){
	int c, i;

	int frequencies[26];

	for (i = 0; i < 26; ++i)
		frequencies[i] = 0;

	while ((c = getchar()) != EOF) {
		if (c >= 'A' && c <= 'Z')
			frequencies[c - 'A']++;
		else if (c >= 'a' && c <= 'z')
			frequencies[c - 'a']++;	
	}

	for (c = 'a'; c <= 'z'; ++c){
		printf("%c | ", c);
		for (i = 0; i < frequencies[c - 'a']; ++i)
			printf("#");
		printf("(%d)\n", i);
	}
}
