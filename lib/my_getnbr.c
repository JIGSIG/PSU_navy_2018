/*
** EPITECH PROJECT, 2019
** my_getnbr
** File description:
** create my_getnbr
*/

int my_strlen(char const *);

int my_getnbr(char const *str)
{
    int nb;
    int sign;

    sign = 1;
    nb = 0;
    while (*str == '+' || *str == '-') {
        if (*str == '-')
            sign = -1 * sign;
        str++;
    } if (my_strlen(str) > 10)
        return 0;
    else {
        while (*str >= '0' && *str <= '9') {
            nb = *str - 48 + (10 * nb);
            str++;
        } if (nb < 0)
            return 0;
        return (sign * nb);
    }
}
