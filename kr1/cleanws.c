// Remove trailing blanks and tabs from each line of input and delete entirely blank lines.
// (NOTE: can only successfully remove at most LIMIT many blanks or tabs from the end of each line.)
// (however, can deal with lines longer than LIMIT)

/* Try to get LIMIT many chars. Keep track of the index of the last nonblank. When we hit a newline, print up to this index.
   If we didn't hit a newline this iteration (because LIMIT was not large enough), print everything (including blanks). */

// Test it by doing something like ./a.out < trailingwstest.txt | cat -e

// Currently doesn't actually deal with newlines properly. TODO: make it work.
// OK, start a new file and write it properly. Implement a function that not only gets the chars, but 'returns' the exact string to be printed.

#include <stdio.h>
#define LIMIT 1000

int get_chars(char string[], int limit);

int main() {
	char string[LIMIT];
	int i, j;

	// Get LIMIT many chars
	while((i = get_chars(string, LIMIT)) != -1) {
		for (j = 0; j <= i; j++) {
			putchar(string[j]);
		}
		if (i < 0) {
			putchar('\n');
		}
	}
	
	return 0;
}

// Get limit many chars; return the index of the last nonblank if we hit a newline, else return the whole limit.
int get_chars(char s[], int limit) {
	int i, j = 0, c;
	// Keep reading and storing chars (keeping track of index of last nonblank) until we hit a newline (keeping it) or EOF.
	for (i = 0; i < limit && (c = getchar()) != EOF; i++) {
		s[i] = c;
		if (c != ' ' && c != '\t' && c != '\n') {
			j = i;
		}
		if (c == '\n') {
			break;
		}
	}

	if (c == EOF && i == 0) {
		return -1;
	} else if (c == EOF) {
		return j;
	} else if (c == '\n') {
		return -1 * j;
	} else {
		return limit;
	}

}
