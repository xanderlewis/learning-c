// Copies input to output, replacing each string of one or more blanks with a single blank.
// With each char input, we either have a nonblank, a first blank or an nth (n > 1) blank.
// In the case of a nonblank, we just pass it through.
// In the case of a blank, we check inblank and let it through if inblank is false and ignore it if inblank is true.
// We also need to set inblank to true the first time we see a blank, and set inblank to false whenever we see a nonblank.

#include <stdio.h>

int main() {
	int c;
	int inblank = 0;
	while ((c = getchar()) != EOF) {
		if (c != ' ') {
			// Let it through
			putchar(c);
			inblank = 0;
		} else if (c == ' ' && inblank) {
			// Do nothing
			;
		} else if (c == ' ' && !inblank) {
			// Let through the blank, and switch on the inblank flag.
			putchar(c);
			inblank = 1;
		}
	}
}
