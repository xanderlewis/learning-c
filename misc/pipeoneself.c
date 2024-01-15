/* I'm not sure how this pipe() syscall works... let's see if we can create a pipe and then just write stuff to it and read it back from within the same process. */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int fd[2]; // to store the file descriptors we get from the pipe() call

int write_char(char c) {
	int r =  write(fd[1], &c, sizeof(char));
	printf("Wrote %c to the pipe.\n", c);
	return r;
}

char read_char() {
	char c;
	int r = read(fd[0], &c, sizeof(char));
	if (r != -1) {
		printf("Read back %c from the pipe.\n", c);
		return c;
	} else {
		fprintf(stderr, "couldn't read from the pipe. :(\n");
		exit(1);
	}
}

int main() {
	// call pipe() and give it the array to store the file descriptors. if pipe() returns -1, stop.
	// we can read from fd[0] and write to fd[1] using the read() and write() calls.
	// the pipe acts like buffer (I'm not sure of the size of it) that will store the stuff we write so we can
	// read it back later (potentially from some other process, ut here from the same place).
	if (pipe(fd) == -1) {
		fprintf(stderr, "couldn't create a pipe. :(\n");
		return 1;
	}

	// try writing to pipe
	write_char('@');
	// try reading back
	read_char(); // (we won't do anything with the return value)
	
	// try writing a few chars
	char i;
	for (i = 0; i < 10; i++)
		if (write_char('a' + i) == -1) {
			fprintf(stderr, "we couldn't write to the pipe. :(\n");
		}

	// read back these chars
	for (i = 0; i < 10; i++)
		read_char();

	// running: indeed it works like a queue (FIFO). not sure how large the buffer is though.
	
	// write a string to the pipe
	char *s = "hello! :)"; // the compiler will allocate enough memory to store these chars starting at s
	
	// write the string to the pipe
	write(fd[1], s, sizeof(char) * 9); // write 9 bytes
	printf("\nWrote a string to the pipe.\n");

	// read it back?
	for (i = 0; i < 9; i++) // read back 9 bytes
		read_char();

	close(fd[0]);
	close(fd[1]);
	return 0;
}
