/* I saw this example given in a lecture video, where the lecturer started to evaluate the
 * expression and then wasn't sure whether it actually worked. Let's try it. */

// Evaluate *(&(&(&(*(*(*x)))))).
// If we can dereference x three times, then x has to at least be a triple
// pointer...
// but then can we meaningfully talk about the address of this int 
// three times, and then derefernce it once again?
// Straight away, it looks like it should just be the same as *x, but

// We could also write *(*(*(&(&(&x)))))... but this doesn't immediately make
// sense either, because whilst we can happily talk about the address of x
// (provided we've declared x) we can't then talk about the address of this address
// unless we've stored it somewhere. Things that are just floating around as expressions
// don't have addresses.
// ...so we'd have to create pointers to store the first two addresses, and then the final
// & would provide us with an address which we could reference three times to get back to x
// again.

// This is the distinction between lvalues and rvalues in a C compiler.

// an 'lvalue' is an expression that can be placed on the LHS of the assignment operator.
// an 'rvalue' is something else (any other expression).
// So basically.. the lvalues are the *special* expressions that support assignment.
// We can assign pretty much any expression to anything that supports assignment, but
// it is certainly *not* true that we any expression supports assignment.
// For example, something that is *not* an lvalue is a numerical expression:
// We can't say 3 = 4, for example, but x = 4 is perfectly fine (provided we've declared x).

// We can use the reference operator & as many times as we like, but what we get back will
// be an rvalue and will not be assignable.
// In contrast, we can use the dereference * operator n times if the expression we start off
// with has type an n-times iterated pointer. What we get back *will* be an lvalue right up
// until we dereference the final time and end up with the value stored in the original
// variable.

// An lvalue is a thing that has to have a memory address. If we have a pointer p of type
// char *, then p is an lvalue because it has an address. If we dereference once to get *p,
// we now have something of type char which is also an lvalue.
// But chars are not always lvalues; for example, 'a' is a char but is an rvalue.

// If we're referencing multiple times by doing &&&& stuff, it only makes sense if each
// intermediate address is actually being stored somewhere. We need n-1 pointers for n uses
// of the & operator (the final address need not be stored anywhere (have an address)
// to make sense).

// TLDR:
// We can take the address of an lvalue of type char *, but NOT of an rvalue of type char*.


#include <stdio.h>

int main(void) {
	int x = 3;
	int *p = &x;
	int **q = &p;
	int ***r = &q;

	// This WON'T work.
	/*printf("%d\n", *(*(*(&(&(&x))))));*/

	// The first & operator is fine, but the second is already wrong.
	// We have stored the value of &x somewhere above, but this is not
	// what we're talking about in this expression.
	
	// This WILL work.
	printf("%d\n", ***r);

	// The pointer notation makes it quite clear that the above makes sense
	// and should evaluate to an int.
	// INDEED: prints '3'.
	
	// This WON'T work.
	/* printf("%d\n", &(&(&(*(*(*r))))));*/
	
	// The first three * operators are fine; again we just end up with x.
	// But now we have the same problem. Using & once is fine, but the second
	// & now has a problem because we are attempting to get the address of an
	// rvalue.

	return 0;
}

// All of this also explains why the notation (in particular, the standard spacing used)
// for pointer types makes sense; `char* p` means p has type 'char pointer',
// but this is usually written as `char *p` which would possibly be (mis!)interpreted
// as saying that there is something called '*p' of type char.

// But the latter is useful notation, because although p is a pointer rather than a char,
// we are almost always using p by dereferencing it (it is a pointer, afterall)
// and so the most important thing is really the type of thing it points to.
// In our code, we'll mostly be talking about `*p`, and so it's nice and clear to know that
// this expression has type char (rather than having to think each time that we're dereferencing
// a char pointer to get a char).

// ----
// TLDR: any occurrence of '&&' is going to fail.
// ----
