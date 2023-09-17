#include "shell.h"

/**
 * parse_args - function that tokenized user input
 *		and parsing it into strings
 *
 * @line_ptr: pointer to user's input line
 *
 * Return: pointer to parsing string
 */
char **parse_args(char *line_ptr)
{
	char *token = NULL, **args = NULL;
	char *comment = NULL, *temp = NULL;
	int i = 0;

	/*allocate memory for pointer that point to first string of user input*/
	args = malloc(sizeof(char *) * BUFSIZE);
	if (!args)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	/* handle case of comment '#' */
	if (line_ptr[0] == '#')
	{
		free(args);
		return (NULL);
	}
	comment = _strchr(line_ptr, '#');
	if (comment && *(comment - 1) == ' ')
	{
		printf("%p\n", line_ptr);
		temp = line_ptr;
		printf("%p\n", temp);
		line_ptr = handle_comment(temp);
		free(temp);
		printf("%p\n", line_ptr);
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

/**
 * handle_comment - handle the commented user input
 *
 * @line_ptr: Raw user input
 *
 * Return: A pointer to string hold the user input
 * filtered from comments.
 */
char *handle_comment(char *line_ptr)
{
	size_t len;
	char *line_cpy = NULL;

	for (len = 0; line_ptr[len] != '#'; len++)
		;

	line_cpy = malloc(sizeof(char) * (len + 1));
	if (!line_cpy)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	_strncpy(line_cpy, line_ptr, len);

	return (line_cpy);
}
