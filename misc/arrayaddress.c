/* thinking about the 'address of an array', pointers, etc... */

#include <stdio.h>

int main() {
	// what's the difference between, say, a and &a if a is an array?
	char a[16]; // declare a char array of size 16 (bytes)
	
	// a is an array, which basically means it's a pointer to the first char (byte).
	// when we do a[i], we're basically (really?) doing *(a + i).
	// but what about &a? the address of the pointer a?
	printf("a:  %p\n", a);
	printf("&a: %p\n", &a);

	// --> same *value*.

	// but what about their *type*? try adding an int.
	printf("a + 1:  %p\n", a + 1);
	printf("&a + 1: %p\n", &a + 1);

	// --> in the first case, we've added 1 the sizeof(char).
	//     in the second, we've added 16 (the sizeof(a))
	
	// so they evaluated to the same thing (the same address), but
	// they behave differently when we do arithmetic.
	// so we can use a to reference the *array* somehow as a whole object, and
	// &a to reference the first element.
	
	// also, sizeof should behave differently
	printf("sizeof(a): %lu\n", sizeof(a)); // should be 16 (* sizeof(char) = 1)
	printf("sizeof(&a): %lu\n", sizeof(&a)); // should be 8 (on a 64-bit machine)

	return 0;
}
