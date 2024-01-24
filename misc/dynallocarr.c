#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int l;
	if (argc == 2)
		l = atoi(argv[1]);
	else {
		printf("requires an integer argument.\n");
		return 1;
	}

	char arr[l + 1]; // will this work? YES.
	for (int i = 0; i < l; i++)
		arr[i] = 'A' + i;
	arr[l] = '\0';
	printf("%s\n", arr);
	return 0;
}

// so you can, apparently, declare an array of length determined at runtime.
