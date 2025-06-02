#include <unistd.h>
#include <stdarg.h>
#include "main.h"

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
			switch (format[i + 1])
			{
				case 's':
					count += print_string(ap);
					break;
				case 'c':
					count += print_char(ap);
					break;
				case '%':
					count += write(1, "%", 1);
					break;
				default:
					count += write(1, format + i, 2);
					break;
			}
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
