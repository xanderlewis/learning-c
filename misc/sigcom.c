/* interprocess communication using signals */
/* signals are intended to be used to indicate that an 'event has occurred',
 * but here we try to (ab)use them (as a deliberately weird hack) to
 * transmit data a la pipes or sockets. */

// (spawn two copies of this program and use one to talk to the other)

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <math.h>
#include <stdlib.h>

// we'll use these two (arbitrarily chosen for their catchability) signals to represent 0 and 1
#define SIG_0 SIGHUP
#define SIG_1 SIGINFO

#define DELAY_MICROSECONDS 5000
/* (0.005s per bit. works with 100 microseconds; 0 produces garbledness.) */

char nextbyte;
int currexp = 0;

void reczero(int n) {
	// received a zero
	currexp = (currexp + 1) % 8;
	if (currexp == 0) {
		// byte collected
		printf("%c", nextbyte);
		fflush(stdout);
		nextbyte = 0;
	}
}

void recone(int n) {
	// received a one
	nextbyte += pow(2, currexp);
	currexp = (currexp + 1) % 8;
	if (currexp == 0) {
		// byte collected
		printf("%c", nextbyte);
		fflush(stdout);
		nextbyte = 0;
	}
}

void recintr(int n) {
	// recieved an interrupt (probably by doing Ctrl-C)
	printf("\ngoodbye ;-)\n");
	exit(0);
}

int main(void) {
	pid_t target_pid;
	int i;
	char c;

	// set up handlers for incoming bits
	signal(SIG_0, reczero);
	signal(SIG_1, recone);

	signal(SIGINT, recintr);

	// get target PID from user
	printf("enter target PID: ");
	scanf("%d", &target_pid);
	for (;;) {	
		// get next char from stdin buffer
		c = getchar();
		// transmit binary encoding
		for (i = 0; i < 8; i++) {
			if (c % 2 == 0) {
				// transmit a zero
				kill(target_pid, SIG_0);
			} else {
				// transmit a one
				kill(target_pid, SIG_1);
			}
			c /= 2;
			usleep(DELAY_MICROSECONDS);
		}
	}
	return 0;
}
