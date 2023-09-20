#include "shell.h"

/**
 * _strdup - copy a string to a newely allocated space
 *
 * @s: String to be copied
 *
 * Return: On success a pointer to a duplicated string
 * On failure NULL
*/
char *_strdup(char *s)
{
	char *str = NULL;
	int s_len, i = 0;

	s_len = _strlen(s);
	str = malloc(sizeof(char) * s_len + 1);
	if (str == NULL)
		return (NULL);

	while (*s != '\0' && i < s_len)
	{
		str[i] = *s;
		s++;
		i++;
	}
	str[i] = '\0';

	return (str);
}

/**
 * _strcmp - compares two strings
 *
 * @s1: first string to be compared
 * @s2: second string to be compared
 *
 * Return: comparison integer
*/
int _strcmp(char *s1, char *s2)
{
	int i, diff;

	diff = 0;
	i = 0;
	while (diff == 0)
	{
		/* Modified version of strcmp for our specific use */
		if ((s1[i] == 0)/* && (s2[i] == 0)*/)
			break;
		diff += s1[i] - s2[i];
		i++;
	}
	return (diff);
}

/**
 * str_concat - concatenates two strings
 *
 * @s1: first param
 * @s2: second param
 *
 * Return: a pointer to the concatenated string
*/
char *str_concat(char *s1, char *s2)
{
	char *my_str = NULL;
	int s1_len, s2_len;
	int i;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	s1_len = 0;
	while (s1[s1_len] != 0)
		s1_len++;
	s1_len++;
	s2_len = 0;
	while (s2[s2_len] != 0)
		s2_len++;
	s2_len++;
	my_str = malloc((s1_len + s2_len + 1) * sizeof(char));

	if (my_str == NULL)
	{
		free(my_str);
		return (NULL);
	}

	i = 0;
	while (i < s1_len)
	{
		my_str[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < s2_len)
	{
		my_str[i + s1_len - 1] = s2[i];
		i++;
	}
	return (my_str);
}

/**
 * _puts - prints a string followed by a new line
 *
 * @str: String to be printed
 *
 * Return: no return
*/

void _puts(char *str)
{
	size_t len;

	len = 0;
	while (str[len] != '\0')
		len++;
	write(STDOUT_FILENO, str, len);
	write(STDOUT_FILENO, "\n", 1);
}
