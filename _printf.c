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
	int i = 0, count = 0;
	va_list ap;

	va_start(ap, format);

	if (format == NULL)
		return (write(1, "\n", 1));
	while (format[i])h
	{
		if (format[i] == '%')
		{
			switch (format[i + 1])
			{

				case 's':
					count += print_string(ap);
					break;
				case 'c':
					count += print_char(ap);
					break;
				case '%':
					count += write(1, &'%', 1);
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
	va_end(ap);
	return (count);
}

/**
 * print_string - print a string argument
 * @ap: an argument list
 *
 * Return: the number of printed characters
 */
int print_string(va_list ap)
{
	char *s = va_arg(char *);

	return (write(1, s, _strlen(s)));
}

/**
 * _strlen - return the length of s
 * @s: the address of the string
 *
 * Return: the length of s
 */
int _strlen(char *s)
{
	if (*s == '\0')
		return (0);
	return (_strlen(s + 1) + 1);
}

/**
 * print_char - print a character from the arguments
 * @ap: the argument list
 *
 * Return: the number of printed characters
 */
int print_char(va_list ap)
{
	return (write(1, &((char) va_arg(int)), 1));
}

