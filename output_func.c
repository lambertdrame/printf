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
 * format_selector - Prints according to the format selector
 * @args: The string gotten from the arguments
 * @buffer: write buffer
 * @format: format character
 * @count: pointer to the main printf charcater count
 *
 * Return: Nothing
 */

void format_selector(va_list args, char *buffer, char format, int *count)
{
	 if (format == 's')
		 print_str(args, buffer, count);
	 else if (format == 'c')
		 print_char(args, buffer, count);
	 else if (format == '%')
	 {
		 buffer[*count] = format;
		 (*count)++;
	 }
	 else if (format == 'd' || format == 'i')
		 print_int(args, buffer, count, 0);
	 else if (format == 'b')
		 print_d2b(va_arg(args, unsigned int), buffer, count);
	 else if (format == 'u')
		 print_int(args, buffer, count, 1);
	 else if (format == 'o')
		 print_d2o(va_arg(args, unsigned int), buffer, count);
	 else if (format == 'x' || format == 'X')
		 print_d2x(va_arg(args, unsigned int), buffer, count, format);
}

/**
 * print_str - prints string
 * @args: The string gotten from the arguments
 * @buffer: write buffer
 * @count: pointer to the main printf charcater count
 *
 * Return: Nothing 
 */

void print_str(va_list args, char *buffer, int *count)
{
	char *str;
	int len, i;

	str = va_arg(args, char *);
	len = _strlen(str);
	for (i = 0; i < len; i++)
	{
		buffer[*count] = str[i];
		(*count)++;
	}
}

/**
 * print_char - prints char
 * @args: The char gotten from the arguments
 * @buffer: write buffer
 * @count: pointer to the main printf charcater count
 *
 * Return: Nothing
 */

void print_char(va_list args, char *buffer, int *count)
{
	int c;

	c = va_arg(args, int);

	buffer[*count] = (char) c;
	(*count)++;
}
