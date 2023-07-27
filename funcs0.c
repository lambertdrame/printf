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
 * flush_buffer - Prints the contents of the buffer and rewind
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void flush_buffer(char *buffer, int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, buffer, *buff_ind);
	*buff_ind = 0;
}

/**
 * format_selector - Prints according to the format selector
 * @args: The string gotten from the arguments
 * @buffer: write buffer
 * @buff_ind: index of the current position in the buffer
 * @format: format character
 * @count: pointer to the main printf charcater count
 * @space: check if there is space between unknown
 *
 * Return: -1 if not valid format character else 0
 */

int format_selector(va_list args, char *buffer
		, int *buff_ind, char format, int *count, int space)
{
	int i = 0, recursive = 0;
	unsigned int num = 0;

	f_list func_list[] = {
		{'c', print_char}, {'s', print_str}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_d2boxX},
		{'u', print_int}, {'o', print_d2boxX}, {'x', print_d2boxX},
		{'X', print_d2boxX}, {'S', print_str}, {'p', print_pointer}
		, {'R', print_str}, {'r', print_reverse}, {'\0', print_end}
	};
	for (i = 0; func_list[i].fc != '\0'; i++)
	{
		if (func_list[i].fc == format)
		{
			return (func_list[i].f(args, num, recursive, format
						, buffer, buff_ind, count, space));
		}
	}
	if (format == '\0')
		return (-1);
	print_end(args, num, recursive, format
				, buffer, buff_ind, count, space);
	return (0);
}

/**
 * print_str - prints string
 * @args: The int gotten from the arguments
 * @num: the number extracted from args
 * @recursive: 1 if recursive initiated otherwise 0
 * @format: i or d or u
 * @buffer: write buffer
 * @buff_ind: index of the current position in the buffer
 * @count: pointer to the main printf charcater count
 * @space: number of previous spaces
 *
 * Return: -1 if error otherwise 0
 */

int print_str(va_list args, unsigned long int num, int recursive, char format
		, char *buffer, int *buff_ind, int *count, int space)
{
	char *str, *null_str = "(null)";
	int len, i;

	(void) space;
	(void) recursive;
	(void) num;

	str = va_arg(args, char *);
	if (!str)
		str = null_str;
	len = _strlen(str);
	for (i = 0; i < len; i++)
	{
		if (format == 'S' && ((str[i] > 0 && str[i] < 32) || str[i] >= 127))
		{
			buffer[(*buff_ind)++] = '\\';
			if (*buff_ind == 1024)
				flush_buffer(buffer, buff_ind);
			(*count)++;
			buffer[(*buff_ind)++] = 'x';
			if (*buff_ind == 1024)
				flush_buffer(buffer, buff_ind);
			(*count)++;
			print_d2boxX(args, ((unsigned int) str[i] >> 4) & 0x0F
					 , 1, 'X', buffer, buff_ind, count, space);
			print_d2boxX(args, ((unsigned int) str[i]) & 0x0F
					 , 1, 'X', buffer, buff_ind, count, space);
		}
		else
		{
			if (format == 'R')
				buffer[(*buff_ind)++] = rot13(str[i]);
			else
				buffer[(*buff_ind)++] = str[i];
			if (*buff_ind == 1024)
				flush_buffer(buffer, buff_ind);
			(*count)++;
		}
	}
	return (0);
}

/**
 * print_char - prints char
 * @args: The int gotten from the arguments
 * @num: the number extracted from args
 * @recursive: 1 if recursive initiated otherwise 0
 * @format: i or d or u
 * @buffer: write buffer
 * @buff_ind: index of the current position in the buffer
 * @count: pointer to the main printf charcater count
 * @space: number of previous spaces
 *
 * Return: -1 if error otherwise 0
 */

int print_char(va_list args, unsigned long int num, int recursive, char format
		, char *buffer, int *buff_ind, int *count, int space)
{
	int c;

	(void) space;
	(void) num;
	(void) recursive;
	(void) format;

	c = va_arg(args, int);
	buffer[(*buff_ind)++] = (char) c;
	if (*buff_ind == 1024)
		flush_buffer(buffer, buff_ind);
	(*count)++;
	return (0);
}
