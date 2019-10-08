/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** create my_putstr
*/

#include <unistd.h>
#include <stddef.h>

void my_putchar(char);

void my_putstr(char const *str)
{
    if (str == NULL) {
        write(1, "", 1);
        return;
    } while (*str) {
        my_putchar(*str);
        str++;
    }
}
