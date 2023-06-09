#include "main.h"

/**
 * _puts - prints a string of characters
 * @str: string
 * Return:( str-a)
 */
int _puts(char *str)
{
	/*declararing the variables*/
	char *a = str;

	while (*str)
		_putchar(*str++);
	return (str - a);
}

/**
 * _putchar - writes chars to stdout
 * @c: the character
 * Return: On success 1 On error, -1 if null
 */
int _putchar(int c)
{
	static int i;
	static char buf[OUTPUT_BUF_SIZE];

	if (c == BUF_FLUSH || i >= OUTPUT_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}
