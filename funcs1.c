#include "main.h"
/**
 * print_int - prints integer to the screen
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
int print_int(va_list args, unsigned long int num, int recursive, char format
		, char *buffer, int *buff_ind, int *count, int space)
{
	long int num_i, len = 1;
	unsigned int num_u, num2, rem, digit;
	char neg = '-';

	num =  recursive + space;
	(void) num;
	if (format == 'u')
		num_u = va_arg(args, unsigned int);
	else
	{
		num_i = va_arg(args, int);
		if (num_i < 0)
		{
			buffer[(*buff_ind)++] = neg;
			if (*buff_ind == 1024)
				flush_buffer(buffer, buff_ind);
			(*count)++;
			num_i = -num_i;
		}
		num_u = num_i;
	}
	num2 = num_u;
	rem = num_u;
	while (num2 >= 10)
	{
		num2 /= 10;
		len *= 10;
	}
	while (len)
	{
		digit = rem / len;
		rem = rem % len;
		digit = digit + '0';
		buffer[(*buff_ind)++] = digit;
		if (*buff_ind == 1024)
			flush_buffer(buffer, buff_ind);
		(*count)++;
		len /= 10;
	}
	return (0);
}

/**
 * print_d2boxX - prints binary of decimal
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
int print_d2boxX(va_list args, unsigned long int num, int recursive
		, char format, char *buffer, int *buff_ind, int *count, int space)
{
	unsigned int digit, base;

	(void) space;

	if (recursive != 1)
	{
		recursive = 1;
		num = va_arg(args, unsigned int);
	}
	else
	{
		(void) args;
	}
	if (format == 'b')
		base = 2;
	if (format == 'o')
		base = 8;
	if (format == 'x' || format == 'X')
		base = 16;
	if (num > (base - 1))
		print_d2boxX(args, num / base, recursive, format
				, buffer, buff_ind, count, space);
	if (base == 16 && (num % base) > 9)
	{
		if (format == 'x')
			digit = (num % base) - 10 + 'a';
		else
			digit = (num % base) - 10 + 'A';
	}
	else
		digit = num % base + '0';
	buffer[(*buff_ind)++] = digit;
	if (*buff_ind == 1024)
		flush_buffer(buffer, buff_ind);
	(*count)++;
	return (0);
}
/**
 * print_percent - prints %
 * @args: The int gotten from the arguments
 * @num: the number extracted from args
 * @recursive: 1 if recursive initiated otherwise 0
 * @format: i or d or u
 * @buffer: write buffer
 * @buff_ind: index of the current position in the buffer
 * @count: pointer to the main printf charcater countA
 * @space: number of spaces
 *
 * Return: -1 if error otherwise 0
 */

int print_percent(va_list args, unsigned long int num, int recursive
		, char format, char *buffer, int *buff_ind, int *count, int space)
{
	(void) args;
	(void) num;
	(void) recursive;
	(void) space;

	buffer[(*buff_ind)++] = format;
	if (*buff_ind == 1024)
		flush_buffer(buffer, buff_ind);
	(*count)++;
	return (0);
}

/**
 * print_end - '\0' end of argument final print
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

int print_end(va_list args, unsigned long int num, int recursive, char format
		, char *buffer, int *buff_ind, int *count, int space)
{
	(void) args;
	(void) num;
	(void) recursive;

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
	return (0);
}

/**
 * print_pointer - prints address
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
int print_pointer(va_list args, unsigned long int num, int recursive
		, char format, char *buffer, int *buff_ind, int *count, int space)
{
	void *address;
	char str[] = "(nil)";
	int len = _strlen(str), i, width = 6;

	(void) space;
	(void) recursive;
	(void) format;

	address = va_arg(args, void *);
	if (!address)
	{
		for (i = 0; i < len; i++)
		{
			buffer[(*buff_ind)++] = str[i];
			if (*buff_ind == 1024)
				flush_buffer(buffer, buff_ind);
			(*count)++;
		}
		return (0);
	}
	num = (unsigned long int) address;
	if (num & 0xffff000000000000)
		width = 8;
	buffer[(*buff_ind)++] = '0';
	if (*buff_ind == 1024)
		flush_buffer(buffer, buff_ind);
	(*count)++;
	buffer[(*buff_ind)++] = 'x';
	if (*buff_ind == 1024)
		flush_buffer(buffer, buff_ind);
	(*count)++;
	for (i = (width * 2 - 1); i >= 0; i--)
	{
		print_d2boxX(args, ((unsigned long int) num >> (4 * i)) & 0x0F
				, 1, 'x', buffer, buff_ind, count, space);
	}

	return (0);
}
