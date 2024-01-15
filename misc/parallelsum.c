/* summing up the elements of an array using two parallel processes. */

#include <unistd.h> // for fork(), pipe()
#include <stdio.h> // for printf()

#define THEY (id == 0) ? "child" : "parent"

int main() {
	int a[] = { 5, 7, 18, 2, 6, 3 };
	int a_size = sizeof(a) / sizeof(int);
	int left, right;
	int fd[2];

	// try to open a pipe (that we will then access from each new process after forking)
	if (pipe(fd) == -1) {
		return 1; // failed to create the pipe
	}

	// try to fork
	int id = fork();
	if (id == -1) {
		return 1; // failed to fork
	}

	if (id == 0) {
		// in the child... set up range
		left = 0; // from beginning of array
		right = a_size / 2; // up to halfway

	} else {
		// in the parent... set up range
		left = a_size / 2; // from halfway
		right = a_size; // up to end
	}

	// compute sum of specified range (in both the parent and child in parallel)
	int sum = 0, i;
	for (i = left; i < right; i++) {
		sum += a[i];
		printf("[%s updated its sum]\n", THEY);
	}

	printf("%s's partial sum is %d\n", THEY, sum);

	if (id == 0) {
		// write sum back to pipe
		close(fd[0]);
		write(fd[1], &sum, sizeof(sum)); // write value of sum to the pipe (to get it back to the parent)
		close(fd[1]);
	} else {
		// read sum from pipe (from child)
		int child_sum;
		close(fd[1]);
		read(fd[0], &child_sum, sizeof(child_sum)); // (this will wait for the child to actually write something)
		close(fd[0]);

		// add the two together
		int total = sum + child_sum;
		printf("total is %d\n", total);
	}
	return 0;
}

// note: we're not doing any error handling on the read and write calls. these could fail.
