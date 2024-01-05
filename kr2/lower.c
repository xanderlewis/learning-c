/* lower: convert a char to lowercase */
// the standard header <ctype.h> contains functions for implementation-independent (portable) tests and conversions like isdigit and tolower

int lower(int c) {
	if (c >= 'A' && c <= 'Z')
		return c + 'a' - 'A'; // if it's an uppercase char, add on the 'vector' that goes from A to a, i.e. takes each capital to its lowercase equivalent
				      // (note: this works because in ASCII the corresponding letters are each a fixed distance apart)
	else
		return c;
}

int main() {
	return 0;
}
