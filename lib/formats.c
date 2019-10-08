/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** formats args
*/

#include "my.h"
#include <stdarg.h>
#include <stdio.h>

void format1(const char *format, va_list ap)
{
    char ch;
    char *str;

    switch (*format) {
    case 'c':
        ch = va_arg(ap, int);
        my_putchar(ch);
        break;
    case 'C':
        ch = va_arg(ap, int);
        my_putchar(ch);
        break;
    case 's':
        str = va_arg(ap, char *);
        my_putstr(str);
        break;
    }
}

void format2(const char *format, va_list ap)
{
    unsigned int nb;

    switch (*format) {
    case 'd':
        my_putnbr(va_arg(ap, int));
        break;
    case 'i':
        my_putnbr(va_arg(ap, int));
        break;
    case 'u':
        nb = va_arg(ap, unsigned int);
        my_putnbr(nb);
        break;
    }
}

void format3(const char *format, va_list ap)
{
    unsigned int nb;

    switch (*format) {
    case 'o':
        nb = va_arg(ap, unsigned int);
        dectooct(nb);
        break;
    case 'x':
        nb = va_arg(ap, unsigned int);
        dectohex(nb);
        break;
    case 'b':
        nb = va_arg(ap, unsigned int);
        dectobin(nb);
        break;
    }
}

void format4(const char *format, va_list ap)
{
    unsigned int nb;
    char *str;

    switch (*format) {
    case 'S':
        str = va_arg(ap, char *);
        my_format(str);
        break;
    case 'p':
        nb = va_arg(ap, unsigned int);
        my_putstr("0x");
        dectohex(nb);
        break;
    case 'X':
        nb = va_arg(ap, unsigned int);
        dectobighex(nb);
        break;
    }
}
