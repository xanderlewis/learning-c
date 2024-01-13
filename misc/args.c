/* thinking about command line arguments (argument count and argument vector) */

#include <stdio.h>

int main(int argc, char *argv[]) {
	// Just print out all the arguments we get (including the 0th)
	for (int i = 0; i < argc; i++)
		printf("argv[%d] = %s\n", i, argv[i]);
	return 0;
}

/* argc is the number of arguments (number of elements of argv);
 * argv is the vector of arguments: it's an array of strings.
 * that is, an array of pointers to characters.
 * I think I've seen it written before somewhere as 'char **argv'
 * (so as a pointer to a pointer to a char) which would also seem
 * to make sense...
 * seems to work just as well.
 * I'm not entirely sure what's actually going on when we use the
 * []-style syntax for declaring arrays...
 * something like char s[4] seems to set s to have type char*
 * and make sure that the memory addresses we get when we do something like
 * s + n (for n < 4) are allocated properly and can be accessed via the []
 * syntax. so writing s[n] is literally the same as writing *(s + n)..? */
