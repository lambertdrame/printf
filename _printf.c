#include "main.h"
/**
 * _printf - Printing something to screen
 * @format: String to print
 * @... : Variadic arguments
 *
 * Return: number of characters printed, -1 if error
 */
int _printf(const char *format, ...)
{
	int i = 0, count = 0;
	va_list args;
	char *buffer;

	buffer = malloc(1024 * (sizeof(*buffer)));
	if (!buffer)
		return (-1);

	if (!format)
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			format_selector(args, buffer, format[i], &count);
		}
		else
		{
			buffer[count] = format[i];
			count++;
		}
		i++;
	}
	va_end(args);
	write(1, buffer, count);
	free(buffer);
	return (count);
}
