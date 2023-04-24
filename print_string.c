#include "main.h"

/**
 * print_string - prints a string
 * @string: string to print
 * @count: character counter
 * Return: void
 */
void print_string(char *string, int *count)
{
	*count += strlen(string);

	while (*string)
	{
		_putchar(*string);
		string++;
	}
}
