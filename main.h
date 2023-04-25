#ifndef MAIN_H
#define MAIN_H

int _printf(const char *format, ...);
int env_print_func(const char *s, int index);
unsigned int hndl_buff(char *buf, char c, unsigned int i_buff);
int print_rot13(va_list args, char *buf, unsigned int i_buff);
int print_rev(va_list args, char *buf, unsigned int i_buff);

#endif
