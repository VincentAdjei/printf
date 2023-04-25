#include "main.h"

/**
 * is_printable - Determines if a character is printable.
 *
 * @c: The character to be evaluated.
 *
 * Return: 1 if the character is printable, 0 otherwise.
 */
int is_printable(char c)
{
  if (c >= 32 && c < 127) {
    return 1;
  }
  return 0;
}

/**
 * append_hex_code - Appends ASCII code in hexadecimal format to buffer.
 *
 * @buffer: Array of characters.
 * @i: Index at which to start appending.
 * @ascii_code: ASCII code to be appended.
 *
 * Return: Always returns 3.
 */
int append_hex_code(char ascii_code, char buffer[], int i)
{
  char map_to[] = "0123456789ABCDEF";
  int abs_code = ascii_code >= 0 ? ascii_code : -ascii_code;

  buffer[i++] = '\';
  buffer[i++] = 'x';
  buffer[i++] = map_to[abs_code / 16];
  buffer[i] = map_to[abs_code % 16];

  return 3;
}

/**
 * is_digit - Determines if a character is a digit.
 *
 * @c: The character to be evaluated.
 *
 * Return: 1 if the character is a digit, 0 otherwise.
 */
int is_digit(char c)
{
  if (c >= '0' && c <= '9') {
    return 1;
  }
  return 0;
}

/**
 * convert_to_signed - Casts a number to a signed integer of the specified size.
 *
 * @num: The number to be casted.
 * @size: The size of the integer to which the number should be casted.
 *
 * Return: The casted value of the number.
 */
long int convert_to_signed(long int num, int size)
{
  switch (size)
  {
    case S_LONG:
      return num;
    case S_SHORT:
      return (short) num;
    default:
      return (int) num;
  }
}

/**
 * convert_to_unsigned - Casts a number to an unsigned integer of the specified size.
 *
 * @num: The number to be casted.
 * @size: The size of the integer to which the number should be casted.
 *
 * Return: The casted value of the number.
 */
unsigned long int convert_to_unsigned(unsigned long int num, int size)
{
  switch (size)
  {
    case S_LONG:
      return num;
    case S_SHORT:
      return (unsigned short) num;
    default:
      return (unsigned int) num;
  }
}
