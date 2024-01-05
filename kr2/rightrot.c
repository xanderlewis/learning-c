/* rightrot: returns the value of the integer x rotated to the right by n bit positions. */

unsigned rightrot(unsigned x, int n) {
	// Throw away the rightmost n bits, and stick the original bits back on shifted by the number of bits in an int minus n.
	return (x >> n) | (x << 8 * sizeof int - n);			
}

// NOTE: if we like, we could be very careful and use the constant CHAR_BITS defined in the header <limits.h>
// ...but I'm pretty sure we'll always have 8 bits to a byte (and a char is always one byte).
