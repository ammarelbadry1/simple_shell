#include "shell.h"

/**
 * handle_env - handle built-in commands
 *
 * @env: current environment
 *
 * Return: no return
*/
void handle_env(char **env)
{
	int i = 0;

	while (env[i] != NULL)
	{
		_puts(env[i]);
		i++;
	}
}
