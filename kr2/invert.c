/* invert: inverts the n bits of x that begin at position p (leaving the others unchanged). */

unsigned invert(unsigned x, int p, int n) {
	// Just XOR with the appropriate mask
	return x ^ (~(~0 << n) << (p - n + 1));
}
