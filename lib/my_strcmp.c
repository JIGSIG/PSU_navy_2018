/*
** EPITECH PROJECT, 2019
** my_strcmp
** File description:
** create my_strcmp
*/

int my_strcmp(char const *S_one, char const *S_two)
{
    while (*S_one && *S_two && *S_one == *S_two) {
        *S_one++;
        *S_two++;
    }
    return (*S_one - *S_two);
}
