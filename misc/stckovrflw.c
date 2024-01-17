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

/* gcc compiles this fine, but it causes a segfault when it runs.
 * however, if we compile using the -O2 or -O3 flags (instead of the default -O1) gcc will do tail-call optimisation and it should run fine. we're doing infinite recursion, but it shouldn't take up more space on the stack. indeed: when we run it, it just goes into an infinite loop, not eating up space on the stack and so runs (theoretically) forever! */
