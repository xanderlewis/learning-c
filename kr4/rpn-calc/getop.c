#include <stdio.h>
#include <stdlib.h> /* (for atof()) */
#include <ctype.h> /* (for isdigit()) */
#include "calc.h"

#define NUMBER '0' /* signal that a number was found */

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
