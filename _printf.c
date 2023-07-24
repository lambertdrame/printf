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
	int i = 0, j = 0, count = 0, consecutive_percentage = 0;
	va_list args;

	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			consecutive_percentage = 0;
			while (format[i] == ' ')
				i++;
			while (format[i] == '%')
			{
				i++;
				consecutive_percentage++;
			}
			if (consecutive_percentage % 2 == 0)
			{
				for (j = 0; j < consecutive_percentage / 2; j++)
				{
					write(1, "%%", 2);
					count += 2;
				}
				if (format[i] == 's')
					count += print_str(args);
				else if (format[i] == 'c')
				{
					print_char(args);
					count++;
				}
				else if (format[i] == '\0')
				{
					va_end(args);
					return (-1);
				}
				else
				{
					va_end(args);
					return (-1);
				}
			}
			else
			{
				write(1, "%", 1);
				count++;
			}
		}
		else
		{
			write(1, format + i, 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
