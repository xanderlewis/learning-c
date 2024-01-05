/* setbits: set the n bits beginning at position p of x according to the rightmost n bits of y (leaving the others unchanged). */

unsigned setbits(unsigned x, int p, int n, int y) {
	int y_mask = ~(~0 << n); // 000...00111 (n ones)
	int x_mask = ~(y_mask << (p - n + 1)); // 11...000...1111 (n zeros)
	int y_masked = y & y_masked; // keep just the far right n bits of y
	int x_masked = x & x_masked; // scoop out the n bits of x to be replaced

	return x_masked | y_masked << (p - n + 1);
}
