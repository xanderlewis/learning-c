#include <stdio.h>
#include <unistd.h> // for fork()

int main() {
	// fork once
	int id1 = fork();

	// fork twice
	int id2 = fork();

	if (id1 == 0) {
		// we're in the first child
	} else {
		// we're in the original process (
	}

	if (id2 == 0) {
		// we're in the second child
		// well.. level of children.
		// we could be the child of the original, or the child of the first child
	} else {
		// we're either in the original process, or the first child
	}

	/* we can combine these into four checks... (well, two nested ones) */

	if (id1 == 0) {
		if (id2 == 0) {
			// we're in the child of the child
		} else {
			// we're in the first child of the original process
		}
	} else {
		if (id2 == 0) {
			// we're in the second child of the original process
		} else {
			// we're in the original (parent of all of the above) process
		}
	}
	return 0;
}

/* the first fork() call creates a child process (total: 2), which on the second fork() call creates a child of its own (total: 3).
 * at this point, though, the original process also has another child process. so in total we have four processes: the original parent process, the first child it had, and the two children after that (of the original process again and the child). */
