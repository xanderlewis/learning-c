// Another way to write the character-counting program -- this time using a for loop.

#include <stdio.h>

int main() {
	double nc;
	for (nc = 0; getchar() != EOF; nc++) {
		;
	}
	// Note: the grammatical rules of C require that the for loop have a 'body', so we put a semicolon to create a 'null statement'
	// and satisfy that requirement.
	printf("There were %.0f characters.\n", nc);
	
	return 0;
}

// We could also just write the for loop on a single line, since its body is a single line of code.
