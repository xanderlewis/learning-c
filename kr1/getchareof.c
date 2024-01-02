// What happens if we continue to get chars from the stream *after* receiving EOF?

#include <stdio.h>

int main() {
	int c;

	while((c = getchar()) != EOF) {
		// Keep getting chars; do nothing.
	}

	// Now, c == EOF.
	// Get ten more chars, and output them.
	int i;
	for (i = 0; i < 10; i++) {
		c = getchar();
		putchar(c);
	}
}

// RESULT: we just get 0xff (= 255 in decimal) for every character after EOF.
// Not sure if this is implementation-dependent... probably is.
