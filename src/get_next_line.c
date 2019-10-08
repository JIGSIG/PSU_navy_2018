/*
** EPITECH PROJECT, 2019
** get_next_line
** File description:
** main file
*/

#include "get_next_line.h"

char *get_next_line(int fd)
{
    int size_line;
    char *line;
    static char buff[READ_SIZE + 1];
    static int cpt = 0;
    static int bytes = 0;

    line = NULL;
    for (size_line = 0; ; size_line++) {
        if (cpt >= bytes) {
            cpt = 0;
            size_line = 0;
            if ((bytes = read(fd, buff, READ_SIZE)) <= 0)
                return (line);
        } if (buff[cpt + size_line] == '\n')
            return (allocation(line, buff, &cpt, size_line));
        while (buff[cpt + size_line] == '\n')
            cpt++;
        if (cpt + size_line == (bytes - 1))
            line = allocation(line, buff, &cpt, (size_line + 1));
    }
}

char *allocation(char *line, char *buff, int *cpt, int size_line)
{
    int len_line;
    int i;
    const char *temp;

    if (line != NULL) {
        for (temp = line; *temp; ++temp);
        len_line = temp - line;
        if ((line = malloc(len_line + size_line + 1)) == NULL)
            return (NULL);
    } else {
        if ((line = malloc(size_line + 1)) == NULL)
            return (NULL);
        len_line = 0;
    } for (i = 0; i < size_line; i++)
        line[len_line + i] = buff[(*cpt) + i];
    line[len_line + i] = '\0';
    *cpt += size_line + 1;
    return (line);
}
