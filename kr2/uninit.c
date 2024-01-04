// Declaring variables and getting their values without (explicitly) initialising.

#include <stdio.h>

// Static stuff
int a, b; // should be initialised to zero

int main() {
	// Automatic stuff
	int c, d; // should contain random junk?
	float e;
	char f[100]; // a pointer to random junk? (100 chars of garbage?)
	char g[100];

	printf("external stuff: %d\n%d\n", a, b);
	printf("main stuff: %d\n%d\n", c, d); // interestingly, c seems to be junk but d is always zero. I wonder why...
					      // oh.. actually, that was some kind of temporary phenomenon.
	printf("a float: %f\n", e);
	printf("a string: %s\n", f);

	g[0] = '\0';
	printf("another string: %s\n", g); // should be nothing
	
	g[0] = g[1] = g[2] = 'a';
	printf("%s", g); // it never seems to last much longer than three chars, perhaps because most of this memory is zero anyway.
	return 0;
}
