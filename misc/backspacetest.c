#include <stdio.h>
#include <unistd.h>

int main(void) {
	printf("hello!");
	fflush(stdout);
	sleep(1);
	printf("%c%c%c", 8, 8, 8);
	fflush(stdout);
	sleep(1);
	return 0;
}
