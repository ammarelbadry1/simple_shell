#include "shell.h"

/**
 * parse_args - function that tokenized user input
 *		and parsing it into strings
 *
 * @lineptr: pointer to user's input line
 *
 * Return: pointer to parsing string
 */
char **parse_args(char *lineptr)
{
	char *token = NULL, **args = NULL;
	char *comment = NULL;
	int i = 0;

	/*allocate memory for pointer that point to first string of user input*/
	args = malloc(sizeof(char *) * BUFSIZE);
	if (!args)
	{
		perror("malloc");
		return (NULL);
	}

	/* handle case of comment '#' */
	if (lineptr[0] == '#')
	{
		free(args);
		return (NULL);
	}
	comment = _strchr(lineptr, '#');
	if (comment && *(comment - 1) == ' ')
	{
		lineptr = handle_comment(lineptr);
	}

	/*tokenize user command and add null if found one of delimeters*/
	token = strtok(lineptr, DELIMETERS);
	while (token)
	{
		args[i] = token;
		token = strtok(NULL, DELIMETERS);
		i++;
	}
	args[i] = '\0';
	return (args);
}

/**
 * handle_comment - handle the commented user input
 *
 * @lineptr: Raw user input
 *
 * Return: A pointer to string hold the user input
 * filtered from comments.
 */
char *handle_comment(char *lineptr)
{
	size_t len;

	for (len = 0; lineptr[len] != '#'; len++)
		;

	lineptr[len] = '\0';

	return (lineptr);
}
