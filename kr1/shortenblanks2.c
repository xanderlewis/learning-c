// Another way to do this might be to keep track of the previous character and compare.
// We have four possibilities for the character pair:
// 1) nonblank followed by nonblank -- let it through
// 2) nonblank followed by blank -- let it through
// 3) blank followed by nonblank -- let it through
// 4) blank followed by blank -- ignore it!
// 
// So we just ignore the fourth possibility.

#include <stdio.h>

int main() {
	// current character and previous character
	// pc is initialised as 'a' -- an arbitrary choice of nonblank (we want to let through an initial blank).
	int c, pc = 'a';

	while ((c = getchar()) != EOF) {
		if (c == ' ' && pc == ' ') {
			// Two blanks in a row ==> ignore it.
			;
		} else {
			// Anything else ==> let it through and retain the character.
			putchar(c);
			pc = c;
		}
	}
}
