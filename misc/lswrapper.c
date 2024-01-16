/* wrap ls into my own C program. completely pointless but why not? */

// (use /bin/ls)

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define LSPATH "/bin/ls"

int main(int argc, char *argv[], char *envp[]) {

	printf("running!\n--------\n");
	// fork
	int id;
	if ((id = fork()) == 1) {
		return 1;
	} // I guess we could just write 'return fork();' to achieve the same thing, but this might be weird.

	// exec
	if (id == 0) {
		execve(LSPATH, argv, envp);
		// if we end up here, exec has failed.
		return 1;
	}

	wait(NULL); // wait for child process (ls) to terminate
	printf("-----\ndone!\n");
	return 0;
}
