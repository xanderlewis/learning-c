/* atoi: convert ascii string representing an integer to an actual integer */

int atoi(char s[]) {
	int i, n;

	n = 0;
	for (i = 0; s[i] >= '0' && s[i] <= '9'; i++) {
		n = 10 * n + (s[i] - '0'); // shift n up by a single place (in decimal) and add the appropriate digit
					   // (s[i] - '0' computes the offset from 0 represented in ASCII)
	}
	return n;
}
