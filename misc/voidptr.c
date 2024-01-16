/* using a void pointer to write a generic function for printing bytes. */

#include <stdio.h>

void print_bytes(void *xs, int n) {
	int i;
	for (i = 0; i < n; i++) {
		// cast xs (of type void*) to a char* and then access its i'th element (deference it + i)
		// so from xs (which points to... we don't know... it's just an address) we get a pointer
		// to a byte. we're just looking at memory locations starting at xs and moving forward
		// a single byte at a time (because adding an int to a char* moves it along by one byte).
		printf("(%d) %02x ", i, ((char*) xs)[i]); // ((char*) xs)[i] is basically *((char*) xs + i)
		if (i % 8 == 7)
			putchar('\n');
	}
}

int main() {
	long xs[] = { 16, 31, 32, 65 };
	print_bytes(xs, 4 * sizeof(long)); // longs are 8 bytes on my machine. so xs has size 32 bytes.
					   // (I think you could just pass sizeof(xs) instead?)
	return 0;
}

/* We can't derefence a void pointer. We have to cast it to a different type of pointer first, and then dereference it.
 * (the compiler will prevent us fom doing so) */
