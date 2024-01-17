/* printing a pointer using the %p format specifier. */

#include <stdio.h>

int main() {
	char s[16] = "Hello!";
	printf("address: %016p\n", &s); // came out as a 32-bit address... hmm...
				     // actually it was 4.5 bytes.
				     // first 7 hex digits are 0?
				     // change to %016p. works well enough.
				     // apparently results in undefined behaviour...
	return 0;
}
