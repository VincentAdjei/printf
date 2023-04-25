#include "main.h"

/**
 * _printf - Prints a formatted string
 * @format: string to format
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

/**
 * print_buffer - Prints the contents of the buffer if it exists.
 *
 * @buffer: Array of characters.
 * @buffer_len: Length of the buffer.
 *
 * This function prints the contents of the buffer to stdout if it is not empty.
 * It also resets the buffer length to zero.
 */
void print_buffer(char buffer[], int *buffer_len)
{
  if (*buffer_len > 0)
  {
    write(STDOUT_FILENO, buffer, *buffer_len);
  }
  *buffer_len = 0;
}
