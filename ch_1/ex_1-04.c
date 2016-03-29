#include <stdio.h>

/* print Celsius-Farenheit table
   for celsius = 0, 20, ..., 300; floating point version*/
main()
{
	float fahr, celsius;
	int lower, upper, step;
	
	lower = 0;
	upper = 300;
	step = 20;

	printf("%s\t%s\n", "celsius", "farenheit");

	celsius = lower;
	while (celsius <= upper) {
		fahr = celsius * (9.0/5.0) + 32.0;
		printf("%6.0f\t%9.1f\n", celsius, fahr);
		celsius = celsius + step;
	}
}
