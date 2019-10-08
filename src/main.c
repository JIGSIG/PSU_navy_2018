/*
** EPITECH PROJECT, 2019
** navy
** File description:
** connect players
*/

#include "navy.h"

extern GLOBAL DOALL;

void init_game(GAME *game)
{
    game->p1 = false;
    game->p2 = false;
    game->co = false;
    game->nb_sig = 0;
    DOALL.usr1 = 0;
    DOALL.usr2 = 0;
    game->map = empty_map();
    game->map2 = empty_map();
}

int start_game(int ac, char **av, GAME *game)
{
    init_game(game);
    if (load_map(av[ac - 1], game) != 0)
        return (84);
    if (ac == 2) {
        game->p1 = true;
        co_to_p2(game);
        game->pid = DOALL.pid;
    } else {
        game->p2 = true;
        co_to_p1(game, game->pid = my_getnbr(av[1]));
    } if (game->co == false) {
        return (84);
    } return (0);
}

int main(int ac, char **av)
{
    GAME game;

    if (check_arg(ac, av) != 0)
        return (84);
    if (start_game(ac, av, &game) != 0)
        return (84);
    if (game.co == true) {
        game.status = true;
        if (play_game(&game) != 0)
            return (84);
        free(game.map);
        free(game.map2);
    } return (0);
}
