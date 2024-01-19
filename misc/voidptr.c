/* using a void pointer to write a generic function for printing bytes. */

#include <stdio.h>

/* print_bytes takes a void pointer which we can then cast to whatever type of pointer we like.
 * the idea is that we are free to pass in whatever kind of pointers we like. */
void print_bytes(void *xs, int n) {
	int i;
	for (i = 0; i < n; i++) {
		// cast xs (of type void*) to a char* and then access its i'th element (deference it + i)
		// so from xs (which points to... we don't know... it's just an address) we get a pointer
		// to a byte. we're just looking at memory locations starting at xs and moving forward
		// a single byte at a time (because adding an int to a char* moves it along by one byte).
		// (offsets the address)

		if (i % 8 == 0)
			printf("\n[0x%4x] ", i); // print offset
		printf("%02x ", ((char*) xs)[i]); // ((char*) xs)[i] is basically *((char*) xs + i)
 
		// we might not have passed a char* originally, but we can certainly cast it to one in order to
		// access each byte individually.
	}
}

int main() {
	long xs[] = { 16, 31, 32, 65 };
	// print all the bytes in this array
	print_bytes(xs, 4 * sizeof(long)); // longs are 8 bytes on my machine. so xs has size 32 bytes.
					   // (I think you could just pass sizeof(xs) instead?)
	printf("sizeof(xs): %lu", sizeof(xs));
	return 0;
}

/* We can't derefence a void pointer. We have to cast it to a different type of pointer first, and then dereference it.
 * (the compiler will prevent us fom doing so) */

// NOTE: looking at the output, these things seem to be stored in little-endian.
//       for example, 16 as an int is 10 00 00 00
