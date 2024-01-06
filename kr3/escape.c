#include <stdio.h>

#define MAX 256

/* escape: converts characters like newline and tab into visible escape sequences like \n and \t as it copies the string t to s. */
void escape(char t[], char s[]) {
	// 'writing' index into s
	int j = 0;

	// Iterate over chars in t
	for (int i = 0; t[i] != '\0'; i++)
		switch (t[i]) {
			case '\n':
				s[j] = '\\'; s[j+1] = 'n';
				j += 2;
				break;
			case '\t':
				s[j] = '\\'; s[j+1] = 't';
				j += 2;
				break;
			case '\a':
				s[j] = '\\'; s[j+1] = 'a';
				j += 2;
				break;
			case '\b':
				s[j] = '\\'; s[j+1] = 'b';
				j += 2;
				break;
			case '\v':
				s[j] = '\\'; s[j+1] = 'v';
				j += 2;
				break;
			case '\r':
				s[j] = '\\'; s[j+1] = 'r';
				j += 2;
				break;
			case '\\':
				s[j] = '\\'; s[j+1] = '\\';
				j += 2;
				break;
			default:
				s[j++] = t[i];
				break;
		}
}

/* unescape: converts visible escape sequences back into their corresponding (whitespace) characters as it copies the string s to t. */
void unescape(char s[], char t[]) {
	int i, j = 0;
	char esc = 0;
	// Iterate through chars of s
	for (int i = 0; s[i] != '\0'; i++) {
		if (esc) {
			// Last char was a backslash
			esc = 0;
			switch (s[i]) {
				case 'n':
					t[j++] = '\n';
					break;
				case 't':
					t[j++] = '\t';
					break;
				case 'a':
					t[j++] = '\a';
					break;
				case 'b':
					t[j++] = '\b';
					break;
				case 'v':
					t[j++] = '\v';
					break;
				case 'r':
					t[j++] = '\r';
					break;
				case '\\':
					t[j++] = '\\';
					break;
				default:
					// This should never occur, because in the original escape function we convert \ to \\.
					fprintf(stderr, "error: unrecognised escape sequence.\n");
					break;
			}
		}
		else
			// Last char was *not* a backslash
			if (s[i] == '\\')
				esc = 1;
			else
				// Copy character to t
				t[j++] = s[i];
	}
}

// test the above functions
int main() {
	int i;
	char string1[MAX], string2[MAX], c;
	for (i = 0; i < MAX; i++)
		string1[i] = string2[i] = 0;

	// Get a string from stdin
	for (i = 0; i < MAX && (c = getchar()) != '\n'; i++) {
		string1[i] = c;
	}

	// Put it through escape and output
	escape(string1, string2);
	printf("escaped version is:\n%s\n", string2);

	// Put that result through unescape and output
	for (i = 0; i < MAX; i++)
		string1[i] = 0;
	unescape(string2, string1);
	printf("unescaping this, we get:\n%s\n", string1);

	return 0;
}
