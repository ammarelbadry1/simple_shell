#include "shell.h"

/**
 * main - function that implements simple shell features
 *
 * @argc: number of arguements
 * @argv: pointer of string
 *
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	char *lineptr = NULL, **tokens = NULL;
	(void) argc, (void) argv;

	while (1)
	{
		/*print prompt sign*/
		write(STDIN_FILENO, "($) ", 4);

		lineptr = read_line();
		/*check for empty input if found skip rest of code and show $ again*/
		if (lineptr == NULL || lineptr[0] == '\n')
		{
			free(lineptr);
			continue;
		}

		tokens = parse_args(lineptr);
		cmd_execute(tokens, lineptr);

		free(lineptr);
		free(tokens);
	}

	return (0);
}
