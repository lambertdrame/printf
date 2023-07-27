#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

/**
 * struct f_list_s  - struct to link format with function name
 *
 * @fc: format character
 * @f: function name
 */

typedef struct f_list_s
{
	char fc;
	int (*f)(va_list args, unsigned long int num, int recursive
			,  char format, char *buffer, int *buff_ind, int *count, int space);
} f_list;

int _strlen(char *s);
char rot13(char ch);
int print_str(va_list args, unsigned long int num, int recursive
		, char format, char *buffer, int *buff_ind, int *count, int space);
int print_reverse(va_list args, unsigned long int num, int recursive
		, char format, char *buffer, int *buff_ind, int *count, int space);
int print_char(va_list args, unsigned long int num, int recursive
		, char format, char *buffer, int *buff_ind, int *count, int space);
int print_percent(va_list args, unsigned long int num, int recursive
		, char format, char *buffer, int *buff_ind, int *count, int space);
int print_pointer(va_list args, unsigned long int num, int recursive
		, char format, char *buffer, int *buff_ind, int *count, int space);
int print_int(va_list args, unsigned long int num, int recursive
		, char format, char *buffer, int *buff_ind, int *count, int space);
int print_d2boxX(va_list args, unsigned long int num, int recursive
		, char format, char *buffer, int *buff_ind, int *count, int space);
int print_end(va_list args, unsigned long int num, int recursive
		, char format, char *buffer, int *buff_ind, int *count, int space);

int _printf(const char *format, ...);

int format_selector(va_list args, char *buffer, int *buff_ind
		, char format, int *count, int space);
void flush_buffer(char *buffer, int *buff_ind);

#endif

