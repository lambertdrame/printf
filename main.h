#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

int _strlen(char *s);
int print_str(va_list args);
void print_char(va_list args);
int _printf(const char *format, ...);
int print_int(va_list args);

#endif
