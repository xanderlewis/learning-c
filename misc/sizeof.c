// I seem to recall there's a sizeof keyword (probably a function?) that can give the size (maybe in bytes?) of some variable of piece of data.
// Let's try.
// Next day: OK, it turns out sizeof is *not* actually a function; it's part of the language. In fact, it's substituted for the size of the requested
// thing during compilation. So the compiled program is not even doing any size calculation!
// Hence, we need not enclose the argument in brackets.


#include <stdio.h>
#include <limits.h>

int main() {
	printf("ints have size %lu\n", sizeof(int));
	printf("long (int)s have size %lu\n", sizeof(long int));
	printf("short (ints)s have size %lu\n", sizeof(short int));
	printf("chars have size %lu\n", sizeof(char));
	printf("pointers to chars have size %lu (%lu bits)\n", sizeof(char*), CHAR_BIT * sizeof(char*)); // not immediately sure if this will work...
	printf("pointers to ints have size %lu\n", sizeof(int*)); // should be the same as for char, if anything...
}
