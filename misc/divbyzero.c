/* let's try dividing by zero. what will happen? will we get a SIGFPE? */

int main() {
	int a = 1 / 0;
	return 0; // if for some reason the above succeeds
}

// well, the compiler warns us that division by zero is undefined.
// ..but it compiles fine and actually runs and returns 0. hmm...
// I thought this might be a way of a process ending its own existence
// without having to ask the system to do so via a syscall like with exit().
// but alas... not.
// we could intentionally cause a segfault or something? haha
// but when the program 'reaches the end' (drops of the end of main() it exits anyway, somehow...
