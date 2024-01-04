// Determine the ranges of char, short, int and long variables (by printing appropriate values from standard header files).
// (implementation-defined, of course)

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
	// Sizes of integral types
	printf("chars range from %d to %d,\n", CHAR_MIN, CHAR_MAX);
	printf("shorts range from %d to %d,\n", SHRT_MIN, SHRT_MAX);
	printf("ints range from %d to %d,\n", INT_MIN, INT_MAX);
	printf("and longs range from %ld to %ld.\n", LONG_MIN, LONG_MAX);
	// Sizes of floating point variables (from float.h)
	printf("floats range from %f to %f.\n", FLT_MIN, FLT_MAX);
	// Epsilon
	printf("Epsilon is %f.\n", FLT_EPSILON);
	printf("(smallest ε such that 1.0 + ε != 1.0)\n");
	return 0;
}
