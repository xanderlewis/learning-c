/* squeeze2: deletes each character in s1 that matches any character in s2. */
// (chars in s2 should only appear once)

#include <stdio.h>

#define LENGTH 128

void squeeze2(char s1[], char s2[]) {
	int i, j, k = 0, m;

	for (i = 0; s1[i] != '\0'; i++) {
		m = 0;
		for (j = 0; s2[j] != '\0'; j++)
			if (s1[i] == s2[j])
				m = 1; // i'th char of s1 matched j'th in s2
		// If the i'th char of s1 didn't match anything, copy it
		if (!m)
			s1[k++] = s1[i];
	}

	s1[k] = '\0';
}

int main() {
	// test
	char s1[LENGTH], s2[LENGTH];
	int i;
	for (i = 0; i < LENGTH; i++)
		s1[i] = s2[i] = 0;
	char c;
	for (i = 0; i < LENGTH && (c = getchar()) != ','; i++)
		s1[i] = c;
	for (i = 0; i < LENGTH && (c = getchar()) != '\n'; i++)
		s2[i] = c;

	squeeze2(s1, s2);
	printf("%s\n", s1);

	return 0;
}
