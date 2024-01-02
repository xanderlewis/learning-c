// A 'barebones' version of the Unix program wc.
// It's pretty clear what lines and characters means, a 'word' is any sequence of non-blanks.
// So we need to count the number of such sequences. They're seperated, of course, by blanks.
// (mimicking wc (as far as I can see), we pad each number in the output out to a minimum width of 8 chars/bytes).

#include <stdio.h>

#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */

/* count lines, words, and characters in input */

int main() {
	int c, nl, nw, nc, state;

	state = OUT;
	nl = nw = nc = 0;
	/* The above syntax is not a special case of assignment; it is just a consequence of the fact that an assignment a = b is an expression that evaluates to a.
	[which is why we can do things like write if ((a = b) == c) { ; } to simultaneously assign b to a AND THEN check whether a equals c]
	Since assignment is right-associative, it's as if we had written nl = (nw = (nc = 0)); */

	while((c = getchar()) != EOF) {
		nc++;

		// If char is a newline, increment number of lines.
		if (c == '\n') {
			nl++;
		}

		// If char is a blank of some kind, set state to OUT.
		// In the if statement below, apparently we are guarunteed that execution will stop as soon as the truth value is known.
		// That is, if for example the first condition is true, we don't evaluate the other comparisons because we already know the whole expression is true.
		if (c == ' ' || c == '\n' || c == '\t') {
			state = OUT;
		
			// If char is *not* a blank and state is OUT, set state to IN and increment number of words.
			// (state is OUT and we've hit a non-blank ==> we're entering a new word)
		} else if (state == OUT) {
			state = IN;
			nw++;
		}
	}

	printf("%8d%8d%8d\n", nl, nw, nc);
}
