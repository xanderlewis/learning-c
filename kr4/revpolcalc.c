/* A simple calculator that uses reverse Polish notation. Provides the operators +, -, *, / and % (modulus). */

/* Basically: we just loop, looking for operands, operators or the end-of-file indicator.
 * If we find a number, we push it to the stack; if an operator we pop the appropriate number of operands
 * and push back the result of the operation. If we encounter a newline character, we pop and print the top of the stack.*/

#include <stdio.h>
#include <stdlib.h> /* (for atof()) */
#include <ctype.h> /* (for isdigit()) */

#define MAXOP 100 /* max size of operand or operator (that is, the max length of an input number) */
#define NUMBER '0' /* signal that a number was found */
#define MAXVAL 100 /*maximum depth of val stack */

// Function declarations for main
int getop(char []);
void push(double);
double pop(void);
void clear(void);

/* "main doesn't need to know about the stack; it only does push and pop operations" */
int main() {
	int type;
	double op2, op1;
	char s[MAXOP];

	while ((type = getop(s)) != EOF) {
		switch (type) {
			case NUMBER:
				// interpret string as float and push it to the stack
				push(atof(s));
				break;
			case '+':
				// pop two operands from the stack and push their sum back
				push(pop() + pop());
				break;
			case '*':
				// pop two operands from the stack and push their product back
				push(pop() * pop());
				break;
			case '-':
				// pop two operands from the stack and push their difference back
				op2 = pop(); /* note: the order of evaluation of the two things being popped matters for this case */
				push(pop() - op2);
				break;
			case '/':
				// pop two operands from the stack and push their quotient back
				op2 = pop(); /* order also matters here -- not commutative */
				// ensure we're not trying to divide by zero
				if (op2 != 0.0)
					push(pop() / op2);
				else
					fprintf(stderr, "error: zero divisior.\n");
				break;
			case '%':
				// pop two operands and push their modulus back
				op2 = pop();
				push((int) pop() % (int) op2);
				break;
			case 'p':
				// Print the top of the stack without popping
				printf("\t%lf", op1 = pop());
				push(op1);
				break;
			case 's':
				// Swap the top two elements of the stack
				op1 = pop(); op2 = pop();
				push(op1); push(op2);
				break;
			case 'c':
				// Clear the stack
				clear();
				break;
			case 'q':
				// Quit program
				return 0;
				break; // (obviously not really needed)
			case '\n':
				// pop the top of the stack and write it to stdout.
				printf("\t%.8lf\n", pop());
				break;
			default:
				printf("error: unknown command %s.\n", s);
				break;

		}
	}
	return 0;
}

// Stack-related variables
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

// Function declarations (visible to getop)
int getch(void);
void ungetch(int);

/* getop: get next operator or numeric operand */
int getop(char s[]) {
	int i, c;
	
	// Skip leading whitespace (eventually storing the first nonblank char at s[0])
	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;

	// Null-terminate the string after the first character
	s[1] = '\0';

	// If this first char is anything other than a digit or a decimal point...
	if (!isdigit(c) && c != '.')
		// Return the (probably..) operator
		return c; /* not a number */
	i = 0;
	if (isdigit(c)) /* collect integer part */
		// Repeatedly get and store the next char until no longer a digit
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.') /* collect fractional part */
		// Same again... (but now after the decimal point)
		while (isdigit(s[++i] = c = getch()))
			;

	// Null-terminate the whole string
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	// Signal that we're 'returning' a number (operand) rather than an operator
	return NUMBER;
}

/* getch delivers the next input character to be considered; ungetch remembers the characters put back on the input, so that subsequent calls to getch will return them before reading new input. */

#define BUFSIZE 100

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

int getch(void) { /* get a (possibly pushed back) character */
	return (bufp > 0) ? buf[--bufp] : getchar();
} 

void ungetch(int c) { /* push character back on input */
	if (bufp >= BUFSIZE)
		fprintf(stderr, "ungetch: too many characters.\n");
	else
		buf[bufp++] = c; /* store char in buffer (at index bufp) and then increment buffer pointer */
}
