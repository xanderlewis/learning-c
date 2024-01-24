/* playing with the termios functions. */

#include <termios.h>
#include <unistd.h>
#include <stdio.h>

/* todo: test autocompletion of local filenames.
 * that is, echo input chars, but try (in a different colour) to complete
 * whatever the user has currently typed into a file in the current working
 * directory.
 *
 * to start with: implement backspace properly. */

#define BACKSPACE 127
#define MAX_LINE 32

struct termios ts;
char buf[MAX_LINE];
char *bp = buf; // ( == &(buf[0]))

void init(void) {
	// Disable canonical mode and echoing of input characters.
	tcgetattr(STDIN_FILENO, &ts);
	ts.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &ts);
}

void show_buf(void) {
	char *p;
	int n, i;
	for (p = buf; p < bp; p++) {
		putchar(*p);
		n++;
	}
	for (i = 0; i < MAX_LINE - n; i++) {
		putchar(' ');
	}
}

void cursor_back(void) {
	int i;
	for (i = 0; i < MAX_LINE; i++) {
		printf("\033[D");
	}
}

int main(void) {
	int c, i;

	init();

	while (1) {
		// Show current line buffer
		cursor_back();
		show_buf();	

		// Get a char
		c = getchar();

		if (c == BACKSPACE) {
			bp--;
		} else {
			*(bp++) = c;
		}
	}

	return 0;
}
