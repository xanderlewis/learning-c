// Count the number of lines in the given input.

#include <stdio.h>

int main() {
	int c, nl;

	nl = 0;
	while ((c = getchar()) != EOF) {
		if (c == '\n') {
			nl++;
		}
	}
	if (nl == 1) {
		printf("There was %d line.\n", nl);
	} else {
		printf("There were %d lines.\n", nl);
	}
}

// Really, we're counting the number of occurrences of the newline character: \n.
// In hex (ASCII) I seem to recall it's 0x0a...?

// Also note: when we write something like 'a' (single quotes), this represents an integer value corresponding to that character in whatever encoding scheme we're using.
