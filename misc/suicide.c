#include <signal.h> // signals stuff
#include <unistd.h> // fork(), getpid(), getppid(), ...
#include <stdio.h>
#include <stdlib.h> // wait()

int main() {
	int pid = getpid();
	int ppid = getppid();
	printf("My PID is %d.\n", pid);
	printf("My parent (probably the shell?)'s PID is %d.\n", ppid);
	int newid = fork();
	if (newid == -1)
		return 1;
	else if (newid == 0) {
		// in the child process...
		int parentpid = getppid();
		printf("I'm the new child process. My parent's ID is %d.\n", parentpid);

	} else {
		printf("Spawned a child process with PID %d.\n", newid);
		// in the original (parent) process...
		printf("Goodbye.\n");
		/* kill oneself. */
		// ... but kill one's child first.
		wait(NULL); // (after it's finished)
		kill(newid, SIGKILL);
		kill(pid, SIGKILL); // will this kill the child process too? seemingly not.
		return 0;

	}
}
