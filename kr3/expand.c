#include <stdio.h>

void expand_single(char s1[], char s2[]);

/* expand: expands shorthand notations like a-z in the string s1 into the equivalent complete list abc...xyz in s2 */
// (allows for letters of either case and digits, and handles cases like a-b-c and a-z0-9)
// A leading or trailing - is taken literally.
void expand(char s1[], char s2[]) {
	// Input index i; output index j
	int i, j, k;
	i = j = 0;
	
	// Ignore leading hyphen
	if (s1[i] == '-')
		i++;

	// Iterate over input chars
	while (s1[i] != '\0') {
		if (s1[i] == '-') {
			if (s1[i+1] != '\0') {
				// Interpret as shorthand
				/* (we assume we have a hyphenated pair like x-y, and leverage the fact that sequences
				   like the alphabet and 0-9 are contiguous sequences in ASCII) */
				for (k = 1; s1[i-1] + k < s1[i+1]; k++) 
					s2[j++] = s1[i-1] + k;
				i++;

			} else {
				// Interpret literally
				s2[j++] = s1[i++];
				break;
			}
		} else {
			// Interpret literally
			s2[j++] = s1[i++];
		}
	}
}

// TEST STUFF
int main() {
	char s[19], t[128];
	for (int i = 0; i < 128; i++)
		t[i] = 0;
	s[0] = 'a', s[1] = '-', s[2] = 'f';
	s[3] = '0', s[4] = '-', s[5] = '7';
	s[6] = 'D', s[7] = '-', s[8] = 'X';
	s[9] = 'a', s[10] = '-', s[11] = 'b', s[12] = '-', s[13] = 'c';
	s[14] = ' ', s[15] = 'h', s[16] = 'i', s[17] = '!';
	s[18] = '\0';
	expand(s, t);
	printf("original string: %s\n", s);
	printf("expanded string: %s\n", t);
	return 0;
}
