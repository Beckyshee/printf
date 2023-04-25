#include "main.h"
/**
 * print_rev - prints the string in reverse
 * @args: input string
 * @buf: buffer pointer
 * @i_buff: buffer pointer index
 * Return: string
 */
int print_rev(va_list args, char *buf, unsigned int i_buff)
{
	char *str;
	unsigned int i;
	int j = 0;
	char nill[] = "(evahs)";

	str = va_arg(args, char *);
	if (str == NULL)
	{
		for (i = 0; nill[i]; i++)
			i_buff = hndl_buff(buf, nill[i], i_buff);
		return (6);
	}
	for (i = 0; str[i]; i++)
		;
	j = i - 1;
	for (; j >= 0; j--)
	{
		i_buff = hndl_buff(buf, str[j], i_buff);
	}
	return (i);
}
