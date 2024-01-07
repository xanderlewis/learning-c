#include <string.h>

/* trim: remove trailing blanks, tabs, newlines; returns the new length */
int trim(char s[]) {
	int n;

	// Look through the string from the end
	for (n = strlen(s) - 1; n >= 0; n--)
		if (s[n] != ' ' && s[n] != '\t' && s[n] != '\n')
			// As soon as we find a non-blank, break out
			break;
	// End the string there
	s[n+1] = '\0';
	return n;
}
