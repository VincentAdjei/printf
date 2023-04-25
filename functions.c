#include "main.h"

/**
 * print_char - Prints a single character to the buffer
 * @args: List of arguments
 * @buffer: Buffer to store the output string
 * @flags: Flags to modify the output
 * @width: Minimum width of the output
 * @precision: Precision of the output
 * @size: Size modifier for the output
 *
 * Return: Number of characters printed
 */
int print_char(va_list args, char buffer[], int flags, int width, int precision, int size)
{
    char c = va_arg(args, int);
    return handle_write_char(c, buffer, flags, width, precision, size);
}

/************************* PRINT A STRING *************************/

/**
 * print_string - Prints a string
 *
 * @args: List of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Minimum width of the output
 * @precision: Precision specification
 * @size: Size specifier
 *
 * Return: Number of characters printed
 */
int print_string(va_list args, char buffer[], int flags, int width, int precision, int size)
{
    char *str = va_arg(args, char *);
    int length = 0;

    if (str == NULL)
        str = "(null)";

    while (str[length] != '0')
        length++;

    if (precision >= 0 && precision < length)
        length = precision;

    if (width > length)
    {
        int padding = width - length;
        if (flags & F_MINUS)
        {
            write(1, str, length);
            for (int i = 0; i < padding; i++)
                write(1, " ", 1);
        }
        else
        {
            for (int i = 0; i < padding; i++)
                write(1, " ", 1);
            write(1, str, length);
        }
        return width;
    }
    else
    {
        write(1, str, length);
        return length;
    }
}

/************************* PRINT PERCENT SIGN *************************/

/**
 * print_percent - Prints a percent sign
 * @args: List of arguments
 * @buffer: Buffer to store the output string
 * @flags: Flags to modify the output
 * @width: Minimum width of the output
 * @precision: Precision of the output
 * @size: Size modifier for the output
 *
 * Return: Number of characters printed
 */
int print_percent(va_list args, char buffer[], int flags, int width, int precision, int size)
{
    UNUSED(args);
    UNUSED(buffer);
    UNUSED(flags);
    UNUSED(width);
    UNUSED(precision);
    UNUSED(size);

    return write(1, "%%", 1);
}

/************************* PRINT INTEGER *************************/

/**
 * print_int - Prints an integer
 * @args: List of arguments
 * @buffer: Buffer to store the output string
 * @flags: Flags to modify the output
 * @width: Minimum width of the output
 * @precision: Precision of the output
 * @size: Size modifier for the output
 *
 * Return: Number of characters printed
 */
int print_int(va_list args, char buffer[], int flags, int width, int precision, int size)
{
    int i = BUFF_SIZE - 2;
    int is_negative = 0;
    long int n = va_arg(args, long int);
    unsigned long int num;

    n = convert_size_number(n, size);

    if (n == 0)
        buffer[i--] = '0';

    buffer[BUFF_SIZE - 1] = '0';
    num = (unsigned long int)n;

    if (n < 0)
    {
        num = (unsigned long int)((-1) * n);
        is_negative = 1;
    }

    while (num > 0)
    {
        buffer[i--] = (num % 10) + '0';
        num /= 10;
    }

    i++;

    return write_number(is_negative, i, buffer, flags, width, precision, size);
}

/************************* PRINT BINARY *************************/
/**
 * print_binary - Prints an unsigned number in binary format
 * @types: List of arguments
 * Return: Number of characters printed
 */
int print_binary(va_list types)
{
  unsigned int n, m;
  int count = 0;
  char binary[33]; // Maximum number of bits required to represent an unsigned int

  n = va_arg(types, unsigned int);
  m = 2147483648; // (2 ^ 31)
  for (int i = 0; i < 32; i++)
  {
    binary[i] = (n & m) ? '1' : '0';
    m >>= 1;
  }
  binary[32] = '\0'; // Null-terminate the binary string

  // Print the binary string without leading zeros
  int i = 0;
  while (binary[i] == '0' && i < 31)
    i++;
  while (i < 32)
  {
    write(1, &binary[i], 1);
    count++;
    i++;
  }

  return count;
}
