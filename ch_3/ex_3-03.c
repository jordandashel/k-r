#include <stdio.h>
#include <string.h>

void expand(char s1[], char s2[]);

main(){
	char s1[] = "a-z";
	char s2[] = "-a-z0-9";
	char s3[] = "a-b-c";
	char ss[1000];
	printf("%s\n", s1);
	expand(s1, ss);
	printf("%s\n", ss);

	printf("%s\n", s2);
	expand(s2, ss);
	printf("%s\n", ss);

	printf("%s\n", s3);
	expand(s3, ss);
	printf("%s\n", ss);
}

/* expand: expand shorthand notation such as a-z to its representation. */
void expand(char s1[], char s2[]) {
	int i, j, k, c;
	j = i = 0;

	if (s1[i] == '-') {
		s2[j++] = '-';
		++i;
	}

	int length = strlen(s1);
	for (; i < length; ++i) {
		if (s1[i] == '-') {
			for (k = s1[i-1]; k <= s1[i+1]; ++k)
				s2[j++] = k;
		}
	}
	s2[j] = '\0';
}
