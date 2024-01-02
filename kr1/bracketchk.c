// Check a C program for unbalanced brackets, etc.
// For now, just track curly brackets ('braces').

#include <stdio.h>

#define OUT 0
#define IN 1

int main() {
	int c, pc, curly, slc, mlc;
	curly = slc = mlc = pc = 0;

	while((c = getchar()) != EOF) {
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

	if (curly == 0)
		printf("Yay! Your brackets are balanced. :)\n");
	else {
		printf("Oh dear, you've got ");
		if (curly > 0)
			printf("%d too many left brackets. :(\n", curly);
		else
			printf("%d too many right brackets. :(\n", -1 * curly);
	}
}
