#include <unistd.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf_switch - the switch case for _printf
 * @i: the index of the current character
 * @format: the format string
 * @count: the address of the count
 * @ap: the arguments list
 */
void _printf_switch(int i, const char *format, int *count, va_list ap)
{
	switch (format[i + 1])
	{
		case 's':
			*count += print_string(ap);
			break;
		case 'c':
			*count += print_char(ap);
			break;
		case '%':
			*count += write(1, "%", 1);
			break;
		case 'd':
		case 'i':
			*count += print_int(ap);
			break;
		case 'b':
			*count += print_binary(ap);
			break;
		case 'X':
			*count += print_hex(ap);
			break;
		case 'x':
			*count += print_hex_small(ap);
			break;
		case 'u':
			*count += print_unsignedi(ap);
			break;
		case 'o':
			*count += print_octal(ap);
			break;

		default:
			*count += write(1, format + i, 2);
			break;
	}
}

/**
 * _printf - writes the format string
 * @format: string that could have formatting specefies
 * @arg*: the arguments to print
 *
 * Return: the number of printed characters
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list ap;

	va_start(ap, format);

	if (format == NULL)
		return (-1);

	count = __printf_helper(format, ap);
	va_end(ap);
	return (count);
}

/**
 * __printf_helper - a helper function for _pritnf
 * @format: a format string
 * @ap: the argument list
 *
 * Description: dont use outside _printf.c file this function is meant to be
 * used only by the _printf function.
 * Return: the number of printed characters
 */
int __printf_helper(const char *format, va_list ap)
{
	int i = 0, count = 0;

	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
			{
				va_end(ap);
				return (-1);
			}
			_printf_switch(i, format, &count, ap);
			i += 2;
		}
		else
		{
			count += write(1, format + i, 1);
			i++;
		}
	}

	return (count);
}

