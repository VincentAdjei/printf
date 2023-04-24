#include "main.h"

/**
* _putchar - prints a character to std output
* @c: character to print
* Return: number of characters printed
*/
int _putchar(char c)
{
	return (write(1, &c, 1));
}
