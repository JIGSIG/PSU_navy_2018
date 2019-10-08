/*
** EPITECH PROJECT, 2019
** navy
** File description:
** read pos
*/

#include "navy.h"

extern GLOBAL DOALL;

void display_map(char **map)
{
    int i;
    int j;

    my_printf(" |A B C D E F G H\n");
    my_printf("-+---------------\n");
    for (i = 1; i <= 8; i++) {
        my_printf("%d|", i);
        for (j = 1; j <= 8; j++) {
            my_printf("%c", map[i][j]);
            if (j < 8)
                my_printf(" ");
        } my_printf("\n");
    } my_printf("\n");
}

char **empty_map(void)
{
    int i;
    int j;
    char **new;

    new = malloc(sizeof(char *) * 8);
    for (i = 1; i <= 8; i++)
        new[i] = malloc(sizeof(char *) * 8);
    for (i = 1; i <= 8; i++)
        for (j = 1; j <= 8; j++)
            new[i][j] = '.';
    return (new);
}

int put_on_map(char *pos, GAME *game)
{
    int i;
    COORD map;

    map.to_put = pos[0];
    map.col1 = pos[2] - 64;
    map.row1 = pos[3] - 48;
    map.col2 = pos[5] - 64;
    map.row2 = pos[6] - 48;
    if (map.col1 == map.col2) {
        if ((map.row2 - map.row1) + 1 != (pos[0] - 48))
            return (84);
        for (i = map.row1; i <= map.row2; i++)
            game->map[i][map.col1] = map.to_put;
    } else if (map.row1 == map.row2) {
        if ((map.col2 - map.col1) + 1 != (pos[0] - 48))
            return (84);
        for (i = map.col1; i <= map.col2; i++)
            game->map[map.row1][i] = map.to_put;
    } return (0);
}

int load_map(char *fp, GAME *game)
{
    int fd;
    char *pos;

    fd = open(fp, O_RDONLY);
    pos = get_next_line(fd);
    while (pos) {
        if (put_on_map(pos, game) != 0)
            return (84);
        free(pos);
        pos = get_next_line(fd);
    } close(fd);
    return (0);
}

void update_map(GAME *game, int hit, char *move)
{
    char to_put;
    int row;
    int col;

    to_put = 0;
    if (hit == TOUCHED)
        to_put = 'x';
    else if (hit == MISSED)
        to_put = 'o';
    row = move[1] - 48;
    col = move[0] - 64;
    game->map[row][col] = to_put;
    game->map2[row][col] = to_put;
}
