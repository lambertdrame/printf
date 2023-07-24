#include "main.h"

/**
 * _printf - Printing something to screen
 * @format: String to print
 * @... : arguments
 *
 * Return: number of characters printed, -1 if error
 */
int _printf(const char *format, ...)
{
	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	int i = 0, count = 0;
	va_list args;
	char n = '\n';

	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 's')
				count += print_str(args);
			else if (format[i] == 'c')
			{
				print_char(args);
				count++;
			}
			else if (format[i] == '%')
			{
				write(1, format + i, 1);
				count++;
			}
			else if (format[i] == 'd' || format[i] == 'i')
				count += print_int(args);
		}
		else
		{
			write(1, format + i, 1);
			count++;
		}
		i++;
	}
	va_end(args);
	count--;
	return (count);
}
