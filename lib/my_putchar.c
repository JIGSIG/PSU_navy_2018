/*
** EPITECH PROJECT, 2019
** my_putchar
** File description:
** create my_putchar
*/

#include <unistd.h>

void    my_putchar(char c)
{
    write(1, &c, 1);
}
