#include <string.h> // for strlen function

/* reverse: reverse string s in place */
void reverse(char s[]) {
	int c, i, j;

	/* i++, j-- is evaluated from left to right and has the value and type of the right side of the comma.
	   (the value doesn't actually matter here; it simply functions to increment both i and j)
	   (same for the first expression in the for (;;)) */

	// Look at first and last, then second and penultimate, and so on.. (until the pointers cross or become equal)
	for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
		// Swap i'th and j'th chars
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}
