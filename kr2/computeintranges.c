// Determine (implementation-defined) ranges of ints by computing them.

#include <stdio.h>
#include <math.h>

int main() {
	int test_min, test_max;
	test_min = -1;
	test_max = 1;
	// The max will be (one less than) some power of 2. In fact, of the form 2^(8n) - 1 since it's represented by some number of bytes.
	// Actually, it's signed so it'll be 2^(8n - 1) - 1 (or something?).
	// (Of course, this is making an assumption about the ranges we might expect to see... but I think it's a fairly safe one...)
	
	int max_tmp = test_max, max_old;
	int min_tmp = test_min, min_old;
	// NOTE: this could be made more efficient by jumping straight to the expected overflow value each time and then dropping back once we've overflowed,
	// but I think it's easier to understand this way.
	for (int n = 0; max_tmp > 0; n++) {
		// Try approaching new wraparound (overflow?) points
		max_tmp = pow(2, 8*n - 1) - 1;
		min_tmp = -1 * pow(2, 8*n - 1);
		
		/*printf("max %d\n", max_tmp);
		printf("min %d\n", min_tmp);*/
		// Store the old value
		max_old = max_tmp;
		min_old = min_tmp;
		// Try pushing by one
		max_tmp++;
		min_tmp--;
		/*printf("one more gives %d\n", max_tmp);
		printf("one fewer gives %d\n\n", min_tmp);*/
	}
	// Once we wrap around (we expect max to go to zero at some point), we exit the loop and end up here.
	printf("MAX_INT is %d\n", max_old);
	printf("MIN_INT is %d\n", min_old);
	return 0;
}
