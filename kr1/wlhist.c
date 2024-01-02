// Print a histogram of the lengths of words in the input.
// NOTE: only works on inputs with maximum word length MAX_LENGTH (since I don't know to do variable-length arrays in C yet).
// If you feed it text with a word of length greater than this, it'll try to index further into the array than has been declared/initialised...

#include <stdio.h>

#define OUT 0
#define IN 1
#define MAX_LENGTH 20

int main() {
	int i, j, c, state = OUT;
	int l = 0;
	int counts[MAX_LENGTH]; //  Keep track of counts of words of length 1 ... MAX_LENGTH.
	
	// Initialise counts array
	for (i = 0; i < MAX_LENGTH; i++) {
		counts[i] = 0;
	}

	while ((c = getchar()) != EOF) {
		// Hit whitespace
		if (c == ' ' || c == '\t' || c == '\n') {
			if (state == IN) {
				counts[l - 1]++;
				l = 0;
				state = OUT;
			}
			// Not whitespace
		} else {
			state = IN;
			l++;
		}
	}

	// Print the histogram
	for (i = 0; i < MAX_LENGTH; i++) {
		printf("length %d: ", i + 1);
		for (j = 0; j < counts[i]; j++) {
			printf("*");
		}
		printf("\n");
	}
}
