#include <limits.h>
#include <stdio.h>

//#define TEST_INT 2147483647 // (= 2^31 - 1 = MAX_INT on my machine)
#define TEST_INT -2147483648 // (= -2^31 = MIN_INT on my machine)

/* itoa: convert n to characters in s */
void itoa(int n, char s[]) {
	int i, j, sign;
	char c;

	// Check if n is the smallest (signed) number representable (in two's complement, we will only be able to represent positive integers up to and including -n - 1)
	// (this is -1 * pow(2, CHAR_BITS * sizeof (int) - 1))
	if (n == INT_MIN) {
		char d[2];
		itoa(n % 10 , d); // Compute last digit (with a minus sign)
		itoa(n / 10, s); // Compute rest

		// Concatenate these
		for (i = 0; s[i] != '\0'; i++)
			;
		s[i] = d[1];
		return;
	}

	// Take absolute value of n, whilst recording the sign for later
	if ((sign = n) < 0)
		n = -n;

	i = 0;
	do {
		// Append final (decimal) digit to s
		s[i++] = n % 10 + '0';
	} while ((n /= 10) > 0); // divide n by 10 (and drop the remainder) and check that it's still positive
	
	// If the original n was negative, append a minus sign
	if (sign < 0)
		s[i++] = '-';
	// Terminate the s
	s[i] = '\0';

	// Reverse s
	for (j = 0; s[j] != '\0'; j++)
		;
	j -= 1;
	for (i = 0; i < j; i++, j--)
		c = s[i], s[i] = s[j], s[j] = c;
}

// test
int main() {
	char s[128];
	for (int i = 0; i < 128; i++)
		s[i] = 0;

	int n = TEST_INT;
	itoa(n, s);
	printf("integer: %d\n", n);
	printf("ascii:   %s\n", s);
	return 0;
}
