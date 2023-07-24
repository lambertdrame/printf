#include "main.h"

/**
 * _strlen - gets length of string
 * @s: String
 *
 * Return: length of s
 */
int _strlen(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		;

	return (i);
}

/**
 * print_str - prints string
 * @args: The string gotten from the arguments
 *
 * Return: length of string
 */
int print_str(va_list args)
{
	char *str;
	int len;

	str = va_arg(args, char *);
	len = _strlen(str);
	write(1, str, len);

	return (len);
}

/**
 * print_char - prints char
 * @args: The char gotten from the arguments
 *
 * Return: Nothing
 */
void print_char(va_list args)
{
	int c;

	c = va_arg(args, int);

	write(1, &c, 1);
}
