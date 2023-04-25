#include "main.h"

/**
 * _printf - Prints a formatted string
 * @format: strimg to format
 * Return: int - number of characters printed
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	va_start(args, format);

	if (format == NULL)
		return (-1);

	while (*format)
	{
		if (*format == '%')
		{
			while (*(++format) == ' ')
			{
				continue;
			}
			if (!(*format))
			{
				_print_string("(null)");
				return (-1);
			}
			handleSpecifier(*format, &args, &count);
			format++;
			continue;
		}
		_putchar(*format);
		count++;
		format++;
	}
	_putchar('\0');
	va_end(args);
	return (count);
}
