#include "shell.h"

/**
 * _getenv - get an environment variable
 *
 * @name: environment variable to get
 *
 * Return: a pointer to the value of the target variable
 * or NULL if it is not exist.
*/
char *_getenv(char *name)
{
	char *env_var, **env;
	int i, is_found = 0;

	env = environ;
	i = 0;
	while (env[i] != NULL)
	{
		/* _strcmp function returns 0 if the name variable matches */
		/* the first characters of the current environment variable */
		is_found = _strcmp(name, env[i]);
		if (is_found == 0)
		{
			env_var = _strdup(env[i]);
			if (env_var == NULL)
			{
				free(env_var);
				return (NULL);
			}
			return (env_var);
		}
		i++;
	}
	return (NULL);
}

/**
 * check_cmd_in_PATH - checks if a command exists in the PATH variable
 *
 * @cmd: the command to be checked
 *
 * Return: on success returns the command path
 * on failure returns
*/
char *check_cmd_in_PATH(char *cmd)
{
	char *path_var, *cmd_path, *tmp;

	path_var = _getenv("PATH");
	if (path_var == NULL)
	{
		free(path_var);
		return (NULL);
	}
	path_var += 5;
	cmd_path = strtok(path_var, ":");
	path_var -= 5;
	while (cmd_path != NULL)
	{
		tmp = str_concat(cmd_path, "/");
		if (tmp == NULL)
		{
			free(tmp);
			return (NULL);
		}
		cmd_path = str_concat(tmp, cmd);
		free(tmp);
		if (access(cmd_path, X_OK) == 0)
		{
			free(path_var);
			return (cmd_path);
		}
		free(cmd_path);
		cmd_path = strtok(NULL, ":");
	}
	return (NULL);
}
