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
	if (str == NULL)
	{
		str = "(null)";
	}

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

/**
 * print_int - prints int
 * @args: The int gotten from the arguments
 *
 * Return: Length of int
 */
int print_int(va_list args)
{
	int num, num2, len = 1, rem, digit, count = 0;

	num = va_arg(args, int);

	num2 = num;
	rem = num;

	while (num2)
	{
		num2 /= 10;
		len *= 10;
		count++;
	}

	len /= 10;

	while (len)
	{
		digit = rem / len;
		rem = rem % len;
		digit = digit + '0';
		write(1, &digit, 1);
		len /= 10;
	}

	return (count);
}
