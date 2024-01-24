/* playing with readline lib.
 * (compile w/ gcc -lreadline) */

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>

int main(void) {
	char *line = readline("<PROMPT> ");

	free(line);
	return 0;
}
