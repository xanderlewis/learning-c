/* lower2: converts a string to lowercase. */
// (this time using a conditional expression)
// as before, I think the standard library one returns a pointer to the string.. or something.
void lower2(char s[]) {
	for (int i = 0; s[i] != '\0'; i++)
		s[i] = (s[i] >= 'A' && s[i] <= 'Z') ? s[i] + 'a' - 'A' : s[i]
}
