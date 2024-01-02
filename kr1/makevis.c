// Make blanks and tabs visible. Also replace backslashes with double backslashes.
// (because we want to be able to distinguish between a *real* tab and the string '\t\', for example)

#include <stdio.h>

int main() {
	int c;
	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			putchar('\\');	
			putchar('b');

		} else if (c == '\t') {
			putchar('\\');
			putchar('t');
			
		} else if (c == '\\') {
			putchar('\\');
			putchar('\\');

		} else {
			putchar(c);
		}
	}
}
