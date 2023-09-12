#include "shell.h"

/**
 * parse_args - function that tokenized user input
 *		and parsing it into strings
 * @line_ptr: pointer to user's input line
 *
 * Return: pointer to parsing string
 */
char **parse_args(char *line_ptr)
{
	char *token = NULL, **args = NULL;
	int i = 0;

	/*allocate memory for pointer that point to first string of user input*/
	args = malloc(sizeof(char *) * BUFSIZE);
	if (!args)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	/*tokenize user command and add null if found one of delimeters*/
	token = strtok(line_ptr, DELIMETERS);
	while (token)
	{
		args[i] = token;
		token = strtok(NULL, DELIMETERS);
		i++;
	}
	args[i] = '\0';

	return (args);
}
