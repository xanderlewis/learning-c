// This should invert makevis. That is, it takes the output of makevis and returns the original input.
// So we need to convert: \b to a blank, \t to a tab, and \\ to a \.
// One idea is to step through two characters at a time... but then we have to deal with EOF in some clever way.
// Let's just set a flag when we see a backslash, and then use this to convert what we want to.

// Test it using pipes: cat testinput.txt | ./makevis | ./makeinvis
// NOTE: this is not a double-sided inverse. makeinvis can undo makevis, but not vice versa.

#include <stdio.h>

int main() {
	// Current char and previous char.
	int c, pc = 'a';
	
	while((c = getchar()) != EOF) {
		// If we had a slash last character...
		if (pc == '\\') {
			// Check for escape sequences.
			if (c == 'b') {
				putchar(' ');
			} else if (c == 't') {
				putchar('\t');
			} else if (c == '\\') {
				putchar('\\');
			} else {
				// If it's not an escape sequence...
				putchar(c);
			}
			
		// If we don't have a slash in either position...
		} else if (c != '\\') {
			// Let it through.
			putchar(c);
		}

		pc = c;
	}
}

// I'm not sure if having nested if statements like that is frowned upon, but it seems to lead to fairly simple logic here.
