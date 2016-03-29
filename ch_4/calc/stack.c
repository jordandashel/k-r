#include <stdio.h>

#define	MAXVAL	100	/* maximum depth of val stack */

int sp = 0;		/* next free stack position */
double val[MAXVAL];	/* value stack */

/* push: push f onto value stack */
void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

/* peek: view first element */
double peek(void)
{
	if (sp > 0)
		return val[sp - 1];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

/* swap: swap the top two elements */
void swap(void)
{
	if (sp > 1) {
		double swap = val[sp - 1];
		val[sp - 1] = val[sp - 2];
		val[sp - 2] = swap;
	} else {
		printf("error: stack not large enough to swap\n");
	}
}

/* clear: clear the stack */
void clear(void)
{
	sp = 0;
}
