#include "main.h"
/**
 * print_char - prints character
 * @aps: argument pointer
 * @params: the parameters
 * Return: number characters to be printed
 */
int print_char(va_list aps, params_t *params)
{
	char pad_char = ' ';
	unsigned int pad = 1, sum = 0, ch = va_arg(aps, int);

	if (params->minus_flag)
		sum += _putchar(ch);
	while (pad++ < params->width)
		sum += _putchar(pad_char);
	if (!params->minus_flag)
		sum += _putchar(ch);
	return (sum);
}

/**
 * print_int - prints integer
 * @aps: argument pointer
 * @params: the parameters
 * Return: number of characters to be printed
 */
int print_int(va_list aps, params_t *params)
{
	long l;

	if (params->l_modifier)
		l = va_arg(aps, long);
	else if (params->h_modifier)
		l = (short int)va_arg(aps, int);
	else
		l = (int)va_arg(aps, int);
	return (print_nums(convert(l, 10, 0, params), params));
}

/**
 * print_string - prints string
 * @aps: argument pointer
 * @params: the parameters
 * Return: chars printed
 */
int print_string(va_list aps, params_t *params)
{
	char *str = va_arg(aps, char *), pad_char = ' ';
	unsigned int pad = 0, sum = 0, i = 0, j;

	(void)params;
	switch ((int)(!str))
		case 1:
			str = NULL_STRING;

	j = pad = _strlen(str);
	if (params->precision < pad)
		j = pad = params->precision;

	if (params->minus_flag)
	{
		if (params->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				sum += _putchar(*str++);
		else
			sum += _puts(str);
	}
	while (j++ < params->width)
		sum += _putchar(pad_char);
	if (!params->minus_flag)
	{
		if (params->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				sum += _putchar(*str++);
		else
			sum += _puts(str);
	}
	return (sum);
}

/**
 * print_percent - prints stringto percentage
 * @aps: argument pointer
 * @params: the parameters
 * Return: chars
 */
int print_percent(va_list aps, params_t *params)
{
	(void)aps;
	(void)params;
	return (_putchar('%'));
}

/**
 * print_S - custom format specifier
 * @aps: argument pointer
 * @params: the parameters
 * Return: number
 */
int print_S(va_list aps, params_t *params)
{
	char *str = va_arg(aps, char *);
	char *hex;
	int sum = 0;

	if ((int)(!str))
		return (_puts(NULL_STRING));
	for (; *str; str++)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			sum += _putchar('\\');
			sum += _putchar('x');
			hex = convert(*str, 16, 0, params);
			if (!hex[1])
				sum += _putchar('0');
			sum += _puts(hex);
		}
		else
		{
			sum += _putchar(*str);
		}
	}
	return (sum);
}
