/*
** EPITECH PROJECT, 2019
** navy
** File description:
** rigor handler
*/

#include "navy.h"

int check_arg(int ac, char **av)
{
    if (ac > 3 || ac < 2)
        return (84);
    if (ac == 2) {
        if (check_file(av[1]) != 0)
            return (84);
    } if (ac == 3) {
        if (my_str_isnum(av[1]) == 0)
            return (84);
        if (check_file(av[2]) != 0)
            return (84);
    } return (0);
}

int check_line2(char *fp)
{
    int fd;
    int i;
    char **line;

    if ((fd = open(fp, O_RDONLY)) == -1)
        return (84);
    line = malloc(sizeof(char *) * 5);
    for (i = 0; i < 4; i++)
        line[i] = malloc(sizeof(char *) * 8);
    for (i = 0; i < 4; i++)
        line[i] = get_next_line(fd);
    close(fd);
    for (i = 0; i < 4; i++) {
        if (line[i][0] != ('2' + i))
            return (84);
    } return (0);
}

int check_file2(char *fp)
{
    int i;
    int fd;
    char buff[1000];
    int read_size;
    int nb_ret;

    i = 0;
    nb_ret = 0;
    if ((fd = open(fp, O_RDONLY)) == -1)
        return (84);
    if ((read_size = read(fd, buff, 1000)) != 32)
        return (84);
    while (buff[i++] != 0)
        if (buff[i] == '\n')
            nb_ret++;
    if (nb_ret != 4)
        return (84);
    close(fd);
    if (check_line2(fp) != 0)
        return (84);
    return (0);
}

int check_line(char *line)
{
    if (my_strlen(line) != 7)
        return (84);
    if (line[2] > line[5])
        return (84);
    if (line[2] != line[5] && line[3] != line[6])
        return (84);
    if (line[2] == line[5] && line[3] >= line[6])
        return (84);
    if (line[0] < '2' || line[0] > '5')
        return (84);
    if (line[1] != ':' || line[4] != ':')
        return (84);
    if (line[2] < 'A' || line[5] < 'A')
        return (84);
    if (line[2] > 'H' || line[5] > 'H')
        return (84);
    if (line[3] < '1' || line[6] < '1')
        return (84);
    if (line[3] > '8' || line[6] > '8')
        return (84);
    return (0);
}

int check_file(char *fp)
{
    int fd;
    char *line;
    int rows;

    rows = 0;
    if ((fd = open(fp, O_RDONLY)) == -1)
        return (84);
    if ((line = get_next_line(fd)) == NULL)
        return (84);
    while (line) {
        rows++;
        if (check_line(line) != 0)
            return (84);
        free(line);
        line = get_next_line(fd);
    } close(fd);
    if (rows != 4)
        return (84);
    if (check_file2(fp) != 0)
        return (84);
    return (0);
}
