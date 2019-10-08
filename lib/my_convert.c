/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** convert to octal base
*/

#include "my.h"
#include <stdlib.h>

void dectooct(unsigned int nb)
{
    if (nb < 9)
        my_putchar(nb + 48);
    else if (nb >= 8) {
        dectooct(nb / 8);
        dectooct(nb % 8);
    }
}

void dectobin(unsigned int nb)
{
    int binarr[32];
    int i;
    int j;

    i = 0;
    while (nb > 0) {
        binarr[i] = nb % 2;
        nb /= 2;
        i++;
    } for (j = i - 1; j >= 0; j--)
        my_putnbr(binarr[j]);
}

void dectohex(unsigned int nb)
{
    char *hexarr;
    int i;
    int j;
    int tmp;

    i = 0;
    hexarr = malloc(sizeof(char *) * 100);
    while (nb > 0) {
        tmp = 0;
        tmp = nb % 16;
        if (tmp < 10) {
            hexarr[i] = tmp + 48;
            i++;
        } else {
            hexarr[i] = tmp + 87;
            i++;
        } nb = nb / 16;
    } for (j = i - 1; j >= 0; j--)
        my_putchar(hexarr[j]);
    free(hexarr);
}

void dectobighex(unsigned int nb)
{
    char *arr;
    int i;
    int j;
    int tmp;

    i = 0;
    arr = malloc(sizeof(char *) * 100);
    while (nb > 0) {
        tmp = 0;
        tmp = nb % 16;
        if (tmp < 10) {
            arr[i] = tmp + 48;
            i++;
        } else {
            arr[i] = tmp + 55;
            i++;
        } nb = nb / 16;
    } for (j = i - 1; j >= 0; j--)
        my_putchar(arr[j]);
    free(arr);
}
