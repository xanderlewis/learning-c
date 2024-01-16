/* playing with the exec() syscall. */

/* the exec family of functions cause the running process to be completely replaced by the program we pass in as an
 * argument. the PID doesn't change; the data, heap and stack of the original process are just entirely replaced by those
 * of the new process.
 * well... not a new processs from the OS's point of view, but it's now doing something else.
 * the 'new' process inherits the current environment variables. */

// the functions are called 'exec', followed by one more more letters:
// e - an array of pointers to environment variables is explicitly passed to the new process image.
// l - command line arguments are passed individually to the function (we used this below)
// p - uses the PATH environment variable to find the file named in the path argument to be executed.
// v - command line arguments are passed to the function as an array of pointers.

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h> /* wait() */

#define XPATH "/bin/ls"

int main() {
	// fork and exec
	int id;
	if ((id = fork()) == -1) {
		fprintf(stderr, "failed to fork. :(\n");
		return 1;
	}
	if (id == 0) {
		// in the new child process...
		printf("[forked.]\n");
		// replace it with ls
		execl(XPATH, XPATH, "-alt", ".", NULL); // note: we end the arguments with a null pointer
		// (should then exit)
	}

	// wait for the child (now ls) to terminate, and then report.
	wait(NULL);
	printf(XPATH " finished.\n");

	// this time, try execlp (use PATH to find the file, as well as passing arguments individually)
	if ((id = fork()) == -1) {
		fprintf(stderr, "failed to fork the second time. :(\n");
		return 1;
	}
	if (id == 0) {
		// in the child...
		printf("[forked.]\n");
		execlp("ls", "[location of ls; we don't know]", "-alt", ".", NULL); // call execvp (use PATH to search for ls)
	}

	wait(NULL);
	printf("ls (using PATH) also finished.\n");
	
	return 0;
}
