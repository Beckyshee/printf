#include "main.h"

/**
 * check_precision - checks the precision from string
 * @p: pointer to a string
 * @params: parameters
 * @ap: argument pointer
 * Return:  pointer
 */
char *check_precision(char *p, params_t *params, va_list aps)
{
	int d = 0;

	if (*p != '.')
		return (p);
	p++;
	if (*p == '*')
	{
		d = va_arg(aps, int);
		p++;
	}
	else
	{
		while (_isdigit(*p))
			d = d * 10 + (*p++ - '0');
	}

	params->precision = d;
	return (p);
}
