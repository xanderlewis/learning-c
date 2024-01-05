/* squeeze: delete all c from s. */

void squeeze(char s[], int c) {
	int i, j;

	for (i = j = 0; s[i] != '\0'; i++)
		// If the i'th char is not c
		if (s[i] != c)
			// Copy the i'th char into the j'th position and increment j
			s[j++] = s[i];
	s[j] = '\0';
}
