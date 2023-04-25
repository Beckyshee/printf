#include "main.h"

/**
 * hndl_buff - concatenates the buffer characters
 * @buf: buffer pointer
 * @c: concantenation
 * @i_buff: buffer index pointer
 * Return: pointer.
 */
unsigned int hndl_buff(char *buf, char c, unsigned int i_buff)
{
	if (i_buff == 1024)
	{
		print_buff(buf, i_buff);
		i_buff = 0;
	}
	buf[i_buff] = c;
	i_buff++;
	return (i_buff);
}
