#include "main.h"

/**
 * print_from_to - prints
 *
 * @start: starting
 * @stop: stopping
 * @except: except
 *
 * Return: number
 */
int print_from_to(char *start, char *stop, char *except)
{
	int sum = 0;

	while (start <= stop)
	{
		if (start != except)
			sum += _putchar(*start);
		start++;
	}
	return (sum);
}

/**
 * print_rev - print
 *
 * @ap: string
 * @params: the parameters
 *
 * Return: number
 */
int print_rev(va_list ap, params_t *params)
{
	int len, sum = 0;
	char *str = va_arg(ap, char *);
	(void)params;

	if (str)
	{
		for (len = 0; *str; str++)
			len++;
		str--;
		for (; len > 0; len--, str--)
			sum += _putchar(*str);
	}
	return (sum);
}

/**
 * print_rot13 - print
 *
 * @ap: string
 * @params: parameters
 *
 * Return: number
 */
int print_rot13(va_list ap, params_t *params)
{
	int f, index;
	int count = 0;
	char arr[] = 
		"NOPQRSTUVWXYZABCDEFGHIJKLM	nopqrstuvwxyzabcdefghijklm";
	char *a = va_arg(ap, char *);
	(void)params;

	f = 0;
	index = 0;
	while (a[f])
	{
		if ((a[f] >= 'A' && a[f] <= 'Z')
				|| (a[f] >= 'a' && a[f] <= 'z'))
		{
			index = a[f] -65;
			count += _putchar(arr[index]);
		}
		else
			count += _putchar(a[f]);
		f++;
	}
	return (count);
}
