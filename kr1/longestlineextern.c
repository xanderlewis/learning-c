// The extern declarations in the below are redundant because we declare them before they are used anywhere else in the source code anyway.

#include <stdio.h>
#define MAXLINE 1000

// Declare these variables globally
int max;
char line[MAXLINE];
char longest[MAXLINE];

// Function declarations. Note that they no longer take parameters.
int get_line(void);
void copy(void);

int main() {
	int len;
	extern int max;
	extern char longest[];

	max = 0;
	while ((len = get_line()) > 0) {
		if (len > max) {
			max = len;
			copy();
		}
	}
	if (max > 0) {
		printf("%s", longest);
	}
	return 0;
}


int get_line(void) {
	int c, i;
	extern char line[];

	for (i = 0; i < MAXLINE - 1
			&& (c = getchar()) != EOF && c != '\n'; i++) {
		line[i] = c;
	}
	if (c == '\n') {
		line[i] = c;
		i++;
	}
	line[i] = '\0';
	return i;
}

// Copy contents of 'line' to 'longest'.
// i.e. keep a copy of the longest line thus far.
void copy(void) {
	int i;
	extern char line[], longest[];

	i = 0;
	while ((longest[i] = line[i]) != '\0') {
		i++;
	}
}
