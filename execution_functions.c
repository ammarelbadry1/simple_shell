#include "shell.h"

/**
 * cmd_execute - function that check user commands
 *		and execute them
 *
 * @tokens: pointer to pointer of strings
 *
 * Return: 1 on Success to make infiniti loop continue
 */
int cmd_execute(char **tokens, char *lineptr, char **env)
{
	char *slash = NULL, *path;
	int shell_exit_flag = 1;

	(void) slash;
	/*handle case of spaces*/
	if (tokens == NULL || tokens[0] == NULL)
		return (1);

	/*check if command built-in*/
	if (_strcmp(tokens[0], "exit") == 0)
		return (shell_exit_flag = 0);
	if (_strcmp(tokens[0], "env") == 0)
		handle_env(env);
	/*check if command sent in full path*/
	slash = _strchr(tokens[0], '/');
	if (slash)
	{
		shell_exit_flag = fullpath_execution(tokens, lineptr);
		return (shell_exit_flag);
	}
	/*check if command sent not in a full path*/
	else
	{
		path = check_cmd_in_PATH(tokens[0]);
		tokens[0] = path;
		shell_exit_flag = fullpath_execution(tokens, lineptr);
		return (shell_exit_flag);
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
int fullpath_execution(char **tokens, char *lineptr)
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
			(void) lineptr;
			/*free(tokens);*/
			/*free(lineptr);*/
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

	error = malloc(_strlen(arg) + 40);
	_strcpy(error, "./hsh: 1: ");
	_strcat(error, arg);
	_strcat(error, ": not found\n");
	write(STDERR_FILENO, error, _strlen(error));
	/*exit(127);*/
	free(error);
}
