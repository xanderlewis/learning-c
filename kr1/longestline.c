// Print the longest line in the input.
// NOTE: I had to change the name of the getline function to get_line because there's something else with that name and gcc got confused.

#include <stdio.h>
#define MAXLINE 1000 /* maximum input line size */

// Get a line from the input stream
int get_line(char line[], int maxline);

// Store a line for later (usually because it's the longest so far)
void copy(char to[], char from[]);

int main() {
	int len, max;
	char line[MAXLINE];
	char longest[MAXLINE];

	max = 0;
	// Note: since arrays are passed by reference in C, getline can modify line.
	while ((len = get_line(line, MAXLINE)) > 0 ) {
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	}

	if (max > 0) {
		printf("The longest line was:\n%s", longest);
	}

	return 0;
}

int get_line(char s[], int lim) {
	int c, i;

	// Get input chars until either we've got lim many or we've reached EOF or a linebreak.
	// Store the chars in the char array s.
	for (i = 0; i < lim - 1 &&  (c = getchar()) != EOF && c != '\n'; i++) {
		s[i] = c;
	}

	// If the last character was a linebreak, then add it in.
	if (c == '\n') {
		s[i] = c;
		i++;
	}

	s[i] = '\0';
	return i;
}

// Takes (references to) two arrays and copies the second to the first.
void copy(char to[], char from[]) {
	int i;
	i = 0;
	// Iterate through the indices of the from array, copying them into the to array until we reach '\0'.
	// to[i] = from[i] tries to record the ith element of from into the ith element of to, and we check each time that it isn't '\0'.
	while ((to[i] = from[i]) != '\0') {
		i++;
	}
}
