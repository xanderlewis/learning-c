#include <stdio.h>

/* itob: converts the integer n into a base b character representation in the string s */
void itob(int n, int b, char s[]) {
	int i = 0, j, d;
	char c;
	do {
		d = n % b;
		s[i++] = (d >= '0' && d <= '9') ? '0' + d : 'a' + d - 10;
	} while ((n /= b) > 0);

	// (then reverse it)
	for (j = 0; s[j] != '\0'; j++)
		;
	j--;
	for (i = 0; i < j; i++, j--)
		c = s[i], s[i] = s[j], s[j] = c;
}

int main() {
	// test
	int i;
	char s[128];
	for (i = 0; i < 128; i++)
		s[i] = '\0';

	int n = 48879, b = 16;
	itob(n, b, s);
	printf("in decimal: %d\nin base %d: %s\n", n, b, s);

	return 0;
}
