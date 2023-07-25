#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

int _strlen(char *s);
void print_str(va_list args, char format, char *buffer, int *buff_ind, int *count);
void print_char(va_list args, char *buffer, int *buff_ind, int *count);
int _printf(const char *format, ...);
void print_int(va_list args, char format, char *buffer, int *buff_ind
		, int *countn);
void print_d2boxX(unsigned int num, char format, char *buffer
		, int *buff_ind, int *count);
int format_selector(va_list args, char *buffer
		, int *buff_ind, char format, int *count, int space);
void flush_buffer(char *buffer, int *buff_ind);

#endif
