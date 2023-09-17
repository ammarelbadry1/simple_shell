#include "shell.h"

/**
 * _strchr - function that look for
 * a character in a string
 *
 * @str: string
 * @c: character
 *
 * Return: pointer of first occorunce of a char or NULL
 */
char *_strchr(char *str, char c)
{
	int i = 0;

	while (*(str + i) != '\0')
	{
		if (*(str + i) == c)
			return (str + i);
		i++;
	}
	return (NULL);
}

/**
 * _strlen - function that get string length
 *
 * @str: pointer to string
 *
 * Return: length of string
 */
size_t _strlen(const char *str)
{
	size_t len;

	for (len = 0; str[len] != '\0'; len++)
		;
	return (len);
}

/**
 * _strcpy - function that copy content of src to dest
 *
 * @dest: destination parameter
 * @src: source parameter
 * Return: pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (*src)
	{
		dest[i] = *src;
		i++;
		src++;
	}
	dest[i] = '\0';

	return (dest);
}

/**
 * _strcat - function that concatenates 2 strings
 *
 * @dest: first string
 * @src: second string
 *
 * Return: pointer to dest
 */
char *_strcat(char *dest, const char *src)
{
	int i = 0, j;

	j = _strlen(dest);

	while (*src)
	{
		dest[j + i] = *src;
		i++;
		src++;
	}
	dest[j + i] = '\0';

	return (dest);
}

/**
 * _strncpy - function that copy string
 *  for n bytes
 *
 * @dest: destination string
 * @src: source sting
 * @n: n bytes from src
 *
 * Return: dset string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i = 0;

	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';

	return (dest);
}
