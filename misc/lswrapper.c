/* wrap ls into my own C program. completely pointless but why not? */

// (use /bin/ls)

#include <unistd.h> // (POSIX) system calls like fork() and exec()
#include <stdlib.h> // wait() (which is apparently part of the C standard)
#include <stdio.h>

#define LSPATH "/bin/ls"

int main(int argc, char *argv[], char *envp[]) {

	printf("running!\n--------\n");
	// FORK
	int id;
	if ((id = fork()) == 1) {
		return 1;
	} // I guess we could just write 'return fork();' to achieve the same thing, but this might be weird.

	// EXEC
	if (id == 0) {
		execve(LSPATH, argv, envp); // (explicitly passing environment variables)
		// if we end up here, exec has failed.
		return 1;
	}

	int status;
	wait(&status); // wait for child process (ls) to terminate
	printf("-----\ndone!\n");
	printf("(ls finished with status %d)\n", status);
	return 0;
}
