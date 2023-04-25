#include "main.h"

/************************* PRINT UNSIGNED NUMBER *************************/
/**
 * print_unsigned - Prints an unsigned number to the console
 * @types: List of arguments
 * Return: Number of characters printed
 */
int print_unsigned(va_list types)
{
  unsigned long int num = va_arg(types, unsigned long int);
  int count = 0;

  /* Convert the number to the appropriate size */
  num = convert_size_unsgnd(num, size);

  /* If the number is zero, print '0' and return */
  if (num == 0)
  {
    write(1, "0", 1);
    return 1;
  }

  /*  Calculate the number of digits in the number */
  int num_digits = 0;
  unsigned long int temp = num;
  while (temp > 0)
  {
    temp /= 10;
    num_digits++;
  }

  /* Print the digits of the number from right to left */
  char digit;
  while (num > 0)
  {
    digit = (num % 10) + '0';
    write(1, &digit, 1);
    count++;
    num /= 10;
  }

  /* If the number of digits is less than the minimum width, pad with zeros or spaces as necessary */
  int width = get_width();
  if (num_digits < width)
  {
    int num_padding = width - num_digits;
    char padding_char = get_padding_char();
    for (int i = 0; i < num_padding; i++)
    {
      write(1, &padding_char, 1);
      count++;
    }
  }

  return count;
}

/************************* PRINT UNSIGNED NUMBER IN OCTAL *************************/
/**
 * print_unsigned_octal - Prints an unsigned number in octal notation
 * @types: List of arguments
 * Return: Number of characters printed
 */
int print_unsigned_octal(va_list types)
{
  unsigned long int num = va_arg(types, unsigned long int);
  unsigned long int init_num = num;
  int count = 0;

  /* Convert the number to the appropriate size */
  num = convert_size_unsgnd(num, size);

  /* If the number is zero, print '0' and return */
  if (num == 0)
  {
    write(1, "0", 1);
    return 1;
  }

  /* Calculate the digits of the number in octal notation */
  char octal_digits[32];
  int num_digits = 0;
  while (num > 0)
  {
    octal_digits[num_digits] = (num % 8) + '0';
    num /= 8;
    num_digits++;
  }

  /* If the '#' flag is set and the number is not zero, add a leading '0' */
  if (flags & F_HASH && init_num != 0)
  {
    write(1, "0", 1);
    count++;
  }

  /* Print the digits of the number in reverse order */
  for (int i = num_digits - 1; i >= 0; i--)
  {
    write(1, &octal_digits[i], 1);
    count++;
  }

  return count;
}

/************** PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/

/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: Number of characters printed
 */
int print_hexadecimal(va_list types, char buffer[],
       int flags, int width, int precision, int size)
{
 return (print_hexa(types, "0123456789abcdef", buffer,
      flags, 'x', width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/

/**
 * print_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: Number of characters printed
 */
int print_hexa_upper(va_list types, char buffer[],
       int flags, int width, int precision, int size)
{
 return (print_hexa(types, "0123456789ABCDEF", buffer,
      flags, 'X', width, precision, size));
}
/************** PRINT HEXX NUM IN LOWER OR UPPER **************/

/**
 * print_hexa - Prints a hexadecimal number in lower or upper case
 * @types: List of arguments
 * @map_to: Array of values to map the number to
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @flag_ch: Calculates active flags
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: Number of characters printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
       int flags, char flag_ch, int width, int precision, int size)
{
 int i = BUFF_SIZE - 2;
 unsigned long int num = va_arg(types, unsigned long int);
 unsigned long int init_num = num;

 UNUSED(width);

 num = convert_size_unsgnd(num, size);

 if (num == 0)
  buffer[i--] = '0';

 buffer[BUFF_SIZE - 1] = '0';

 while (num > 0)
 {
  buffer[i--] = map_to[num % 16];
  num /= 16;
 }

 if (flags & F_HASH && init_num != 0)
 {
  buffer[i--] = flag_ch;
  buffer[i--] = '0';
 }

 i++;

 return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

