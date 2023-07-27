#include "main.h"

/**
 * print_reverse - prints reversed string
 * @args: The int gotten from the arguments
 * @num: the number extracted from args
 * @recursive: 1 if recursive initiated otherwise 0
 * @format: i or d or u
 * @buffer: write buffer
 * @buff_ind: index of the current position in the buffer
 * @count: pointer to the main printf charcater count
 * @space: number of spaces
 *
 * Return: -1 if error otherwise 0
 */
int print_reverse(va_list args, unsigned long int num, int recursive
		, char format, char *buffer, int *buff_ind, int *count, int space)
{
	char *str, *null_str = "(null)";
	int len, i;

	(void) space;
	(void) recursive;
	(void) num;
	(void) format;

	str = va_arg(args, char *);
	if (!str)
		str = null_str;
	len = _strlen(str);
	for (i = len - 1; i >= 0; i--)
	{
		buffer[(*buff_ind)++] = str[i];
		if (*buff_ind == 1024)
			flush_buffer(buffer, buff_ind);
		(*count)++;
	}
	return (0);
}

/**
 * rot13 -return rot13 of a character
 * @ch: character to get rot13 for
 *
 * Return: rot13 of the character
 */

char rot13(char ch)
{
	if ('a' <= ch && ch <= 'z')
		return (((ch - 'a' + 13) % 26) + 'a');
	else if ('A' <= ch && ch <= 'Z')
		return (((ch - 'A' + 13) % 26) + 'A');
	else
		return (ch);
}
