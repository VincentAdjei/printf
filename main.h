#ifndef MAIN_H_PRINTF
#define MAIN_H_PRINTF

#include <unistd.h>
#include<stdarg.h>

int _putchar(char c);
int _printf(const char *format, ...);
void handleSpecifier(char s, va_list args, int *count);
void print_string(char *string, int *count);
#endif
