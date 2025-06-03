#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * print_string - print a string argument
 * @ap: an argument list
 *
 * Return: the number of printed characters
 */
int print_string(va_list ap)
{
	char *s = va_arg(ap, char *);

	if (s == NULL)
		return (write(1, "(null)", 6));

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
	char c = (char) va_arg(ap, int);

	return (write(1, &c, 1));
}

/**
 * print_int - print an integer from ap
 * @ap: the arguemnt list
 *
 * Retrun: the number of printed characters
 */
int print_int(va_list ap)
{
	int n = va_arg(ap, int);
	char buffer[12];
	int i = 0, c = n, x = 0, j = 0, size = 0;

	do {
		x = c % 10;
		if (x < 0)
			x *= -1;
		buffer[i] = x + '0';
		c /= 10;
		i++;
	} while (c != 0);

	if (n < 0)
		buffer[i++] = '-';

	size = i;

	while (j < i)
	{
		int temp = buffer[j];

		buffer[j] = buffer[i - 1];
		buffer[i - 1] = temp;
		i--;
		j++;
	}

	return (write(1, buffer, size));
}
