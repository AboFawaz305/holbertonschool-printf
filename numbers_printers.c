#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * print_octal - print an integer in bace 8 from ap
 * @ap: the arguemnt list
 *
 * Return: the number of printed characters
 */
int print_octal(va_list ap)
{
	unsigned int n = va_arg(ap, unsigned int);
	char buffer[12];
	unsigned int x = 0, c = n, j = 0, size = 0, i = 0;

	do {
		x = c % 8;
		buffer[i] = x + '0';
		c = c / 8;
		i++;
	} while (c != 0);

	size = i;

	while (j < i)
	{
		unsigned int temp = buffer[j];

		buffer[j] = buffer[i - 1];
		buffer[i - 1] = temp;
		i--;
		j++;
	}

	return (write(1, buffer, size));
}

/**
 * print_binary - print an integer in bace 2 from ap
 * @ap: the arguemnt list
 *
 * Return: the number of printed characters
 */
int print_binary(va_list ap)
{
	unsigned long int n = va_arg(ap, unsigned long int);
	char buffer[65];
	unsigned long int x = 0, c = n, j = 0, size = 0, i = 0;

	do {
		x = c % 2;
		buffer[i] = x + '0';
		c = c / 2;
		i++;
	} while (c != 0);

	size = i;

	while (j < i)
	{
		char temp = buffer[j];

		buffer[j] = buffer[i - 1];
		buffer[i - 1] = temp;
		i--;
		j++;
	}

	return (write(1, buffer, size));
}

/**
 * print_hex - print an integer in bace 16 from ap
 * @ap: the arguemnt list
 *
 * Return: the number of printed characters
 */
int print_hex(va_list ap)
{
	unsigned int n = va_arg(ap, unsigned int);
	char buffer[12];
	unsigned int x = 0, c = n, j = 0, size = 0, i = 0;

	do {
		x = c % 16;
		if (x < 10)
		{
			buffer[i] = x + '0';
		}
		if (x >= 10)
		{
			buffer[i] =  (x - 10) + 'A';
		}
		c = c / 16;
		i++;
	} while (c != 0);

	size = i;

	while (j < i)
	{
		unsigned int temp = buffer[j];

		buffer[j] = buffer[i - 1];
		buffer[i - 1] = temp;
		i--;
		j++;
	}

	return (write(1, buffer, size));
}

/**
 * print_hex_small - print an integer in bace 16 from ap
 * @ap: the arguemnt list
 *
 * Return: the number of printed characters
 */
int print_hex_small(va_list ap)
{
	unsigned int n = va_arg(ap, unsigned int);
	char buffer[12];
	unsigned int x = 0, c = n, j = 0, size = 0, i = 0;

	do {
		x = c % 16;
		if (x < 10)
		{
			buffer[i] = x + '0';
		}
		if (x >= 10)
		{
			buffer[i] =  (x - 10) + 'a';
		}
		c = c / 16;
		i++;
	} while (c != 0);

	size = i;

	while (j < i)
	{
		unsigned int temp = buffer[j];

		buffer[j] = buffer[i - 1];
		buffer[i - 1] = temp;
		i--;
		j++;
	}

	return (write(1, buffer, size));
}
