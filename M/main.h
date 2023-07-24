#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

int _strlen(char *s);
void print_str(va_list args, char *buffer, int *buff_ind, int *count);
void print_char(va_list args, char *buffer, int *buff_ind, int *count);
int _printf(const char *format, ...);
void print_int(va_list args, char *buffer
		, int *buff_ind, int *count, int is_unsign);
void print_d2b(unsigned int num, char *buffer, int *buff_ind, int *count);
void print_d2o(unsigned int num, char *buffer, int *buff_ind, int *count);
void print_d2x(unsigned int num, char *buffer
		, int *buff_ind, int *count, char letter);
int format_selector(va_list args, char *buffer
		, int *buff_ind, char format, int *count);
void flush_buffer(char *buffer, int *buff_ind);

#endif
