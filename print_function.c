#include "main.h"

/**
 * print_char - print
 *
 * @ap: pointer
 * @params: params
 *
 * Return: number
 */
int print_char(va_list ap, params_t *params)
{
	char pad_char = ' ';
	unsigned int pad = 1, sum = 0, ch = va_arg(ap, int);

	if (params->minus_flag)
		sum += _putchar(ch);
	while (pad++ < params-width)
		sum += _putchar(pad_char);
	if (!params->minus_flag)
		sum += _putchar(ch);
	return (sum);
}

/**
 * print_int - print
 *
 * @ap: argument
 * @params: parameter
 *
 * Return: 
