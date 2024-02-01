/* A brainfuck interpreter. */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_CELLS   32768
#define PROG_SIZE   32768

#define SHOW_CELLS  12
#define SHOW_PROG   128
#define CLOCK_RATE  50 // (Hz)

// Cell memory, program memory, cell pointer,
// instruction pointer, end (of program) pointer.
unsigned char *cells, *program, *cp, *ip, *ep;

void bf_show_state(void);

int main(int argc, char **argv) {
	int c, i, bl, running;
	char *command_chars = "><+-.,[]";

	if (argc != 2) {
		fprintf(stderr, "usage: %s [program text]\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	// Allocate memory for cells and set cell pointer.
	cells = calloc(NUM_CELLS, sizeof(char));	
	cp = cells;

	// Load program; set instruction pointer and end pointer.
	program = malloc(PROG_SIZE * sizeof(char));
	ip = program;
	FILE *f = fopen(argv[1], "r");
	if (!f) {
		fprintf(stderr, "I couldn't find the program '%s'. :(\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((c = fgetc(f)) != EOF) {
		for (i = 0; command_chars[i] != '\0' && c != command_chars[i]; i++)
			;
		if (command_chars[i] != '\0') {
			*(ip++) = (char) c;
		}
	}
	ep = ip;
	ip = program;

	// Run program.
	running = 1;
	while (running) {
		// Give visual indication of current state.
		//bf_show_state();
		//getchar();
		//usleep(1000000 / CLOCK_RATE);

		// Interpret next instruction.
		switch (*ip) {
			case '>':
				cp++;
				break;
			case '<':
				cp--;
				break;
			case '+':
				(*cp)++;
				break;
			case '-':
				(*cp)--;
				break;
			case '.':
				//printf("\nOUTPUT: 0x%02x\n\n", *cp);
				printf("%c", *cp);
				break;
			case ',':
				printf("input:");
				scanf("%x", cp);
				fflush(stdin);
				break;
			case '[':
				if (*cp == 0) {
					// Find corresponding ']'.
					ip++;
					for (bl = 1; bl != 0; ip++) {
						if (*ip == '[')
							bl++;
						else if (*ip == ']')
							bl--;
					}
					ip--;
				}
				break;
			case ']':
				if (*cp != 0) {
					// Find corresponding '['.
					ip--;
					for (bl = -1; bl != 0; ip--) {
						if (*ip == '[')
							bl++;
						else if (*ip == ']')
							bl--;
					}
					ip++;
				}
				break;
		}
		if (ip == ep) {
			running = 0;
		} else {
			ip++;
		}
	}

	// Finish up.
	free(cells);
	free(program);
	return 0;
}

// (ANSI) colours for terminal.
#define RED               "\x1B[31m"
#define BK_RED            "\x1B[41m"
#define BK_BLU            "\x1B[44m"
#define MAG               "\x1B[35m"
#define RESET             "\x1B[0m"


/* Give a visual indication of the current state of the program and data. */
void bf_show_state(void) {
	int i;

	// Show cells, with current cell highlighted.
	printf("\n");
	for (i = 0; i < SHOW_CELLS; i++) {
		if (&cells[i] == cp)
			printf(BK_BLU "|%02x|" RESET, cells[i]);
		else
			printf("|%02x|", cells[i]);
	}
	printf("\n\n");

	// Show program, with current instruction highlighted.
	for (i = 0; i < SHOW_PROG; i++) {
		if (&program[i] == ip)
			printf(BK_RED "%c" RESET, program[i]);
		else
			printf("%c", program[i]);
	}
	printf("\n");
}
