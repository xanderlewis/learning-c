/* raise some given base to the given (nonnegative) power */

#include <stdio.h>

// Declare the power function
int power(int m, int n);

// Test the power function
int main() {
	int i;
	for (i = 0; i < 10; i++) {
		printf("%d %d %d\n", i, power(2, i), power(-3, i));
	}

	return 0;
}

// Define the power function
int power(int base, int n) {
	int i, p;
	p = 1;

	for (i = 1; i <= n; i++) {
		p = p * base;
	}

	return p;
}

// Since C is call-by-value, we could have written it like this:
// We don't need i anymore -- we just use n to count through the multiplications, which is quite natural.
// Changes to n have no effect on the value of the original variable (in this case, i in main).
// Note: in C, arrays are call-by-reference since they are naturally implemented via pointers.

int power2(int base, int n) {
	int p;

	for (p = 1; n > 0; n--) {
		p = p * base
	}
	
	return p;
}
