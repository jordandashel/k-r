#include <stdio.h>

void escape(char s[], char t[]);
void unescape(char s[], char t[]);

main(){
	char t[1000];
	char s[] = "tabs	please";
	escape(s, t);
	printf("%s\n",t);
	char v[1000];
	char u[] = "tab\tplease";
	unescape(u, v);
	printf("%s\n",v);
}

/* escape: print escape characters as character literals */
void escape(char s[], char t[]) {
	int i, j, c;

	i = j = 0;
	while ((c = s[i++]) != '\0') {
		switch (c) {
		case '\n':
			t[j++] = '\\';
			t[j++] = 'n';
			break;
		case '\t':
			t[j++] = '\\';
			t[j++] = 't';
			break;
		default:
			t[j++] = c;
			break;
		}
	}
}

/* unescape: print literal escape strings as escape characters */
void unescape(char s[], char t[]) {
	int i, j, c;

	i = j = 0;
	while ((c = s[i++]) != '\0') {
		if (c == '\\'){
			c = s[++i];
			if (c == '\0') {
				t[j] = '\0';
				break;
			}
			switch (c) {
			case 't':
				t[j++] = '\t';
				break;
			case 'n':
				t[j++] = '\n';
				break;
			default:
				t[j++] = '\\';
				t[j++] = c;
			}
		}
		else
			t[j++] = c;
	}
}
