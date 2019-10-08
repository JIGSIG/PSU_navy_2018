/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** create my_strcat
*/

char *my_strcat(char *dest, char const *src)
{
    char *cpy;

    cpy = dest;
    while (*dest)
        *dest++;
    while (*src) {
        *dest = *src;
        *src++;
        *dest++;
    }
    *dest = '\0';
    return (cpy);
}
