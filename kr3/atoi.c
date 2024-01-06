#include <ctype.h> // (for isspace, isdigit functions)

/* atoi: convert s to integer; version 2 */
// (ignores leading whitespace and an optional + or - sign; terminates on the first character that could not be part of a number.
int atoi(char s[]) {
	int i, n, sign;

	// Ignore leading whitespace
	for (i = 0; isspace(s[i]); i++)
		;

	// Record sign
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;

	
	// Get digits and construct number
	for (n = 0; isdigit(s[i]); i++)
		n = 10 * n + (s[i] - '0');

	return sign * n;
}
