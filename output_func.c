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
 * Return:0 if not valid format character else 1
 */

int format_selector(va_list args, char *buffer
		, int *buff_ind, char format, int *count, int space)
{
	if (format == 's' || 'S')
		print_str(args, format, buffer, buff_ind, count);
	else if (format == 'c')
		print_char(args, buffer, buff_ind, count);
	else if (format == '%')
	{
		buffer[(*buff_ind)++] = format;
		if (*buff_ind == 1024)
			flush_buffer(buffer, buff_ind);
		(*count)++;
	}
	else if (format == 'd' || format == 'i' || format == 'u')
		print_int(args, format, buffer, buff_ind, count);
	else if (format == 'b' || format == 'o' || format == 'x' || format == 'X')
		print_d2boxX(va_arg(args, unsigned int), format, buffer, buff_ind, count);
	else if (format != '\0')
	{
		buffer[(*buff_ind)++] = '%';
		(*count)++;
		if (space)
		{
			buffer[(*buff_ind)++] = ' ';
			(*count)++;
		}
		buffer[(*buff_ind)++] = format;
		(*count)++;
		if (*buff_ind == 1024)
			flush_buffer(buffer, buff_ind);
	}
	else
		return (0);
	return (1);
}

/**
 * print_str - prints string
 * @args: The string gotten from the arguments
 * @format: s or S
 * @buffer: write buffer
 * @buff_ind: index of the current position in the buffer
 * @count: pointer to the main printf charcater count
 *
 * Return: Nothing
 */

void print_str(va_list args, char format, char *buffer
		, int *buff_ind, int *count)
{
	char *str, *null_str = "(null)";
	int len, i;

	str = va_arg(args, char *);
	if (!str)
		str = null_str;
	len = _strlen(str);
	for (i = 0; i < len; i++)
	{
		if (format == 's')
		{
			buffer[(*buff_ind)++] = str[i];
			if (*buff_ind == 1024)
				flush_buffer(buffer, buff_ind);
			(*count)++;
		}
		else if (format == 'S')
		{
			if ((str[i] > 0 && str[i] < 32) || (str[i] >= 127))
			{
				buffer[(*buff_ind)++] = '\\';
				if (*buff_ind == 1024)
					flush_buffer(buffer, buff_ind);
				buffer[(*buff_ind)++] = 'x';
				if (*buff_ind == 1024)
					flush_buffer(buffer, buff_ind);
				(*count) += 2;
				print_d2boxX((((unsigned int) str[i]) >> 4)
						& 0x0F, 'X', buffer, buff_ind, count);
				print_d2boxX(((unsigned int) str[i]) & 0x0F, 'X', buffer, buff_ind, count);
			}
			else
			{
				buffer[(*buff_ind)++] = str[i];
				if (*buff_ind == 1024)
					flush_buffer(buffer, buff_ind);
				(*count)++;
			}
		}
	}
}

/**
 * print_char - prints char
 * @args: The char gotten from the arguments
 * @buffer: write buffer
 * @buff_ind: index of the current position in the buffer
 * @count: pointer to the main printf charcater count
 *
 * Return: Nothing
 */

void print_char(va_list args, char *buffer, int *buff_ind, int *count)
{
	int c;

	c = va_arg(args, int);
	buffer[(*buff_ind)++] = (char) c;
	if (*buff_ind == 1024)
		flush_buffer(buffer, buff_ind);
	(*count)++;
}
