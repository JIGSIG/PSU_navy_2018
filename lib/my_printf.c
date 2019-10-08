/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** main file
*/

#include "my.h"
#include <stdarg.h>
#include <stdio.h>

void my_printf(const char *format, ...)
{
    va_list ap;

    va_start(ap, format);
    disp_stdarg(format, ap);
    va_end(ap);
}

int sum_stdarg(int i, int nb, ...)
{
    int n;
    int sum;
    va_list ap;

    sum = 0;
    va_start(ap, nb);
    if (i == 0)
        for (n = 0; n < nb; n++)
            sum += va_arg(ap, int);
    if (i == 1)
        for (n = 0; n < nb; n++)
            sum += my_strlen(va_arg(ap, char *));
    va_end(ap);
    return (sum);
}

int disp_stdarg(const char *format, va_list ap)
{
    while (*format) {
        if (*format != '%') {
            my_putchar(*format);
            format++;
        } if (*format == '%') {
            format++;
            if (*format == '%')
                my_putchar(*format);
            format1(format, ap);
            format2(format, ap);
            format3(format, ap);
            format4(format, ap);
            format++;
        }
    } return (0);
}
