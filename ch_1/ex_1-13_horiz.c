#include <stdio.h>

/* displays a histogram of word lengths in the input */
main(){
	int c, i, j, chars, longest;
	int lengths[100];

	for (i = 0; i < 100; ++i)
		lengths[i] = 0;

	chars = longest = 0;

	while((c = getchar()) != EOF){
		if (c == ' ' || c == '\n' || c == '\t'){
			++lengths[chars];
			chars = 0;
		} else {
			++chars;
		}
	}

	printf("\n\t-- Your Word Lengths --\t\n");

	for (i = 1; i < 100; ++i)
		if (lengths[i] > 0)
			longest = i;

	printf("\t-- longest word: %3d --\n\n", longest);

	for (i = 1; i <= longest; ++i){
		printf("%3d | ", i);
		for (j = 0; j < lengths[i]; ++j)
			printf("#");
		printf("%d\n", lengths[i]);
	}
}
