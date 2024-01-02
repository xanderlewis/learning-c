// Prints a table of temperatures in Fahrenheit and Celsius.
// Originally we were using ints for the temperature values; now we're using floats we can write the calculation a bit more naturally
// and get more accurate results.

#include <stdio.h>

int main() {
	float fahr, celsius;
	int start, stop, step;

	start = 0;
	stop = 300;
	step = 10;

	fahr = start; // note: the int start is casted to a float before assignment to fahr
	
	printf("  F     C\n---------\n");

	while (fahr <= stop) /* also here: the int stop is casted to a float before comparison with fahr */ {
		celsius = 5.0/9.0 * (fahr - 32.0);
		printf("%3.0f%6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}
	
	return 0;
}
