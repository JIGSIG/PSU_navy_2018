/*
** EPITECH PROJECT, 2019
** navy.h
** File description:
** create navy.h
*/

#ifndef NAVY_H
#define NAVY_H
#define TOUCHED (84)
#define MISSED (77)

#include "my.h"
#include "get_next_line.h"

typedef struct GLOBAL GLOBAL;
struct GLOBAL
{
    int pid;
    int usr1;
    int usr2;
};

GLOBAL DOALL;

typedef struct GAME GAME;
struct GAME
{
    bool p1;
    bool p2;
    bool co;
    char *move;
    char **map;
    char **map2;
    pid_t pid;
    int nb_sig;
    bool status;
};

typedef struct COORD COORD;
struct COORD
{
    int row1;
    int col1;
    int row2;
    int col2;
    char to_put;
};

//MAIN
void init_game(GAME *game);
int start_game(int ac, char **av, GAME *game);

//CONNECTION
void sig_handler(int sig, siginfo_t *info, void *ptr);
int reception(void);
int invitation(pid_t pid);
void co_to_p2(GAME *game);
void co_to_p1(GAME *game, pid_t pid);

//MAP
char **empty_map(void);
void display_map(char **map);
int load_map(char *fp, GAME *game);
int put_on_map(char *pos, GAME *game);
void update_map(GAME *game, int hit, char *move);

//GAME
int play_game(GAME *game);
int player1(GAME *game);
int player2(GAME *game);
void check_status (GAME *game);

//PLAYER 1
int check_input(char *move);
int nb_sig(char *move);
int send_attack(GAME *game);
int hit_ennemy(int nb_sig);
int receive_answer(GAME *game);

//PLAYER 2
int send_it_hit(int hit, int sig, GAME *game);
int hit_me(GAME *game, int nb);
char *translate_sig(int nb);
int receive_attack(GAME *game);

//RIGOR
int check_arg(int ac, char **av);
int check_line(char *line);
int check_file(char *fp);

#endif
