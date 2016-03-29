#include <stdio.h>
#include <limits.h>
#include <float.h>

void printinfo(char string[], int max_value, int min_value);
int calculate_max_capacity(int sample, int comparison);
int calculate_min_capacity(int sample, int comparison);

/* A program to display the maximum and minimum values of signed and 
 * unsigned char, short, int, and long variables, by symbolic constants
 * and by computation. */
main()
{
	/* UNSIGNED CHAR */
	printinfo("UNSIGNED CHAR", UCHAR_MAX, 0);

	unsigned char uc_min, uc_max, uc_comparison;
	uc_min = uc_max = uc_comparison = 0;
	++uc_comparison;
	while(uc_comparison > uc_max) { ++uc_comparison; ++uc_max; }

	uc_comparison = 0;
	--uc_comparison;
	while(uc_comparison < uc_min) { --uc_comparison; --uc_min; }

	printinfo("CALC UNSIGNED CHAR", uc_max, uc_min);

	/* SIGNED CHAR */
	printinfo("SIGNED CHAR", SCHAR_MAX, SCHAR_MIN);

	signed char sc_min, sc_max, sc_comparison;
	sc_min = sc_max = sc_comparison = 0;
	++sc_comparison;
	while(sc_comparison > sc_max) { ++sc_comparison; ++sc_max; }

	sc_comparison = 0;
	--sc_comparison;
	while(sc_comparison < sc_min) { --sc_comparison; --sc_min; }
	printinfo("CALC SIGNED CHAR", sc_max, sc_min);

	/* UNSIGNED SHORT */
	printinfo("UNSIGNED SHORT", USHRT_MAX, 0);

	unsigned short us_min, us_max, us_comparison;
	us_min = us_max = us_comparison = 0;
	++us_comparison;
	while(us_comparison > us_max) { ++us_comparison; ++us_max; }

	us_comparison = 0;
	--us_comparison;
	while(us_comparison < us_min) { --us_comparison; --us_min; }

	printinfo("CALC UNSIGNED SHORT", us_max, us_min);

	/* SIGNED SHORT */
	printinfo("SIGNED SHORT", SHRT_MAX, SHRT_MIN);

	signed short ss_min, ss_max, ss_comparison;
	ss_min = ss_max = ss_comparison = 0;
	++ss_comparison;
	while(ss_comparison > ss_max) { ++ss_comparison; ++ss_max; }

	ss_comparison = 0;
	--ss_comparison;
	while(ss_comparison < ss_min) { --ss_comparison; --ss_min; }

	printinfo("CALC SIGNED SHORT", ss_max, ss_min);

	/* UNSIGNED INT */
	printf("UNSIGNED INT\n");
	printf("\tmax: %u\n", UINT_MAX);
	printf("\tmin: %u\n", 0);

	unsigned int ui_min, ui_max, ui_comparison;
	ui_min = ui_max = ui_comparison = 0;
	++ui_comparison;
	while(ui_comparison > ui_max) { ++ui_comparison; ++ui_max; }

	ui_comparison = 0;
	--ui_comparison;
	while(ui_comparison < ui_min) { --ui_comparison; --ui_min; }

	printf("CALC UNSIGNED INT\n");
	printf("\tmax: %u\n", ui_max);
	printf("\tmin: %u\n", ui_min);

	/* SIGNED INT */
	printinfo("SIGNED INT", INT_MAX, INT_MIN);

	signed int si_min, si_max, si_comparison;
	si_min = si_max = si_comparison = 0;
	++si_comparison;
	while(si_comparison > si_max) { ++si_comparison; ++si_max; }

	si_comparison = 0;
	--si_comparison;
	while(si_comparison < si_min) { --si_comparison; --si_min; }

	printinfo("CALC SIGNED INT", si_max, si_min);

	/* UNSIGNED LONG */
	printf("UNSIGNED LONG\n");
	printf("\tmax: %lu\n", ULONG_MAX);
	printf("\tmin: %d\n", 0);

	unsigned long ul_min, ul_max, ul_comparison;
	ul_min = ul_max = ul_comparison = 0;
	++ul_comparison;
	while(ul_comparison > ul_max) { ++ul_comparison; ++ul_max; }

	ul_comparison = 0;
	--ul_comparison;
	while(ul_comparison < ul_min) { --ul_comparison; --ul_min; }

	printf("CALC UNSIGNED LONG\n");
	printf("\tmax: %lu\n", ul_max);
	printf("\tmin: %lu\n", ul_min);

	/* SIGNED LONG */
	printf("SIGNED LONG\n");
	printf("\tmax: %ld\n", LONG_MAX);
	printf("\tmin: %ld\n", LONG_MIN);

	signed long sl_min, sl_max, sl_comparison;
	sl_min = sl_max = sl_comparison = 0;
	++sl_comparison;
	while(sl_comparison > sl_max) { ++sl_comparison; ++sl_max; }

	sl_comparison = 0;
	--sl_comparison;
	while(sl_comparison < sl_min) { --sl_comparison; --sl_min; }

	printf("SIGNED LONG\n");
	printf("\tmax: %ld\n", sl_max);
	printf("\tmin: %ld\n", sl_min);
}

/* printinfo: print nicely formatted maximum and minimum values */
void printinfo(char name[], int max, int min)
{
	printf("%s\n", name);
	printf("\tmax: %d\n", max);
	printf("\tmin: %d\n", min);
}
