// I'm reading Kernighan & Ritchie (2nd edition).

// #include <stdio.h>
// (instead of including that library function I'll just make my own thing...)

int printf(char *s) {
	return 5;
}

int main() {
	return printf("Hello, world!\n");
}
