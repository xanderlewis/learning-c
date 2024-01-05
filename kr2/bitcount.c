/* bitcount: count 1 bits in x. */
int bitcount(unsigned x) {
	// (declaring x as unsigned ensures that when we right-shift it it gets padded on the left with zeros rather than sign bits.)
	int b;
	// Repeatedly take the least bit and shift to the right until x becomes zero, keeping track of the culmulative sum.
	for (b = 0; x != 0; x >>= 1)
		if (x & 01)
			b++;
	return b;
}

/* bitcount2: a faster version of bitcount, making use of the fact that x &= (x - 1) deletes the rightmost 1-bit of x. */
int bitcount2(unsigned x) {
	int b;
	// Repeatedly delete the rightmost 1-bit of x, until it becomes zero. Keep track of how many deletions happen.
	for (b = 0; x != 0; b++)
			x &= (x - 1);
	return b;
}

// If the least-significant bit *is* 1, then x & (x - 1) in fact equals x - 1 and is just x with that bit deleted.
// If the rightmost 1-bit is in the 2 position, then subtracting 1 makes this bit 0 and makes the 1 position bit 1 again.
// In general, subtracting 1 causes the rightmost 1-bit to go to zero and all the preceding bits to go to 1.
// Therefore, ANDing with this integer gives us x as it was before, but turns off that rightmost 1-bit.
// (because x and x = x, and x and 1 = x)
