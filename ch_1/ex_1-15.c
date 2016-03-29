#include <stdio.h>

double convert(int fahr);

/* print Farenheit-Celsius table
   for fahr = 0, 20, ..., 300; floating point version*/
main()
{
	float fahr, celsius;
	int lower, upper, step;
	
	lower = 0;
	upper = 300;
	step = 20;

	printf("%s\t%s\n", "farenheit", "celsius");

	fahr = lower;
	while (fahr <= upper) {
		printf("%9.0f\t%6.1f\n", fahr, convert(fahr));
		fahr = fahr + step;
	}
}

double convert(int fahr)
{
	return (5.0/9.0) * (fahr-32.0);
}
