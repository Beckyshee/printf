#include "main.h"

/**
 * _printf - prints the input into standard output
 * @format: a string.
 *
 *
 * Return: number of characters printed.
 */
int _printf(const char *format, ...)
{
	unsigned int i = 0, len = 0, i_buff = 0;
	va_list args;
	int (*function)(va_list, char *, unsigned int);
	char *buffer;

	va_start(args, format), buffer = malloc(sizeof(char) * 1024);
	/*handling null incase of one*/
	if (!format || !buffer || (format[i] == '%' && !format[i + 1]))
		return (-1);
	if (!format[i])
		return (0);
	for (i = 0; format && format[i]; i++)
	{
	/*checking for the percent specifier*/
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
			{	print_buff(buffer, i_buff), free(buffer), va_end(args);
				return (-1);
			}
			else
			{	function = get_print_func(format, i + 1);
				if (function == NULL)
				{
					if (format[i + 1] == ' ' && !format[i + 2])
						return (-1);
					handle_buff(buffer, format[i], i_buff), len++, i--;
				}
				else
				{
					len += function(args, buffer, i_buff);
					i += env_print_func(format, i + 1);
				}
			} i++;
		}
		else
			handl_buff(buffer, format[i], i_buff), len++;
		for (i_buff = len; i_buff > 1024; i_buff -= 1024)
			;
	}
	print_buff(buffer, i_buff), free(buffer), va_end(args);
	return (len);
}
