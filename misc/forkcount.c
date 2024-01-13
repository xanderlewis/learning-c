/* experimenting with fork() syscall */

#include <stdio.h> // for stdout stuff
#include <unistd.h> // for fork()
#include <sys/wait.h> // for wait()

int main() {
	// fork process; new process gets id 0 and old process gets (p)id of new processe
	int id = fork();
	int n;

	// start the counters from different values depending on whether we're in the original (main) process or the child
	if (id == 0)
		n = 1;
	else
		n = 11;

	if (id != 0)
		// we're in the main process; wait for the child to finish.
		wait(NULL);

	// count (either from 1 or 11, 10 times)
	for (int i = n; i < n + 10; i++) {
		printf("%d ", i);
		fflush(stdout); // flush the stdout buffer (we want to output stuff to the terminal straight away)
	}

	// if we're not in a child process, print a newline.
	if (id != 0)
		printf("\n");
	
	return 0;
}
