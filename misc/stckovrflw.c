/* try to get a stack overflow? I guess I can make it happen... */

#include <stdio.h>

void func(int i) {
	// call oneself
	printf("calling myself for the %d(th/st/nd) time...\n", i);
	func(++i);
}

int main() {
	func(1); // call func, which then repeatedly calls itself
		 // hopefully, we've blow up the stack at some point
		 // yay: segmentation fault at the 26157th call!
	return 0;
}
