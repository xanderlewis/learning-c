// Messing around with pointers and addresses...

#include <stdio.h>
#include <inttypes.h>

int main() {
	int a, b;
	int *pa; // a pointer to an int
	pa = &a; // make pa point to a
	
	printf("%x\n", pa);

	char c[10]; // let's have an array of size 10
	for (int i = 0; i < 10; i++)
		printf("position %d: %16p\n", i, &c[i]);
	// ..they are indeed consecutive bytes.
	
	// how about an int array? should be consecutive blocks of four bytes.
	putchar('\n');
	int d[5];
	for (int i = 0; i < 5; i++)
		//printf("position %d: %p\n", i, &d[i]);
		printf("position %d: 0x%016" PRIX64 "\n", i, &d[i]);
	// yes.
	
	// I'm getting warnings about using the format specifier %x... but it works.
	// ..well, actually it only shows a 32-bit address...
	// apparently you can use %p.
	// even using llx gives an address that isn't long enough.
	// oh; it's just because its mostly zero at the beginning.
	
	// trying the macro PRIx64 from <inttypes.h> above.
	// can also use PRIX64.
	
	return 0;
}
