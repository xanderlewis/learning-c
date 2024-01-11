/* A simple calculator that uses reverse Polish notation. Provides the operators +, -, *, / and % (modulus). */

/* Basically: we just loop, looking for operands, operators or the end-of-file indicator.
 * If we find a number, we push it to the stack; if an operator we pop the appropriate number of operands
 * and push back the result of the operation. If we encounter a newline character, we pop and print the top of the stack.*/

#include <stdio.h>
#include <stdlib.h> /* (for atof()) */
#include <ctype.h> /* (for isdigit()) */
#include "calc.h"

#define MAXOP 100 /* max size of operand or operator (that is, the max length of an input number) */
#define NUMBER '0' /* signal that a number was found */

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
