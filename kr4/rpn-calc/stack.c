#include <stdio.h>
#include <stdlib.h> /* (for atof()) */
#include <ctype.h> /* (for isdigit()) */
#include "calc.h"

#define MAXVAL 100 /*maximum depth of val stack */

int sp = 0; /* next free (empty) stack position -- 'stack pointer' */
double val[MAXVAL]; /* value stack */

/* push: push f onto value stack */
void push(double f) {
	// Check that we're not about to overflow
	if (sp < MAXVAL)
		val[sp++] = f; /* store in the position currently pointed to by the stack pointer and then increment the pointer */
	else
		fprintf(stderr, "error: stack full; can't push %lf.\n", f);
}

/* pop: pop and return top value from stack */
double pop(void) {
	// If the stack isn't empty... (recall sp points to the next *free* space)
	if (sp > 0)
		return val[--sp]; /* Decrement stack pointer *first*, and then return the value it points to */
	else {
		fprintf(stderr, "error: stack empty.\n");
		return 0.0;
	}
}

/* clear: clear the stack */
void clear(void) {
	sp = 0;
}
