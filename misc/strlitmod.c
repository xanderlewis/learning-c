/* attempting to modify a string literal. */

/* apparently, this results in undefined behaviour according to the ANSI C standard but isn't caught by most compilers. it then of crashes at runtime. */

int main(void) {
	// declare and initialise a string literal
	char *s = "Hello, world!";

	// try to modify the first char...
	*s = 'h';
}

/* indeed: compiles fine, but crashes with a 'bus error' when run. */

/* apparently when it's run, the string ends up in the read-only section of the data segment of the process (makes sense... it was a literal rather than something we explicitly tried to assign to an array) which is why trying to write to it causes an issue. s is a pointer to a memory address outside where we're supposed to be able to do stuff. so when we dereference s on the left side of the equality and try to set its value, we get a segfault. not sure why it says 'bus error' though instead of 'segmentation fault'... */
