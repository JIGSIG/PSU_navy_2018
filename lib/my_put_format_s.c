/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** my_putstr with additionnal octal base
*/

#include "my.h"

void my_format(char *str)
{
    while (*str) {
        if (*str < 32 || *str >= 127) {
            my_putstr("\\");
            if (*str < 8)
                my_putstr("00");
            if (*str < 64 && *str >= 8)
                my_putchar('0');
            dectooct(*str);
        } else
            my_putchar(*str);
        str++;
    }
}
