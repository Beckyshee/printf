#ifndef PRINTF_MAIN_H
#define PRINTF_MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1

#define FIELD_BUF_SIZE 50

#define NULL_STRING "(null)"

#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/**
 * struct parameters - parameters struct
 *
 * @unsign: flag if unsigned
 * @plus_flag: on if plus_flag
 * @space_flag: if hashtag_flag
 * @hashtag_flag: if _flag specified
 * @zero_flag: flag specified
 * @minus_flag: on if specified
 * @width: field width
 * @precision: field precision
 * @h_modifier: on if its specified
 * @l_modifier: on if its specified
 *
 */

typedef struct parameters
{
	unsigned int unsign			: 1;

	unsigned int plus_flag		: 1;
	unsigned int space_flag		: 1;
	unsigned int hashtag_flag	: 1;
	unsigned int zero_flag		: 1;
	unsigned int minus_flag		: 1;

	unsigned int width;
	unsigned int precision;

	unsigned int h_modifier		: 1;
	unsigned int l_modifier		: 1;
} params_t;

/**
 * struct specifier - Structure struct
 * @specifier: format
 * @f: function
 */
typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, params_t *);
} specifier_t;

/* print_funcs.c module */
int print_char(va_list aps, params_t *params);
int print_percent(va_list aps, params_t *params);
int print_S(va_list aps, params_t *params);
int print_int(va_list aps, params_t *params);
int print_string(va_list aps, params_t *params);

/* _put.c module */
int _puts(char *str);
int _putchar(int c);

/* nums.c module */
char *convert(long int num, int base, int flags, params_t *params);
int print_unsigned(va_list aps, params_t *params);
int print_addresses(va_list aps, params_t *params);

/* specifiers.c module */
int (*check_specifier(char *s))(va_list aps, params_t *params);
int get_modifier(char *s, params_t *params);
char *get_width(char *s, params_t *params, va_list aps);
int get_print_func(char *s, va_list aps, params_t *params);
int get_flag(char *s, params_t *params);

/* conertors.c module */
int print_hex(va_list aps, params_t *params);
int print_HEX(va_list aps, params_t *params);
int print_binary(va_list aps, params_t *params);
int print_octal(va_list aps, params_t *params);

/* print_nums.c module */
int _isdigit(int c);
int _strlen(char *s);
int print_nums(char *str, params_t *params);
int print_right_shift(char *str, params_t *params);
int print_left_shift(char *str, params_t *params);

/* parameters.c module */
void init_params(params_t *params, va_list aps);

/* get_prescion.c modoule */
char *check_precision(char *p, params_t *params, va_list aps);

/* rot_reverse.c module */
int print_from_to(char *start, char *stop, char *except);
int print_rev(va_list aps, params_t *params);
int print_rot13(va_list aps, params_t *params);

/* _prinf.c module */
int _printf(const char *format, ...);

#endif /*PRINTF_MAIN_H*/
