// Print the input one word per line.
// ...so basically, convert each bit of whitespace into a newline character.

#include <stdio.h>

#define OUT 0
#define IN 1

int main() {
	int state, c;

	while((c = getchar()) != EOF) {
		// If character is a blank (or some kind of whitespace character)
		if (c == ' ' || c == '\t' || c == '\n') {
			// If we're already in a word...
			if (state == IN) {
				state = OUT;
				putchar('\n');
			} else {
				// If we're already outside of a word, do nothing.
				;
			}
		} else {
			// If character is a non-blank, let it through.
			state = IN;
			putchar(c);
		}
	}
}
