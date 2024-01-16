/* thinking about size_t type. */

#include <string.h>
#include <stdio.h>

int main() {
	char *s = "I am a string. :)";

	// set aside 16 ints' worth of memory: that is, probably 4*16 = 64 bytes.
	int* a = malloc(sizeof(int) * 16);

	// (for most compilers, size_t is an unsigned 64 bit integer.)

	for (size_t i = 0; i < strlen(s); i++) {
		printf("%zu\n", i);
	}

	// strlen returns type size_t
	return 0;
}
