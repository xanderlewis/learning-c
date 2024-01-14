/* try and kill the shell! */

#include <unistd.h> // to be able to get pids
#include <signal.h> // to be able to send signals

int main() {
	kill(getppid(), SIGKILL); // try to kill the parent (probably the shell). IT WORKS!
	return 0;
}
