#include "main.h"
#include <stdio.h>
#include <limits.h>

/**
 * main - Entry point
 *
 * Return: Always 0
 */

int main(void)
{
        printf("%d\n", 65176);
        _printf("%d\n", 65176);
        printf("%d\n", -777765176);
        _printf("%d\n", -777765176);
        printf("%d\n", 00002);
        _printf("%d\n", 00002);
        printf("%d\n", 0);
        _printf("%d\n", 0);
        printf("%d\n", 7);
        _printf("%d\n", 7);
        printf("%d\n", -2255445);
        _printf("%d\n", -2255445);
        printf("Maximum value of int: %d\n", INT_MAX);
        _printf("Maximum value of int: %d\n", INT_MAX);
        printf("Minimum value of int: %d\n", INT_MIN);
        _printf("Minimum value of int: %d\n", INT_MIN);
        printf("--------------------------------\n");
        printf("%i\n", 65176);
        _printf("%i\n", 65176);
        printf("%i\n", 0);
        _printf("%i\n", 0);
        printf("%i\n", -2255445);
        _printf("%i\n", -2255445);
        printf("Maximum value of int: %i\n", INT_MAX);
        _printf("Maximum value of int: %i\n", INT_MAX);
        printf("Minimum value of int: %i\n", INT_MIN);
        _printf("Minimum value of int: %i\n", INT_MIN);

        return (0);
}
