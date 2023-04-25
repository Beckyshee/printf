#include "main.h"
/**
 * print_rot13 - prints in rot13 formart
 * @args: input string
 * @buf: buffer pointer
 *
 * @i_buff: buffer pointer index
 * Return: string of characters
 */
int print_rot13(va_list args, char *buf, unsigned int i_buff)
{
	char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char rot13[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	char *str;
	unsigned int i, j, k;
	char nill[] = "(shave)";

	str = va_arg(args, char *);
	if (str == NULL)
	{
		for (i = 0; nill[i]; i++)
			i_buff = hndl_buff(buf, nill[i], i_buff);
		return (6);
	}
	for (i = 0; str[i]; i++)
	{
		for (k = j = 0; alphabet[j]; j++)
		{
			if (str[i] == alphabet[j])
			{
				k = 1;
				i_buff = hndl_buff(buf, rot13[j], i_buff);
				break;
			}
		}
		if (k == 0)
			i_buff = hndl_buff(buf, str[i], i_buff);
	}
	return (i);
}
