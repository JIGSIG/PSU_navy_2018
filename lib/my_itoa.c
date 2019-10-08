/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** my_runner
*/

#include "my.h"

char *my_int_to_string(int num, char *str, int base, bool isneg)
{
    int i;
    int rem;

    i = 0;
    if (num == 0) {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    } if (num < 0 && base == 10) {
        isneg = true;
        num = -num;
    } while (num != 0) {
        rem = num % base;
        str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0';
        num = num/base;
    } if (isneg)
        str[i++] = '-';
    str[i] = '\0';
    str = my_revstr(str);
    return (str);
}

char *my_itoa(int num, int base)
{
    char *str;

    str = malloc(sizeof(*str) * ((num / base) + 1));
    str = my_int_to_string(num, str, base, false);
    return (str);
}
