#include "shell.h"

/**
 * Isbuiltin - map the input command to the corresponding built-in function
 *
 * @command: the command to be mapped
 *
 * Return: On success returns a function pointer to the requested
 * function. On failure returns NULL
 */
int (*Isbuiltin(char *command))(char **, char *, char **)
{
	builtin_t my_builtin[] = {
			{"exit", exit_cmd},
			{"env", handle_env},
			{NULL, NULL}
	};
	int i;

	for (i = 0; my_builtin[i].cmd; i++)
	{
		if (_strcmp(command, my_builtin[i].cmd) == 0)
			return (my_builtin[i].builtin_func);
	}
	return (NULL);
}

/**
 * handle_env - handle built-in commands
 *
 * @tokens: Tokenized user input to be freed
 * @lineptr: Raw user input to be freed
 * @env: current environment
 *
 * Return: no return
*/
int handle_env(char **tokens, char *lineptr, char **env)
{
	int i = 0;
	(void) lineptr, (void) tokens, (void) env, (void) i;

	while (env[i] != NULL)
	{
		_puts(env[i]);
		i++;
	}
	return (1);
}

/**
 * exit_cmd - handle exit command
 *
 * @tokens: Tokenized user input
 * @lineptr: Raw user input to be freed
 * @env: passed just because of the function pointer "Isbuiltin" prototype
 *
 * Return: exit status
 */
int exit_cmd(char **tokens, char *lineptr, char **env)
{
	(void) env;

	if (tokens[1])
	{
		if (_isdigit(tokens[1]) == 0)
		{
			exit_error(tokens[1]);
			free(tokens);
			free(lineptr);
			exit_status = 2;
			exit(exit_status);
		}
		else
		{
			exit_status = _atoi(tokens[1]);
			if (exit_status < 0)
			{
				free(tokens);
				free(lineptr);
				exit_status = 2;
				exit(exit_status);
			}
			free(tokens);
			free(lineptr);
			exit(exit_status);
		}
	}

	free(tokens);
	free(lineptr);
	exit_status = 0;
	exit(exit_status);
}

/**
 * exit_error - check the passed argument to meet a certain criteria
 *
 * @arg: the argument passed
 *
 * Return: no return
 */
void exit_error(char *arg)
{
	char *error = NULL;

	error = malloc(_strlen(arg) + 40);
	if (!error)
	{
		perror("malloc");
		return;
	}
	_strcpy(error, "./hsh: 1: exit: Illegal number: ");
	_strcat(error, arg);
	_strcat(error, "\n");
	write(STDERR_FILENO, error, _strlen(error));

	free(error);
}
