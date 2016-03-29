#include <stdio.h>

/* displays a histogram of word lengths in the input,
 * this time displayed vertically */
main(){
	int c, i, j, chars, longest, most;
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

	for (i = 1; i < 100; ++i){
		if (lengths[i] > 0)
			longest = i;
		if (lengths[i] > most)
			most = lengths[i];
	}

	printf("\n\t-- longest word: %3d --\n\n", longest);

	for (i = most + 1; i >= 1; --i){
		for (j = 1; j <= longest; j++){
			if (lengths[j] + 1 == i)
				printf(" %d ", lengths[j]);
			else if (lengths[j] >= i)
				printf(" # ");
			else
				printf("   ");
		}
		printf("\n");
	}

	for (i = 1; i <= longest; i++)
		printf("---");
	printf("\n");

	for (i = 1; i <= longest; i++)
		printf("%2d ", i);
	printf("\n");
}
