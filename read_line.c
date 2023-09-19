#include "shell.h"

/**
 * read_line - function that reads user input
 *
 * Return: pointer to user command
 */
char *read_line(void)
{
	char *buffer = NULL;
	size_t length = 0;
	ssize_t n_read;
	struct shell_info shell_exit;

	/*read user command by getline()*/
	n_read = getline(&buffer, &length, stdin);

	/*handle case of EOF , ctrl+d*/
	if (n_read == -1)
	{
		free(buffer);
		shell_exit.status = 0;
		exit(shell_exit.status);
	}

	return (buffer);
}
