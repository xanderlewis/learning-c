/* playing with signals... */

#include <stdio.h>
#include <unistd.h> // for fork(), usleep(), etc. this header declares POSIX stuff.
#include <signal.h> // for kill()
#include <stdlib.h> // for wait()

#define forever while (1)

int main(int argc, char *argv[]) {
	// We can use the kill syscall(?) to (request the system to?) send signals to processes
	
	/* a process has permission to send a signal if the real or effective user ID of the sender is the
	 * same as the real or effective user ID of the intended recipient.
	 * a process can also send signals if it has appropriate privileges. */

	// Fork and get the pid of the new child process (return value is 0 in the child process itself)
	int pid = fork(); // the return type is called pid_t (but I think this is basically an int?)
	if (pid == -1)
		return 1; // failed to fork
	
	if (pid == 0) {
		// in the child process...
		int i = 1;
		forever {
			printf("hello! #%d :)\n", i++);
			/* I guess when the child gets created, it inherits its stdin and stdout from
			 * its parent... */
			usleep(100000); // wait 100ms
		}
	} else {
		// in the parent...
		printf("spawned a child process (with pid %d).\n", pid);
		sleep(1); // wait a second
		kill(pid, SIGSTOP); // stop the child process (halt its execution in place)
		printf("stopped the child.\n");
		sleep(1); // wait another second
		printf("now continuing...\n");
		kill(pid, SIGCONT); // continue the execution of the child process
		sleep(1);
		kill(pid, SIGKILL); // kill the child process (send a SIGKILL (9?) signal)
		wait(NULL); // wait for child to exit (well, we've already killed it)
		printf("child process finished.\n");
	}

	return 0;
}
