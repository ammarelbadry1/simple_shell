#include "shell.h"

/**
 * _atoi - function that convert a char to int
 *
 * @str: pointer to string
 *
 * Return: nomber of the converted char
 */
int _atoi(const char *str)
{
	int num = 0, sign = 1, i = 0;

	while (str[i] == ' ')
		i++;

	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
	{
		i++;
	}

	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}

	return (num * sign);
}

/**
*_isdigit - function that checks Is a digit
*
*@str: pointer to user input
*
*Return: 1 if a digit, else 0
*/
int _isdigit(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
		{
			return (0);
		}
		i++;
	}
	return (1);
}
