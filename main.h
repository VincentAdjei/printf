#ifndef MAIN_H_PRINTF
#define MAIN_H_PRINTF

#include<stdarg.h>

int _printf(const char *format, ...);
int _putchar(char c);
void handleSpecifier(char s, va_list args, int *count);
void print_string(char *string, int *count);
#endif