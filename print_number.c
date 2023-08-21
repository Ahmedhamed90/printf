#include "main.h"

/**
 * _isdigit - checks
 *
 * @c: character
 *
 * Return: 1 if digit
 */
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - return length
 *
 * @s: string
 *
 * Return: int length
 */
int _strlen(char *s)
{
	int x = 0;

	while (*s++)
		x++;
	return (x);
}

/**
 * print_number - print
 *
 * @str: string
 * @params: params
 *
 * Return: chars
 */
int print_number(char *str, params_t *params)
{
	unsigned int x = _strlen(str);
	int thg = (!params->unsign && *str == '-');

	if (!params->precision && *str == '0' && !str[1])
		str = "";
	if (thg)
	{
		str++;
		x--;
	}
	if (params->precision != UINT_MAX)
		while (i++ < params->precision)
			*--str = '0';
	if (thg)
		*--str ='-';

	if (!params->minus_flag)
		return (print_number_right_shift(str, params));
	else
		return (print_number_left_shift(str, params));
}

/**
 * print_number_right_shift - print
 *
 * @str: the base
 * @params: params
 *
 * Return: char
 */
int print_number_right_shift(char *str, params_t *params)
{
	unsigned int n = 0, thg, thg2, x = _strlen(str);
	char pad_char = ' ';

	if (params->zero_flag && !params->minus_flag)
		pad_char = '0';
	thg = thg2 = (!params->unsig && *str == '-');
	if (thg && x < params->width && pad_char == '0' && !params->minus_flag)
		str++;
	else
		thg = 0;
	if ((params->plus_flag && !thg2) ||
			(!parmas->plus_flag && params->space_flag && !thg2))
		x++;
	if (thg && pad_char == '0')
		n += _putchar('-');
	if (params->plus_flag && !thg2 && pad_char == '0' && !params->unsign)
		n += _putchar('+');
	else if (!params->plus_flag && params->space_flag && !thg2 && 
			!params->unsign && params->zero_flag)
		n += _putchar(' ');
	while (x++ < params->width)
		n += _putchar(pad_char);
	if (thg && pad_char == ' ')
		n += _putchar('-');
	if (params ->plus_flag && ! thg2 && pad_char == ' ' && !params->unsign)
		n += _putchar('+');
	else if (!params->plus_flag && params->space_flag && !thg2 &&
			!params->unsign && !params->zero_flag)
		n += _putchar(' ');
	n += _puts(str);
	return (n);
}

/**
 * print_number_left_shift - print
 *
 * @str: the base
 * @params: params
 *
 * Return: char
 */
int print_number_left_shift(char *str, params_t *params)
{
	unsigned int n = 0, thg, thg2, x = _strlen(str);
	char pad_char = ' ';

	if (params->zero_flag && !params->minus_flag)
		pad_char = '0';
	thg = thg2 = (!params->unsign && *str == '-');
	if (thg && x < params->width && pad_char == '0' && !params->minus_flag)
		str++;
	else
		thg = 0;

	if (params->plus_flag && !thg2 && !params->unsign)
		n += _putchar('+'), x++;
	else if (params->space_flag && !thg2 && !params->unsign)
		n += _putchar(' '), x++;
	n += _puts(str);
	while (x++ < params->width)
		n += _putchar(pad_char);
	return (n);
}
