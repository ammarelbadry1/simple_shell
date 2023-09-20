#include "shell.h"

/**
 * main - function that implements simple shell features
 *
 * @argc: number of arguements
 * @argv: pointer of string
 * @env: program environment
 *
 * Return: 0 on success
 */
int main(int argc, char **argv, char **env)
{
	char *lineptr = NULL, **tokens = NULL;
	int shell_exit_flag = 1;
	struct shell_info shell_exit;
	(void) argc, (void) argv;

	shell_exit.status = 0;
	while (shell_exit_flag)
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
		shell_exit_flag = cmd_execute(tokens, lineptr, env);

		_free(2, lineptr, tokens);
	}

	return (shell_exit.status);
}
