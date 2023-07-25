#include "main.h"
/**
 * print_int - prints integer to the screen
 * @args: The int gotten from the arguments
 * @format: i or d or u
 * @buffer: write buffer
 * @buff_ind: index of the current position in the buffer
 * @count: pointer to the main printf charcater count
 *
 * Return: Nothing
 */
void print_int(va_list args, char format, char *buffer
		, int *buff_ind, int *count)
{
	int num_i;
	unsigned int num_u, num2, rem, digit;
	long int len = 1;
	char neg = '-';

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
}

/**
 * print_d2boxX - prints binary of decimal
 * @num: The int gotten from the arguments
 * @format: b or o or x or X
 * @buffer: write buffer
 * @buff_ind: index of the current position in the buffer
 * @count: pointer to the count of digits
 *
 * Return: Nothing
 */
void print_d2boxX(unsigned int num, char format, char *buffer
		, int *buff_ind, int *count)
{
	unsigned int digit, base;

	if (format == 'b')
		base = 2;
	if (format == 'o')
		base = 8;
	if (format == 'x' || format == 'X')
		base = 16;
	if (num > (base - 1))
		print_d2boxX(num / base, format, buffer, buff_ind, count);
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
}
