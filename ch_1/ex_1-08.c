#include <stdio.h>

/* counts blanks, tabs, and new lines */
main(){
	int c, total, spaces, tabs, nl;

	total = 0;
	spaces = 0;
	tabs = 0;
	nl = 0;

	while((c = getchar()) != EOF){
		if (c == ' ') {
			++total;
			++spaces;
		}
		if (c == '\t') {
			++total;
			++tabs;
		}
		if (c == '\n') {
			++total;
			++nl;
		}
	}
	printf("%4d total whitespace characters\n", total);
	printf("%4d spaces\n", spaces);
	printf("%4d tabs\n", tabs);
	printf("%4d new lines\n", nl);
}
