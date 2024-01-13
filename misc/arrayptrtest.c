/* experimenting with arrays and pointers... I don't know how it really works yet... */

#include <stdio.h>

#define OUT(A) printf(#A ": 0x%016lx (%d)\n", A, A)

int main() {
	/* -- USING THE [] SYNTAX -- */
	char s[20]; // make a character array of length 20
	s[0] = 3; // initialise some stuff
	s[1] = 4;
	OUT(s);
	OUT(s[0]);
	OUT(s[1]);
	OUT(*s);
	OUT(*(s + 1));
	OUT(sizeof(s)); // sizeof(s) is apparently 20. well, that's not the actual size of s (which I thought was a pointer?)
			// ...but it's giving us the number of elements of s the array. useful.
	OUT(sizeof(s[0])); // s[0] has size 1 byte (again, makes sense; a char is a single byte)
	OUT(&s); // the address of s (so the address of the pointer to the first element...?) nope. it gives exactly the same as s.
	OUT(sizeof(&s)); // AH! so if we want the actual size of the pointer that points to the start of the array s,
			 // we can just look at &s. so s and &s aren't entirely the same thing.
	
	/* -- JUST USING POINTERS -- */
	char *p; // declare p to be a pointer to a char
	
	
	return 0;
}

/* so when we say &s we seem to be saying 'the address of the array s' -- that is, the address of the first element.
 * but when we talk about s alone it's also this. so s and &s are somewhat interchangeable.
 * of course, *s is the (value of the) first element of the array s. */
