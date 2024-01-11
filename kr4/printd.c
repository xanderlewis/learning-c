#include <stdio.h>

/* printd: print n in decimal */
/* (using recursion!) */
void printd(int n) {
	if (n < 0) {
		putchar('-');
		n = -n; // (note: of course, this will fail if n is INT_MIN)
	}
	// If n isn't a single (base ten) digit...
	if (n / 10)
		// Try to print the first [# digits] - 1 digits
		printd(n / 10);

	// Output last digit (as ASCII)
	putchar(n % 10 + '0');
}
