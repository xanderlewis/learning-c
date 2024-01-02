// Print all input lines that are longer than 80 characters.
/* Repeatedly get chars and store them in an array of length 81 until either a linebreak or the array is full.
   If we have 81 chars, print them and continue to getchar putchar until a linebreak.
   Repeat. */

#include <stdio.h>
#define MIN_LENGTH 81

int get_string(char line[], int length);

int main() {
	int c, length;
	char string[MIN_LENGTH];
	
	// Keep getting strings of MIN_LENGTH many chars until there are no more.
	while((length = get_string(string, MIN_LENGTH)) != -1) {
		// printf("got %d chars.\n", length);
		// If sufficiently long, print the first MIN_LENGTH chars and then the rest
		if (length >= MIN_LENGTH) {
			printf("%s", string);
			while((c = getchar()) != '\n' && c != EOF) {
				putchar(c);
			}
			printf("\n");
		}
	}
}

// Get l many chars and return the length (exclusive) up to a linebreak.
int get_string(char s[], int l) {
	int c, i = 0;

	// Read in chars up to either an EOF of a linebreak.
	while(i < l && (c = getchar()) != EOF && c != '\n') {
		s[i] = c;
		i++;
	}
	// (the above might be more natural as a for loop)
	
	// Return number of chars we got, or -1 if the first char was already EOF.
	if (i == 0 && c == EOF) {
		return -1;
	} else {
		return i;
	}
}
