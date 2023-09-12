#include "shell.h"

/**
 * cmd_execute - function that check user commands
 *		and execute them
 *
 * @tokens: pointer to pointer of strings
 *
 * Return: 1 on Success to make infiniti loop continue
 */
int cmd_execute(char **tokens)
{
	char *slash = NULL;
	int checker = 1;

	/*handle case of empty input*/
	if (tokens == NULL || tokens[0] == NULL)
		return (1);

	/*check if command built-in*/

	/*check if command not in a full path*/

	/*check if command sent in full path*/
	slash = _strchr(tokens[0], '/');
	if (slash)
	{
		checker = fullpath_execution(tokens);
		return (checker);
	}

	return (1);
}

/**
 * fullpath_execution - function that executes
 *		 user command with full path
 *
 * @tokens: pointer to pointer of strings
 *
 * Return: 1 on Success
 */
int fullpath_execution(char **tokens)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execve(tokens[0], tokens, NULL) == -1)
		{
			cmd_error(tokens[0]);
		}
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (1);
}

/**
 * cmd_error - function that handle commands errors
 * @arg: pointer to user command
 *
 * Return: no return
 */
void cmd_error(char *arg)
{
	char *error = NULL;

	error = malloc(_strlen(arg) + 22);
	_strcpy(error, "./hsh: 1: ");
	_strcat(error, arg);
	_strcat(error, ": not found\n");
	write(STDERR_FILENO, error, _strlen(error));

	free(error);
	exit(EXIT_FAILURE);
}
