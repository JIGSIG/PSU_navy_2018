/*
** EPITECH PROJECT, 2019
** my_strlen
** File description:
** create my_strlen
*/

int my_strlen(char const *str)
{
    int len;

    len = 0;
    while (*str) {
        str++;
        len++;
    }
    return (len);
}
