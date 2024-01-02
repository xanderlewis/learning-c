// Reverse a character string.

#include <stdio.h>
#include "reverse.h"

/*
int main() {
	// Test the reversing function.
	char string[5];
	string[0] = 'h';
	string[1] = 'e';
	string[2] = 'l';
	string[3] = 'l';
	string[4] = 'o';

	printf("%s\n", string);
	reverse(string, 5);
	printf("%s\n", string);

	return 0;
}
*/

void reverse(char s[], int l) {
	char tmp[l];
	int i;
	for (i = 0; i < l; i++) {
		tmp[i] = s[l - (i + 1)];
	}
	for (i = 0; i < l; i++) {
		s[i] = tmp[i];
	}
}
