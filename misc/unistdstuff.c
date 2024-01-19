#include <unistd.h>
#include <stdio.h>

#define OUT(A, T) printf(#A ": %" #T "\n", A);

int main() {
	// symbolic constants for POSIX versions
	OUT(_POSIX_VERSION, ld);
	OUT(_POSIX2_VERSION, ld);

	// try some functions declared in the <unistd.h> header
	OUT(getlogin(), s);
	OUT(
	return 0;
}
