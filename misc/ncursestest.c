/* playing with ncurses. */
/* proof-of-concept of autocompletion in the current working directory.
 * (compile using gcc -lncurses) */

#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

#define BUF_INC 128
#define MAX_LINE 256

/* Return a list of filenames in the current working directory. */
char **get_cwd_contents(void) {
	// Get current working directory (mallocs; requires freeing later).
	int buf_size = BUF_INC;
	char *cwd_buf = malloc(buf_size * sizeof(char));
	while (getcwd(cwd_buf, buf_size) == NULL) {
		buf_size += BUF_INC;
		cwd_buf = realloc(cwd_buf, buf_size * sizeof(char));
	}
	
	// Read contents.
	DIR *cwd_p = opendir(cwd_buf);
	free(cwd_buf);
	struct dirent *ent;
	int names_buf_size = BUF_INC;
	char **filenames = malloc(names_buf_size * sizeof(char *));
	int i;
	for (i = 0; (ent = readdir(cwd_p)) != NULL; i++) {
		filenames[i] = malloc(256 * sizeof(char));
		memcpy(filenames[i], ent->d_name, 256);
		if (i >= names_buf_size) {
			names_buf_size += BUF_INC;
			filenames = realloc(filenames, names_buf_size * sizeof(char *));
		}
	}
	filenames[i] = NULL;

	return filenames;
}

int main(void) {
	int c, i, j, p = 0;
	char **cwd_filenames;
	char buf[MAX_LINE];
	buf[p] = '\0';

	// Disable buffering and echo.
	cbreak();
	noecho();

	// Get filenames in current working directory.
	cwd_filenames = get_cwd_contents();

	// Loop, getting chars and showing them or backspacing.
	while (1) {
		// Get a character.
		while ((c = getch()) == EOF)
			;

		printf("got char: %c\n", c);

		// Either print or remove.
		/*if (c == KEY_BACKSPACE) {
			move(0, 0);
			buf[p--] = 0;
		} else {
			addch(c);
			buf[p++] = c;
		}*/

		// Compute possible completions.
		int best_j = 0;
		char *best = malloc(256 * sizeof(char));
		best[0] = '\0';
		char *filename;
		for (i = 0; (filename = cwd_filenames[i]) != NULL; i++) {
			for (j = 0; buf[j] != '\0'; j++) {
				if (filename[j] != buf[j])
					break;
			}
			if (j > best_j) {
				best_j = j;
				best = filename;
			}
		}
		printf("\nbest match: %s\n", best);
		free(best);
	}

	return 0;
}

/* OK. After this little experiment it seems that ncurses is the wrong tool for this.
 * I should try to somehow do it using readline() / termios. */
