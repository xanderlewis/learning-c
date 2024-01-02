// Check a C program for unbalanced brackets, etc.
// For now, just track curly brackets ('braces').

// In the first version, I was (essentially) just counting left and right brackets and summing them at the end.
// But clearly, the order matters: {} is valid, }{ is not.
// The problem is that you can open as many brackets as you like as long as you eventually close them... {{{{{}{}}{{}}}}}
// ...but if you close more brackets than you've opened you're screwed and can't recover.
// So we count brackets as before, but if the sum ever goes negative (too many right brackets) we stop.

#include <stdio.h>

#define OUT 0
#define IN 1

int main() {
	int c, pc, curly, slc, mlc;
	curly = slc = mlc = pc = 0;

	// Get a char
	while((c = getchar()) != EOF && curly >= 0) {
		if (slc) {
			// In a singleline comment
			if (c == '\n')
				slc = OUT;

		} else if (mlc) {
			// In a multiline comment
			if (pc == '*' && c == '/')
				mlc = OUT;

		} else {
			// Not currently inside a comment of any kind
			if (pc == '/') {
				if (c == '/')
					// Entering a singline comment
					slc = IN;
				else if (c == '*')
					// Entering a multiline comment
					mlc = IN;
			}

			if (c == '{')
				curly++;
			else if (c == '}')
				curly--;
		}

		// Store last character
		pc = c;
	}

	// Finished
	if (curly == 0)
		printf("Perfect! Your brackets are balanced. :)\n");
	else if (curly > 0)
		printf("Oh no. You left %d too many brackets open and forgot to close them. :(\n", curly);
	else if (curly < 0)
		printf("Oh no. You closed too many brackets. :(\n");
	
	return 0;
}
