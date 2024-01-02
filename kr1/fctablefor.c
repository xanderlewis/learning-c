// The same Fahrenheit --> Celsius table program, but this time using a for loop rather than a while.
// (modified to print the table in reverse order to before).

#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

// We also made use of the define keyword to ask the compiler (?) (preprocessor?) to make some substitutions.
// It's conventional to use UPPERCASE for these symbolic constants.

int main() {
	int fahr;

	for (fahr = UPPER; fahr >= LOWER; fahr = fahr - STEP) {
		printf("%3d %6.1f\n", fahr, 5.0/9.0 * (fahr - 32.0));
	}
}
