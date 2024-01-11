#include <stdio.h>

/* reverse: reverses the given string in place */
/* (using recursion! (pass in left and right of the (sub)string to be reversed) */
void reverse(char s[], int left, int right) {
	// base case: empty string
	if (right <= left)
		return;

	// Swap far left and far right
	int temp = s[left];
	s[left] = s[right];
	s[right] = temp;
	
	// reverse the middle part of the string
	reverse(s, left + 1, right - 1);
}

int main() {
	// test the above function
	char s[] = "hello, world! :)";
	int i;
	for (i = 0; s[i] != '\0'; i++)
		;
	reverse(s, 0, --i);
	printf("%s\n", s);
	return 0;
}
