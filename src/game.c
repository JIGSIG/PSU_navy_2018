/*
** EPITECH PROJECT, 2019
** navy
** File description:
** connect players
*/

#include "navy.h"

extern GLOBAL DOALL;

int play_game(GAME *game)
{
    while (game->status == true) {
        my_printf("\033[00mmy positions:\n");
        display_map(game->map);
        my_printf("\033[00menemy's positions:\n");
        display_map(game->map2);
        while (game->p1 == true) {
            while (player1(game) != 0);
            game->p2 = true;
            game->p1 = false;
        } while (game->p2 == true) {
            while (player2(game) != 0);
            game->p1 = true;
            game->p2 = false;
        } check_status(game);
    } return (0);
}

int player1(GAME *game)
{
    int check;
    static int n = 0;

    if (n == 0) {
        my_printf("\033[00mattack: \033[03m");
        n++;
    } while ((check = check_input(game->move = get_next_line(0))) != 0) {
        if (check == 404)
            return (84);
        my_printf("\033[00mwrong position\nattack: \033[03m");
    } if (send_attack(game) != 0)
        return (84);
    if (receive_answer(game) != 0)
        return (84);
    if (hit_ennemy(DOALL.usr2) == TOUCHED)
        my_printf("\033[00m%s: hit\n\n", game->move);
    else
        my_printf("\033[00m%s: missed\n\n", game->move);
    update_map(game, hit_ennemy(DOALL.usr2), game->move);
    n = 0;
    return (0);
}

int player2(GAME *game)
{
    int it_hit;
    char *msg;

    my_printf("\033[00mwaiting for enemy's attack...\n");
    if (receive_attack(game) != 0)
        return (84);
    if ((it_hit = hit_me(game, DOALL.usr1)) == TOUCHED) {
        my_printf("\033[00m%s: hit\n\n", msg = translate_sig(DOALL.usr1));
        update_map(game, TOUCHED, msg);
    } else {
        my_printf("\033[00m%s: missed\n\n", msg = translate_sig(DOALL.usr1));
        update_map(game, MISSED, msg);
    } if (send_it_hit(it_hit, SIGUSR2, game) != 0)
        return (84);
    return (0);
}

void check_status (GAME *game)
{
    int i;
    int j;

    for (i = 1; i <= 8; i++)
        for (j = 1; j <= 8; j++)
            if (game->map[i][j] != '.' || game->map[i][j] != 'o'
                || game->map[i][j] != 'x')
                return;
    game->status = false;
}
