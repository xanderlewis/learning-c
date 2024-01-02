// Counts digits, whitespace and others.

#include <stdio.h>

int main() {
	int c, i, nwhite, nother;
	// We're declaring an array to store the digit counts.
	int ndigit[10];

	// Initialise the counters and the array.
	nwhite = nother = 0;
	for (i = 0; i < 10; i++) {
		ndigit[i] = 0;
	}

	while((c = getchar()) != EOF) {
		// In ASCII (as far as I remember), '0' = 30, '9' = 39 (and 'd' = 3d for 0 < d < 9).
		// So we can check if the integer c represents a single digit in ASCII by checking if it's in this range.
		if (c >= '0' && c <= '9') {
			// Index into the array by the required offset
			ndigit[c - '0']++;
		} else if (c == ' ' || c == '\n' || c == '\t') {
			nwhite++;
		} else {
			nother++;
		}
	}

	printf("digits:");
	for (i = 0; i < 10; i++) {
		printf(" %d", ndigit[i]);
	}
	printf(", whitespace: %d, other: %d\n", nwhite, nother);
}
