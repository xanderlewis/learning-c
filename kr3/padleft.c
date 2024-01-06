#include <stdio.h>

#define MAX_LENGTH 256

/* padleft: pad the string s with blanks on the left out to a minimum field width of n */
void padleft(int n, char s[]) {
	int i, j, p, l;
	char t[MAX_LENGTH];
	// Find length of s (whilst copying s)
	for (l = 0; s[l] != '\0'; l++)
		t[l] = s[l];
	t[l] = '\0';

	// Pad s
	p = n - l;
	if (p > 0) {
		// Write p many blanks
		for (i = 0; i < p; i++)
			s[i] = ' ';
		// Append original s
		for (j = 0; j < l; j++)
			s[i++] = t[j];

	}
}

int main() {
	// test
	int i;
	char s[MAX_LENGTH], c;
	for (i = 0; i < MAX_LENGTH; i++)
		s[i] = '\0';
	for (i = 0; i < MAX_LENGTH && (c = getchar()) != '\n'; i++)
		s[i] = c;
	s[i] = '\0';
	padleft(16, s);
	printf("padded out to 16 chars:\n%s\n", s);
	return 0;
}
