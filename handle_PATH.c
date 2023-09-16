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
	int i, name_len, is_found = 0;

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
				return (NULL);
			name_len = 0;
			while (name[name_len] != 0)
				name_len++;
			env_var += ++name_len;
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
	char *path, *token;

	path = _getenv("PATH");
	token = strtok(path, ":");
	while (token != NULL)
	{
		token = str_concat(token, "/");
		token = str_concat(token, cmd);
		if (access(token, X_OK) == 0)
		{
			return (token);
		}
		token = strtok(NULL, ":");
	}
	cmd_error(cmd);
	return (NULL);
}
