/* strcat: concatenate t to the end of s; s must be big enough. */
// The standard library version returns a pointer to the resulting string.

void strcat(char s[], char t[]) {
	int i, j;

	i = j = 0;
	while (s[i] != '\0') /* find end of s */
		i++;
	while ((s[i++] = t[j++]) != '\0') /* copy t */
		;
}

// The second while loop is equivalent to:
// while ((s[i] = t[j]) != '\0') {
// 	i++;
// 	j++;
// }
// 
// which is also equivalent to:
// while (t[j] != '\0') {
// 	s[i] = t[j]
// 	i++;
// 	j++;
// }
// To be honest, I actually think the final version is clearer at first glance, but maybe if you're used to the syntax it's nicer.
// (Note that the value of i++ is i and the value of ++i is i + 1.)
// These sorts of differences are very much important to a traditional language like C where there's lots of state and everything's quite procedural... To someone who's used to a functional way of thinking it seems to be a not-very-useful distinction...
