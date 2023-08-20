#include "main.h"

/**
 * get_precision - get the precision
 *
 * @p: the string
 * @params: the parameters
 * @ap: the argument
 *
 * Return: new pointer
 */
char *get_precision(char *p, params_t *params, va_list ap)
{
	int q = 0;

	if (*p != '.')
		return (p);
	p++;
	if (*p == '*')
	{
		q = va_arg(ap, int);
		p++;
	}
	else
	{
		while (_isdigit(*p))
			q = q * 10 + (*p++ - '0');
	}
	params->precision = q;
	return (p);
}
