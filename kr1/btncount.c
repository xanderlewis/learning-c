// Count blanks, tabs and newlines.

#include <stdio.h>

int main() {
	int nb = 0, nt = 0, nl = 0;

	int c;
	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			nb++;
		} else if (c == '\t') {
			nt++;	
		} else if (c == '\n') {
			nl++;
		}
	}

	printf("%d blanks, %d tabs, %d lines.\n", nb, nt, nl);
	return 0;
}
