#include <stdio.h>
#include <stdlib.h>	/* for atof() */
#include <math.h>
#include <string.h>

#define	MAXOP	100	/* max size of operand or operator */
#define	NUMBER	'0'	/* signal that a number was found */
#define	FUNC	'1'	/* signal that a function was found */
#define	VAR	'2'	/* signal that a variable was found */

int getop(char []);
void push(double);
double pop(void);

/* reverse Polish calculator */
main() {
	int type, num, alpha;
	double op2;
	char s[MAXOP];
	double var['z' - 'a' + 1];
	int set['z' - 'a' + 1];
	for (int i = 0; i < ('z' - 'a'); ++i) 
		set[i] = 0;

	while ((type = getop(s)) != EOF) {
		switch (type) {
		case NUMBER:
			push(atof(s));
			break;
		case VAR:
			if (set[(int) s[0] - 'a']) {
				push(var[(int) s[0] - 'a']);
			} else {
				push((int) s[0]);
			}
			break;
		case FUNC:
			if (!strcmp(s, "SIN")) {
				push(sin(pop()));
			} else if (!strcmp(s, "COS")) {
				push(cos(pop()));
			} else if (!strcmp(s, "EXP")) {
				push(exp(pop()));
			} else if (!strcmp(s, "POW")) {
				op2 = pop();
				push(pow(pop(), op2));
			}
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':
			op2 = pop();
			if (op2 != 0.0)
				push(pop() / op2);
			else
				printf("error: zero divisor\n");
			break;
		case '%':
			op2 = pop();
			push((int)pop() % (int)op2);
			break;
		case '=':
			num = pop();
			alpha = pop();
			var[alpha - 'a'] = num;
			set[alpha - 'a'] = 1;
			push(num);
			break;
		case '\n':
			printf("\t%.8g\n", pop());
			break;
		default:
			printf("error: unknown command %s\n", s);
			break;
		}
	}
	return 0;
}
