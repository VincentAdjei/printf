#include "main.h"

/**
* _print_string - prints a string
* @s: string to print
* Return: number of characters printed
*/
int _print_string(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		_putchar(s[i++]);
	}
	return (i);
}
