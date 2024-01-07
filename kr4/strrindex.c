#include <stdio.h>

/* strrindex: returns the position of the *rightmost* occurence of t in s, or -1 if there is none. */
int strrindex(char s[], char t[]) {
	int i, j, k, l;

	// Find end of s
	for (i = 0; s[i] != '\0'; i++)
		;
	// Move back to the last possible start of t in s
	for (j = 0; t[j] != '\0'; j++)
		i--;	
	
	// Look for t in s
	for (j = i; j > 0; j--) {
		for (k = j, l = 0; t[l] != '\0' && s[k] == t[l]; k++, l++)
			;
		if (t[l] == '\0')
			return j;
	}
	return -1;
}

int main() {
	// test
	char s[128], t[128], c;
	int i;
	for (i = 0; i < 128 && (c = getchar()) != ','; i++)
		s[i] = c;
	s[i] = '\0';
	for (i = 0; i < 128 && (c = getchar()) != EOF && c != '\n'; i++)
		t[i] = c;
	t[i] = '\0';
	return strrindex(s, t); /* NOTE: if t isn't found this'll return -1 as an exit code, which probably wraps round to 255 on most systems. */
}
