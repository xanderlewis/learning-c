#include <stdio.h>

int main() {
	char a, b; // a single byte on my machine? (unsigned, so represents 0 to 255) (actually... it is signed? not sure..)
	a = 200; // implicit conversion from int to char makes a = -56
	b = 60; // Are chars between -128 and 127? (two's complement)
	printf("a + b = %d\n", a + b); // should output 260 % 256 = 4? YES!
	
	printf("a = %d\n", a);

	// The following are valid chars
	a = -128;
	b = 127;

	unsigned char c; // try this
	c = 255; // hopefully a single byte representing 0 to 255
	printf("c is the decimal %d\n", c); // we get 255 encoded in ASCII (3 bytes: 0x32 0x35 0x35)
	printf("c is the character %c\n", c); // we get an actual byte 0xff (which the shell doesn't render as anything particularly human-readable)
	
	// OK, so chars are [-128, 127] \cap \mathbb{Z}; unsigned chars are [0, 255] \cap \mathbb{Z}.

	return 0;
}
