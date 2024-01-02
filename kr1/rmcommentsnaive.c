// Remove comments from a C program, in a fairly naive way.
// (NOTE: Doesn't handle indentation. It will remove singleline comments but leave the tabs/spaces that precede it.)

#include <stdio.h>

#define OUT 0
#define IN 1

int main() {
	// Flags for whether we are in or out of a singleline or multiline comment.
	int c1, c2, slc, mlc;
	slc = mlc = OUT;

	// Get first char
	while((c1 = getchar()) != EOF) {
		if (slc) {
			// Inside a singleline comment
			if (c1 == '\n') {
				slc = OUT;
			}

		} else if (mlc) {
			// Inside a multiline comment
			if (c1 == '*') {
				// Check next char
				if ((c2 = getchar()) == '/') {
					mlc = OUT;
				}
			}

		} else {
			// Not inside either
			if (c1 == '/') {
				// Check next char
				if ((c2 = getchar()) == '/') {
					slc = IN;
				} else if (c2 == '*') {
					mlc = IN;
				} else if (c2 != EOF) {
					putchar(c1);
					putchar(c2);
				}
			} else {
				putchar(c1);
			}

		}
	}
}
