/* spawn some child processes and then loop forever */
// try killing these and see if the children stay.

// now we're going to try to actually kill the children from the parent process before exiting.

#include <unistd.h>
#include <signal.h>
#include <stdio.h>

#define NUM_CHILDREN 5

int main() {

	pid_t pids[NUM_CHILDREN];
	int i;

	// spawn NUM_CHILDREN-many child processes
	for (i = 0; i < NUM_CHILDREN; i++) {
		// spawn a child and make it loop forever.
		// original process continues and goes round again to spawn another
		// (until we've got NUM_CHILDREN)
		pids[i] = fork();
		if (pids[i] == 0)
			while(1) { ; }
	}

	// as David Bowie said, let the children boogie.
	// actually, no... kill all the children.
	for (i = 0; i < NUM_CHILDREN; i++) {
		sleep(1);
		kill(pids[i], SIGKILL);
		printf("killed %d...\n", pids[i]);
	}
	

	// end the main process
	return 0;
}

/* interestingly, when i run this and look at ps in another terminal, I see all the processes get spawned,
 * then as they are killed by the parent one by one the 'CMD' field becomes <defunct>...
 * so it seems like they aren't completely(?) killed until the parent process dies, and then they all disappear. */
