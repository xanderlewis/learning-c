// The unary negation operator
// 0 is false; anything nonzero is true (freedom to be *anything* nonzero is quite nice because it lets us implement && as multiplication and || as addition)
// swaps true and false, therefore maps 0 to something nonzero (let's choose 1) and maps anything nonzero to 0.

#include <stdio.h>

int neg(int p) {
	if (p == 0)
		return 1;
	else
		return 0;
}

int main() {
	// test it
	int result;
	result = neg(1 == 0); // this should be true i.e. nonzero
	printf("%d\n", result);

	result = neg(3 == 3); // this should be false i.e. 0
	printf("%d\n", result);

	result = neg(neg(1 == 1)); // this should be true i.e. nonzero
				   // !!(true)
	printf("%d\n", result);
	return 0;
}

// OUTPUT:
// 1
// 0
// 1
