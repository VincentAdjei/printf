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
	char *error = "Segmentation fault";

	va_start(args, format);

	if (format == NULL)
	{
		while (*error)
		{
			_putchar(*(error++));
			count++;
		}
		return (count);
	}

	while (*format)
	{
		if (*format == '%')
		{
			handleSpecifier(*(++format), args, &count);
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
