#include <stdio.h>
#include <stdlib.h> // for exit()
#include <unistd.h> // for usleep()
#include <signal.h>

/* mainly using this to test signal stuff... */

void handle_sigterm(int);
void handle_sigint(int);
void handle_sigkill(int);

int main() {
	// set up signal handlers
	// (we pass a function pointer to the signal function, along with the signal number)
	signal(SIGTERM, handle_sigterm); // SIGTERM and SIGINT are just macros from <signal.h>
	signal(SIGINT, handle_sigint);
	signal(SIGKILL, handle_sigkill); // will this work? or will it just get ruthlessly killed?
	
	// indeed, it seems like we can't handle a SIGKILL.

	for (int i = 1;; i++) {
		printf("nothing (%d)!\n", i);
		usleep(100000); // 100ms
	}

	return 0;
}

void handle_sigterm(int sig) {
	printf("received a %d signal.\n", sig);
	exit(3);
}

void handle_sigint(int sig) {
	printf("received a %d signal.\n", sig);
	printf("(SIGINT)\n");
}

void handle_sigkill(int sig) {
	printf("received a %d signal.\n", sig);
	printf("SIGKILL\n");
}

/* I ran this and sent it a SIGTERM via another tty and zsh (its parent) terminated it.
 * sending it a SIGKILL also worked: zsh 'killed' it. now let's try to handle a SIGTERM...*/
