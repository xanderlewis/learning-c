// We count the number of characters in the input (up to the EOF, which we just saw is equal to -1 on my system).
// I guess (by default?) getchar reads from the stream stdin. printf writes to stdout.

#include <stdio.h>

int main() {
	// Number of characters.
	long nc = 0;

	// Keep reading chars from the stream until we hit an EOF, incrementing nc each time.
	while (getchar() != EOF) {
		nc++;
	}
	
	// Output the result.
	if (nc == 1) {
		printf("There was %ld character.\n", nc);
	} else {
		printf("There were %ld characters.\n", nc);
	}

	return 0;
}

// hint: try echo -n 'hello' | ./a.out
// (or whatever the output from the compiler was called)
