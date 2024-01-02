// Reverse each line of the input.
// (test it with something like: cat testlines.txt & cat testlines.txt | ./reveachline | ./reveachline)

#include <stdio.h>
#include "reverse.h"

int get_line(char line[], int maxlen);
void clear_line(char line[], int length);

#define MAX_LINE_LENGTH 100

int main() {
	char line[MAX_LINE_LENGTH];
	clear_line(line, MAX_LINE_LENGTH);
	int length;
	
	while ((length = get_line(line, MAX_LINE_LENGTH)) != 0) {
		reverse(line, length);
		printf("%s", line);
		clear_line(line, MAX_LINE_LENGTH);
	}

	return 0;
}

void clear_line(char line[], int length) {
	int i;
	for (i = 0; i < length; i++) {
		line[i] = 0;
	}
}

// Get a line from the input stream; returns length of line (zero if EOF).
int get_line(char line[], int maxlen) {
	int i, c;
	for (i = 0; i < maxlen && (c = getchar()) != EOF; i++) {
		line[i] = c;
		if (c == '\n') {
			break;
		}
	}

	return i;
}
