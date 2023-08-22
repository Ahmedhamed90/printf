#include "main.h"

/**
 * _puts - prints a string with newline
 *
 * @str: the string to print
 *
 * Return: void
 */
int _puts(char *str)
{
	char *x = str;

	while (*str)
		_putchar(*str++);
	return (str - x);
}

/**
 * _putchar - writes the character c to stdout
 *
 * @c: the character
 *
 * Return: on success 1.
 */
int _putchar(int c)
{
	static int y;
	static char buf[OUTPUT_BUF_SIZE];

	if (c == BUF_FLUSH || y >= OUTPUT_BUF_SIZE)
	{
		write(1, buf, y);
		y = 0;
	}
	if (c != BUF_FLUSH)
		buf[y++] = c;
	return (1);
}
