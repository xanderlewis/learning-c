#include <stdio.h>

int main() {
	char string[8];
	int i;
	string[0] = 'a';
	string[1] = 'b';
	for (i = 2; i < 8; i++) {
		string[i] = 0;
	}
	printf("%s", string);
	return 0;
}
