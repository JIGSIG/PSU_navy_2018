/*
** EPITECH PROJECT, 2019
** navy
** File description:
** connect players
*/

#include "navy.h"

extern GLOBAL DOALL;

int check_input(char *move)
{
    int i;
    int alphacheck;
    int numcheck;
    char *alpha;
    char *num;

    alpha = malloc(sizeof(char *) * 8);
    num = malloc(sizeof(char *) * 8);
    alpha = "ABCDEFGH";
    num = "12345678";
    if (move == NULL)
        return (404);
    for (i = 0, alphacheck = 0, numcheck = 0; i < 8; i++) {
        if (move[0] == alpha[i])
            alphacheck++;
    } for (i = 0; i < 8; i++)
        if (move[1] == num[i])
            numcheck++;
    if (alphacheck != 1 || numcheck != 1)
        return (84);
    return (0);
}

int nb_sig(char *move)
{
    int row;
    int col;
    int nb;

    row = move[1] - 48;
    col = move[0] - 64;
    nb = ((8 * (row - 1)) + col);
    return (nb);
}

int hit_ennemy(int nb_sig)
{
    if (nb_sig == TOUCHED)
        return (TOUCHED);
    else
        return (MISSED);
}

int send_attack(GAME *game)
{
    int i;
    int n;
    struct timespec tim;
    struct timespec tim2;

    tim.tv_sec = 0;
    tim.tv_nsec = 500;
    DOALL.usr1 = 0;
    DOALL.usr2 = 0;
    n = nb_sig(game->move);
    for (i = 1; i <= n; i++) {
        if (kill(game->pid, SIGUSR1) == -1)
            return (84);
        reception();
        nanosleep(&tim , &tim2);
    } if (kill(game->pid, SIGUSR2) == -1)
        return (84);
    return (0);
}

int receive_answer(GAME *game)
{
    struct timespec tim;
    struct timespec tim2;

    tim.tv_sec = 0;
    tim.tv_nsec = 500;
    DOALL.usr1 = 0;
    DOALL.usr2 = 0;
    while (DOALL.usr1 == 0) {
        reception();
        nanosleep(&tim , &tim2);
        if (kill(game->pid, SIGUSR1) == -1)
            return (84);
    } DOALL.usr1 = 0;
    return (0);
}
