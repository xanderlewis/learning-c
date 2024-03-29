#include <stdio.h>

int main() {
	// try putting some char (hex) literals to stdout
	putchar('\x57');
	putchar('\x41');
	putchar('\x56');
	putchar('\x45');

	// try putting an int expressed in hex
	int a;
	a = 0xff;
	putchar(a);

	// try putting some chars expressed in hex
	char b, c, d, e;
	b = 0xde;
	c = 0xad;
	d = 0xbe;
	e = 0xef;
	putchar(b);
	putchar(c);
	putchar(d);
	putchar(e);

	putchar(sizeof b);

	int f = 3;
	putchar(f); // --> 0x03
	printf("%d", f); // --> 0x33 (3 encoded in ASCII)

	// ...so if I just want to be able to output raw bytes, I'm better off using chars for now.

	return 0;
}
