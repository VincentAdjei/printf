#include "main.h"

/**
 * handleSpecifier - Handles a specific identifier
 * @s: The specifier
 * @args: the list of arguments passed
 * @count: characters counter
 * Return: Nothing
 */
void handleSpecifier(char s, va_list args, int *count)
{
	switch (s)
	{
		case 'c':
		_putchar(va_arg(args, int));
		(*count)++;
		break;

		case '%':
		_putchar('%');
		(*count)++;
		break;

		case 's':
		print_string(va_arg(args, char*), count);
	}
}
