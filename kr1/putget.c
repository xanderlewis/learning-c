#include <stdio.h>

/* copy input to output; 1st version */

//int main() {
//	int c;
//	c = getchar();
//
//	while (c != EOF) {
//		putchar(c);
//		c = getchar();
//	}
//
//	return 0;
//}

// We can rewrite this logic in a better way, making use of the fact that in C, assignments are expressions which evaluate to the value
// of the left hand side. So, in this case, c = getchar() evaluates to c.
// We can therefore get a character *and* check whether it's the end of file 'character' in one go.
// Apparently this idiom is frequently used.
// btw: EOF is a symbolic constant that is some integer that ISN'T a character we'd read in. I guess it's implementation-dependent, but
// we can use it to detect the end of the input.

int main() {
	while((c = getchar()) != EOF) {
		putchar(c);
	}
}
