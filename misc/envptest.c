/* there's something called envp. an array of environment variable values passed into the program at runtime? */

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[], char *envp[]) {
	int i, p = -1, s = -1;
	for (i = 0; envp[i] != NULL; i++) {
		printf("envp[%d]: %s\n", i, envp[i]);
		if (p == -1 && strstr(envp[i], "PATH") == envp[i]) {
			p = i;
		} else if (s == -1 && strstr(envp[i], "SHELL") == envp[i]) {
			s = i;
		}
	}

	char *path = envp[p];

	printf("\nPATH is: ");
	for (i = 0; path[i] != '='; i++)
		;
	i++;
	while (path[i] != '\0') {
		putchar(path[i++]);
	}
	putchar('\n');

	char *shname = envp[s];

	printf("\nYou are using the ");
	for (i = strlen(shname) - 1; shname[i] != '/'; i--)
		;
	i++;
	while (shname[i] != '\0') {
		putchar(shname[i++]);
	}
	printf(" shell.\n");
	return 0;
}
