/*
** EPITECH PROJECT, 2019
** sort words
** File description:
** main file
*/

#include "my.h"

char *cleaned_str(char *str)
{
    int i;
    int j;
    char *output;

    i = 0;
    j = 0;
    output = malloc(sizeof(char *) * (my_strlen(str) + 1));
    while (str[i] == ' ' || str[i] == '\t')
        i++;
    output[j] = str[i];
    j++;
    i++;
    while (str[i] != '\0') {
        if (str[i] != ' ' && str[i] != '\t') {
            if (str[i - 1] == ' ' || str[i - 1] == '\t') {
                output[j] = ' ';
                j++;
            } output[j] = str[i];
            j++;
        } i++;
    } return (output);
}

int nb_words(char *str)
{
    int i;
    int nb_of_words;

    i = 0;
    nb_of_words = 0;
    while (str[i] != '\0') {
        if (str[i] == ' ')
            nb_of_words++;
        i++;
    } nb_of_words++;
    return (nb_of_words);
}
