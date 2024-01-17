/* cause a buffer overflow. */

int main(void) {
	char s[] = "hello world";
	char c = s[20]; // try to access at an index that goes beyond
			// the end of the array.
	return 0;
}

// in fact, it compiles (with a warning) and it even runs fine (apparently). no segfault. I guess it could cause a segfault though... it just happens that the memory address that we try to access is already OK (but probably just contains garbage).

/* recall: if we'd instead done char *s = "hello world";
 * we'd have got a pointer to a perfectly valid string, but it would be
 * stored in read-only memory (not on the stack. */
