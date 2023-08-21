#include "main.h"

/**
 * get_specifier - finds the format function
 *
 * @s: the format a string
 *
 * Return: the number
 */
int (*get_specifier(char *s))(va_list ap, params_t *params)
{
	specifier_t specifier[] = {
		{"c", print_char},
		{"d", print_int},
		{"i", print_int},
		{"s", print_string},
		{"%", print_percent},
		{"b", print_binary},
		{"o", print_octal},
		{"u", print_unsigned},
		{"x", print_hex},
		{"X", print_HEX},
		{"p", print_address},
		{"S", print_S},
		{"r", print_rev},
		{"R", print_rot13},
		{NULL, NULL}
	};
	int x = 0;

	while (specifiers[x].specifier)
	{
		if (*s == specifiers[x].specifier[0])
		{
			return (specifiers[x].f);
		}
		x++;
	}
	return (NULL);
}

/**
 * get_print_func - find the format
 *
 * @s: the string
 * @ap: argument
 * @params: the parameters
 *
 * Return: the number
 */
int get_print_func(char *s, va_list ap, params_t *params)
{
	int (*f)(va_list, params_t *) = get_specifier(s);

	if (f)
		return (f(ap, params));
	return (0);
}

/**
 * get_flag - find flag
 *
 * @s: the string
 * @params: the paramters
 *
 * Return: if flag vald
 */
int get_flag(char *s, params_t *params)
{
	int z = 0;

	switch (*s)
	{
		case '+':
			z = params->plus_flag = 1;
			break;
		case ' ':
			z = params->space_flag = 1;
			break;
		case '#':
			z = params->hashtag_flag = 1;
			break;
		case '-':
			z = params->minus_flag = 1;
			break;
		case '0':
			z = params->zero_flag = 1;
			break;
	}
	return (z);
}

/**
 * get_modifier - find
 *
 * @s: the string
 * @params: the parameter
 *
 * Return: valid
 */
int get_modifier(char *s, params_t *params)
{
	int z = 0;

	switch (*s)
	{
		case 'h':
			z = params->h_modifier = 1;
			break;
		case 'l':
			z = params->l_modiffier = 1;
			break;
	}
	return (z);
}

/**
 * get_width - gets the width
 *
 * @s: the string
 * @params: the parameters
 * @ap: the argument
 *
 * Return: new pointer
 */
char *get_width(char *s, params_t *params, va_list ap)
{
	int q = 0;

	if (*s == '*')
	{
		q = va_arg(ap, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			q = q * 10 + (*s++ - '0');
	}
	params->width = q;
	return (s);
}
