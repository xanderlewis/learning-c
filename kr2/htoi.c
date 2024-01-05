/* htoi: converts a string of hexadecimal digits (including an optional 0x or 0X) into its equivalent integer value. */
// Returns -1 if it can't convert.

#include <stdio.h>

#define TEST_LENGTH 16

unsigned int htoi(char s[]) {
	unsigned int n = 0, m, i, i0 = 0;
	if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
			i0 = 2;
	for (i = i0; s[i] != '\0'; i++) {
		// Work out the integer represented by that char
		if (s[i] >= '0' && s[i] <= '9')
			m = s[i] - '0';
		else if (s[i] >= 'A' && s[i] <= 'F')
			m = s[i] - 'A' + 10;
		else if (s[i] >= 'a' && s[i] <= 'f')
			m = s[i] - 'a' + 10;
		else
			return -1;
		// Update integer
		n = 16 * n + m;
	}
	return n;
}

int main() {
	// Test the function
	char c;
	char s[TEST_LENGTH];
	int i;
	while (1) {
		// Get 16 chars input
		for (i = 0; i < TEST_LENGTH; i++)
			s[i] = 0;
		for (i = 0; i < TEST_LENGTH && (c = getchar()) != '\n' && c != EOF; i++)
			s[i] = c;
		// Output result
		printf("%u\n", htoi(s));

	}
	return 0;
}
