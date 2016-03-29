#include <stdio.h>

int binsearch(int x, int v[], int n);

#define	TEST_SIZE	100000

/* this is a program that implements binsearch normally and tests it. */
main()
{
	int i;

	int sample[TEST_SIZE];

	for (i = 0; i < TEST_SIZE; ++i)
		sample[i] = i;

	int result = binsearch(TEST_SIZE / 2, sample, TEST_SIZE);
	printf("result: %d", result);
}

/* binsearch: find x int v */
int binsearch(int x, int v[], int n)
{
}
