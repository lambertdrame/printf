#include "main.h"

/**
 * print_int - prints integer to the screen
 * @args: The int gotten from the arguments
 * @buffer: write buffer
 * @is_unsign: 0 if int else unsigned
 * @count: pointer to the main printf charcater count
 *
 * Return: Nothing
 */

void print_int(va_list args, char *buffer, int *count, int is_unsign)
{
	int num_i;
	unsigned int num_u, num2, rem, digit;
	long int len = 1;
	char neg = '-';

	if (is_unsign)
	{
		num_u = va_arg(args, unsigned int);
	}
	else
	{
		num_i = va_arg(args, int);
		if (num_i < 0)
		{
			buffer[*count] = neg;
			(*count)++;
			num_i = -num_i;
		}
		num_u = num_i;
	}
	num2 = num_u;
	rem = num_u;

	while (num2)
	{
		num2 /= 10;
		len *= 10;
	}

	len /= 10;
	while (len)
	{
		digit = rem / len;
		rem = rem % len;
		digit = digit + '0';
		buffer[*count] = digit;
		(*count)++;
		len /= 10;
	}
}

/**
 * print_d2b - prints binary of decimal
 * @num: The int gotten from the arguments
 * @buffer: write buffer
 * @count: pointer to the count of digits
 *
 * Return: Nothing
 */
void print_d2b(unsigned int num, char *buffer, int *count)
{
	unsigned int digit;

	if (num > 1)
	{
		print_d2b(num / 2, buffer, count);
	}
	digit = num % 2 + '0';
	buffer[*count] = digit;
	(*count)++;
}

/**
 * print_d2o - prints octal of decimal
 * @num: The int gotten from the arguments
 * @buffer: write buffer
 * @count: pointer to the count of digits
 *
 * Return: Nothing
 */

void print_d2o(unsigned int num, char *buffer, int *count)
{
	unsigned int digit;

	if (num > 7)
	{
		print_d2o(num / 8, buffer, count);
	}
	digit = num % 8 + '0';
	buffer[*count] = digit;
	(*count)++;
}

/**
 * print_d2x - prints hex of decimal
 * @num: The int gotten from the arguments
 * @buffer: write buffer
 * @count: pointer to the count of digits
 * @letter: X or x
 *
 * Return: Nothing
 */

void print_d2x(unsigned int num, char *buffer, int *count, char letter)
{
	unsigned int digit, temp;

	if (num > 15)
	{
		print_d2x(num / 16, buffer, count, letter);
	}
	temp = num % 16;
	if (temp > 9)
	{
		if (letter == 'x')
			digit = (temp - 10) + 'a';
		else
			digit = (temp - 10) + 'A';
	}
	else
	{
		digit = temp + '0';
	}
	buffer[*count] = digit;
	(*count)++;
}
