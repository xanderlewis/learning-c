/* dereferencing a null pointer. */

#include <stdlib.h> // NULL?

int main(void) {
	// get a null pointer
	int *ptr = NULL;

	// try to dereference it
	*ptr;
	/* but we don't actually *use* this value; we just reference it.
	 * possibly at compile time it will be optimised away and not
	 * cause any issue. 
	 * indeed: the compiler warns us that the value of ptr* is not
	 * used. however, it's just warning; the program compiles and
	 * it runs with no issue. */

	return 0;
}

