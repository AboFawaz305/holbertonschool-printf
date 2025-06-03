#ifndef MAIN_H
#define MAIN_H

int _printf(const char *format, ...);
int print_char(va_list ap);
int print_string(va_list ap);
int print_int(va_list ap);
int _strlen(char *s);
int __printf_helper(const char *format, va_list ap);

#endif
