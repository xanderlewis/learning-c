// The strlen function is declared in the standard header <string.h>, but here's another implementation.

#include <string.h>
#include <stdio.h>

int my_strlen(char s[]) {
	int i = 0;
	// Count the number of chars up to the first NULL
	while (s[i] != '\0')
		i++;
	return i;
}

/* NOTE: 'x' and "x" are not the same.
         'x' is an integer corresponding to the letter x in the machine's character set (probably a single byte);
	 "x" is a character array with elements: this integer, and a '\0' -- because strings are null-terminated. */

// Test the two functions
int main() {
	// Get string from stdin (max length 100)
	char s[101], c;
	for (int i = 0; i < 100 && (c = getchar()) != '\n' && c != EOF; i++)
		s[i] = c;
	s[i] = '\0'; // make sure input string is null-terminated (there may be garbage after this though)

	// Compute length
	printf("Length according to strln is %ld\n", strlen(s));
	printf("Length according to my_strln is %d\n", my_strlen(s)); // they agree!
	return 0;
}
