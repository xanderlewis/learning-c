#include <stdio.h>

/* showargs: just outputs its args to standard output so you can see them. */
int main(int argc, char **argv) {
	for (int i = 0; i < argc; i++)
		printf("arg[%d]: %s\n", i, argv[i]);
	return 0;
}
