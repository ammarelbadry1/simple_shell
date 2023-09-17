#include "shell.h"

/**
 * cmd_execute - function that check user commands
 *		and execute them
 *
 * @tokens: pointer to pointer of strings
 * @lineptr: Raw user input to be freed
 * @env: program environment to be used by env built-in
 *
 * Return: 1 on Success to make infiniti loop continue
 */
int cmd_execute(char **tokens, char *lineptr, char **env)
{
	char *slash = NULL, *path;
	int shell_exit_flag = 1, path_var_access_flag = 0;
	int (*check_builtin)(char **, char *, char **);

	/*handle case of spaces*/
	if (tokens == NULL || tokens[0] == NULL)
		return (1);

	/*check if command built-in*/
	check_builtin = Isbuiltin(tokens[0]);
	if (check_builtin)
	{
		shell_exit_flag = check_builtin(tokens, lineptr, env);
		return (shell_exit_flag);
	}

	/*check if command sent in full path*/
	/*slash = _strchr(tokens[0], '/');*/
	(void) slash;
	if (access(tokens[0], X_OK) == 0)
	{
		shell_exit_flag = fullpath_execution(tokens, lineptr, path_var_access_flag);
		return (shell_exit_flag);
	}
	/*check if command sent not in a full path*/
	else
	{
		path = check_cmd_in_PATH(tokens[0]);
		if (!path)
		{
			cmd_error(tokens[0]);
			free(tokens);
			free(lineptr);
			exit(127);
		}
		else
		{
			tokens[0] = path;
			path_var_access_flag = 1;
			shell_exit_flag = fullpath_execution(tokens, lineptr, path_var_access_flag);
			return (shell_exit_flag);
		}
	}

	return (1);
}

/**
 * fullpath_execution - function that executes
 *		 user command with full path
 *
 * @tokens: pointer to pointer of strings
 * @lineptr: Raw user input to be freed
 *
 * Return: 1 on Success
 */
int fullpath_execution(char **tokens, char *lineptr, int path_var_access_flag)
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
			free(tokens);
			free(lineptr);
			exit(127);
		}
	}
	else
	{
		if (path_var_access_flag)
			free(tokens[0]);
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (1);
}

/**
 * cmd_error - function that handle commands errors
 *
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
	free(error);
}
