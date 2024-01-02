// Print the input one word per line.
// ...so basically, convert each bit of whitespace into a newline character.
// Whenever we have a non-blank, we just let it through. Most of the time we ignore whitespace.
// The only thing we have to handle is when we first see whitespace after seeing a non-blank.

#include <stdio.h>

#define OUT 0
#define IN 1

int main() {
	int state, c;

	while((c = getchar()) != EOF) {
		// If character is a blank (or some kind of whitespace character) and we're in a word
		if ((c == ' ' || c == '\t' || c == '\n') && state == IN) {
			state = OUT;
			putchar('\n');
		} else {
			// If character is a non-blank, let it through.
			state = IN;
			putchar(c);
		}
	}
	putchar('\n');
	return 0;
}
