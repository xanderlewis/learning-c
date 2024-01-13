// just want to see what these macros (from the standard library) actually become... try sending to stdout?
#include <stdio.h>

#define OUT(A) printf(#A ":\t0x%08x (%d)\n", A, A)

int main() {
	// of course, not all of these have the correct types, but we just try to print them anyway.
	OUT(NULL); // pointer to NULL
	OUT(BUFSIZ);
	OUT(EOF);
	OUT(FOPEN_MAX);
	OUT(FILENAME_MAX);
	OUT(SEEK_CUR);
	OUT(SEEK_END);
	OUT(SEEK_SET);

	printf("\nfile pointers:\n");
	OUT(stderr); // these have type FILE*
	OUT(stdin);
	OUT(stdout);
	return 0;
}
