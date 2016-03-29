#include <stdio.h>

int binsearch(int x, int v[], int n);

#define	TEST_SIZE	1000000

/* this is a program that implements binsearch normally and tests it. */
main()
{
	int i;

	int sample[TEST_SIZE];

	for (i = 0; i < TEST_SIZE; ++i)
		sample[i] = i;

	int result = binsearch(TEST_SIZE / 2, sample, TEST_SIZE);
	printf("result: %d\n", result);
}

/* binsearch: find x int v 
 *
 * REVISED with only one check in the loop. */
int binsearch(int x, int v[], int n)
{
	int low, high, mid, result;

	low = 0;
	high = n - 1;

	/* not sure if this counts. There are now two 
	 * tests in the while */
	while (low <= high) {
		mid = (low + high) / 2;
		if (x < v[mid])
			high = mid - 1;
		else {
			result = mid;
			low = mid + 1;
		}
	}
	return (v[result] == x) ? result : -1;
}
