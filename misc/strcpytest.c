/* Testing how strcpy works (to debug something). */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	//char *str1 = malloc(32 * sizeof(char));
	char *str1 = calloc(32, sizeof(char));
	for (int i = 0; i < 6; i++)
		str1[i] = ' ';
	//str1 = "hello, world!";
	char *str2 = "another";

	printf("%s\n", str1 + 6); // prints 'world!'

	strcpy(str1 + 6, str2);

	printf("%s\n", str1);

	return 0;
}

/* I guess setting a char* to a string literal doesn't write that string into the memory
 * on the heap pointed to by that pointer; it just sets it to point to some (entirely
 * separate) memory on the stack or something like that. */
