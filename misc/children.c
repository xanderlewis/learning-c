/* spawn some child processes and then loop forever */
// try killing these and see if the children stay.

#include <unistd.h>

#define NUM_CHILDREN 5

int main() {

	// spawn NUM_CHILDREN-many child processes
	for (int i = 0; i < NUM_CHILDREN; i++) {
		// spawn a child and make it loop forever.
		// original process continues and goes round again to spawn another
		// (until we've got NUM_CHILDREN)
		pid_t pid = fork();
		if (pid == 0)
			while(1) { ; }
	}
	// end the main process
	return 0;
}

/* indeed, when we run this it exits but there are still 5 children. running again spawns 5 more.
 * now I'll have to kill them manually!
 * killall a.out */
