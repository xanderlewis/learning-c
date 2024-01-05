/* any: returns the first location in s1 where any character from s2 occurs, or -1 if s1 contains no characters from s2. */
// (the standard library function strpbrk does the same job but returns a pointer to the location.)

#include <stdio.h>

#define LENGTH 128

unsigned int any(char s1[], char s2[]) {
	int i, j;
	for (int i = 0; s1[i] != '\0'; i++)
		for (j = 0; s2[j] != '\0'; j++)
			if (s1[i] == s2[j])
				return i;
	return -1;
}

int main() {
	// test
	char s1[LENGTH], s2[LENGTH];
	char c;
	int i;
	while(1) {
		for (i = 0; i < LENGTH; i++)
			s1[i] = s2[i] = 0;
		for (i = 0; i < LENGTH && (c = getchar()) != ','; i++)
			s1[i] = c;
		for (i = 0; i < LENGTH && (c = getchar()) != '\n'; i++)
			s2[i] = c;

		printf("%d\n", any(s1, s2));
	}
	return 0;
}
