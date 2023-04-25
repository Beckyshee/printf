#include "main.h"
/**
 * env_print_func - finds and returns the conversion specifiers.
 * @s: string
 * @index: index of identifier.
 *
 * Return: identifiers.
 */
int env_print_func(const char *s, int index)
{
	print_t specifiers[] = {
		{"c", print_chr}, {"s", print_str}, {"i", print_int},
		{"d", print_int}, {"b", print_bnr}, {"u", print_unt},
		{"o", print_oct}, {"x", print_hex}, {"X", print_HEX},
		{"S", print_usr}, {"p", print_add}, {"li", prinlint},
		{"ld", prinlint}, {"lu", prinlunt}, {"lo", prinloct},
		{"lx", prinlhex}, {"lX", prinlupx}, {"hi", prinhint},
		{"hd", prinhint}, {"hu", prinhunt}, {"ho", prinhoct},
		{"hx", prinhhex}, {"hX", prinhupx}, {"#o", prinnoct},
		{"#x", prinnhex}, {"#X", prinnupx}, {"#i", print_int},
		{"#d", print_int}, {"#u", print_unt}, {"+i", prinpint},
		{"+d", prinpint}, {"+u", print_unt}, {"+o", print_oct},
		{"+x", print_hex}, {"+X", print_upx}, {" i", prinsint},
		{" d", prinsint}, {" u", print_unt}, {" o", print_oct},
		{" x", print_hex}, {" X", print_upx}, {"R", print_rot13},
		{"r", print_rev}, {"%", print_perc}, {"l", print_prg},
		{"h", print_prg}, {" +i", prinpint}, {" +d", prinpint},
		{"+ i", prinpint}, {"+ d", prinpint}, {" %", print_perc},
		{NULL, NULL},
	};
	int i = 0, j = 0, frst_index;

	frst_index = index;
	while (specifiers[i].type_arg)
	{
		if (s[index] == specifiers[i].type_arg[j])
		{
			if (specifiers[i].type_arg[j + 1] != '\0')
				index++, j++;
			else
				break;
		}
		else
		{
			j = 0;
			i++;
			index = frst_index;
		}
	}
	return (specifiers[i].f);
}
