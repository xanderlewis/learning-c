/* playing with pipes. */

// AMENDING THIS PROGRAM to try redefining stdin and stdout, etc.

#include <unistd.h> // pipe(), fork()?
#include <stdio.h> // fprintf, stderr, etc.

int main() {
	int fd[2]; // file descriptors
		   // fd[0] is for reading
		   // fd[1] is for writing
	
	if (pipe(fd) == -1) {
		fprintf(stderr, "something went wrong. :(\n");
		return 1;
	}

	int id = fork();
	// when we fork, the child process inherits the fd array from its parent
	// so each process has a pair of file descriptors for the pipe (the read end and the write end)
	if (id == 0) {
		// in the child process...
		close(fd[0]); // (we don't need the read end of the pipe)
		char x;
		printf("enter a char: \n");
		scanf("%c", &x);

		dup2(fd[1], fileno(stdout));
		// write this collected int to the pipe (use the second file descriptor we got from pipe()
		// actually, print to stdout now.
		printf("%c", x);
		//write(fd[1], &x, sizeof(char));
		// close (this end of) the pipe
		close(fd[1]);
	} else {
		// in the parent process...
		close(fd[1]); // (we don't need to write anything to the pipe)
		char y;
		// read out of the pipe
		read(fd[0], &y, sizeof(char)); // read is a blocking call; it will wait until there actually is something
					      // to read from the pipe.
		// close the read end of the pipe
		close(fd[0]);
		printf("Got %c from child process.\n", y);
	}
	return 0;
}
