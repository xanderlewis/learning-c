/* getbits: get n bits from position p. */
// Returns the (right-adjusted) n-bit field of x that begins at position p.
// The bit positions go from right to left, but we are returning a field that is counted from left to right.

unsigned getbits(unsigned x, int p, int n) {
	return (x >> (p + 1 - n)) & ~(~0 << n);
}

// x >> (p + 1 - n) moves the desired field to the right end of the word (shift right by p to place the start in the zeroth position, then bring the rest of the n-bit field in by shifting to the left by n - 1 (when n = 1 we want to shift by zero))
// ~0 is all 1s; ~0 << n therefore has n 0s on the right.
// complementing again gives ~(~0 << n) which is all 0s with n 1s on the right
// we then use this as a mask with & to turn off all the bits apart from the n 1s on the right.
