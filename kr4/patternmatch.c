#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */

int getaline(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould"; /* pattern to search for */

/* find all lines matching pattern */
int main() {
	char line[MAXLINE];
	int found = 0;

	// repeatedly get new lines
	while (getaline(line, MAXLINE) > 0)
		// if the line matches...
		if (strindex(line, pattern) >= 0) {
			printf("%s", line);
			found++;
		}
	return found;
}

/* getaline: get line into s; return length */
int getaline(char s[], int lim) {
	int c, i;
	
	i = 0;
	// get chars until either we reach lim chars or EOF or a newline
	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
		s[i++] = c;
	// pop the newline on the end (if it wasn't the EOF)
	if (c == '\n')
		s[i++] = c;
	// terminate the string
	s[i] = '\0';
	return i;
}

/* strindex: return index of t in s; -1 if none */
int strindex(char s[], char t[]) {
	int i, j, k;

	// iterate over s
	for (i = 0; s[i] != '\0'; i++) {
		// for each char in s, iterate from there for as long as it matches t
		for (j = i, k = 0; t[k] != '\0' &&  s[j] == t[k]; j++, k++)
			;
		if (k > 0 && t[k] == '\0')
			// we reached the end of t, meaning that it is fully contained in s
			return i;
	}
	return -1;
}
