#include "main.h"

/**
 * _print_rev - Prints a string in reverse order using recursion
 * @s: pointer to the string array of characters
 * @i: Start index
 * @c: counter
 * Return: Nothing
 */
void _print_rev(char *s, int i, int *c)
{
	if (*(s + i) == '\0')
		return;
	_print_rev(s, i + 1, c);
	_putchar(*(s + i));
	(*c)++;
}

/**
 * print_r - prints a string in reverse
 * @s: pointer to the string
 * @count: counter
 * Return: Nothing
 */
void print_r(char *s, int *count)
{
	_print_rev(s, 0, count);
}
