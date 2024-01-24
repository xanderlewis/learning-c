/* arrays and pointers. */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	// initialise an int (statically allocated) array with three elements
	int arr[] = { 1, 2, 3 }; 
	// initialise a pointer to three ints' worth of memory
	int *p = malloc(3 * sizeof(int));

	// actually initialise the second, dynamically allocated, array
	p[0] = 1;
	p[1] = 2;
	p[2] = 3;

	// both allocate 12 bytes of memory, but I guess arr lives on the stack and
	// p lives on the stack and points to 12 bytes of memory on the heap.
	
	printf("pointer to start of arr (on stack?) %p\n", arr);
	printf("address of p (on stack?): %p\n", &p);
	printf("p (pointer to second 'array' (on heap?): %p\n", p);

	// the stack things seem to be constant across executions, whereas the pointer
	// into the heap changes each time fairly unpredictably.

	// since arr takes up 12 bytes, we'd expect that the closest p could be to arr in
	// memory would be 12 bytes away...but I'm not sure.

	return 0;
}
