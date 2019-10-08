/*
** EPITECH PROJECT, 2019
** navy
** File description:
** connect players
*/

#include "navy.h"

extern GLOBAL DOALL;

void sig_handler(int sig, siginfo_t *info, void *ptr)
{
    DOALL.pid = info->si_pid;
    if (sig == SIGUSR1)
        DOALL.usr1++;
    if (sig == SIGUSR2)
        DOALL.usr2++;
    (void)ptr;
}

int reception(void)
{
    struct sigaction act;

    sigemptyset(&act.sa_mask);
    act.sa_sigaction = &sig_handler;
    act.sa_flags = SA_SIGINFO;
    if (sigaction(SIGUSR1, &act, NULL) == -1) {
        my_printf("ERROR :  SIGUSR1\n");
        return (84);
    } if (sigaction(SIGUSR2, &act, NULL) == -1) {
        my_printf("ERROR :  SIGUSR2\n");
        return (84);
    } return (0);
}

int invitation(pid_t pid)
{
    if (kill(pid, SIGUSR2) != -1)
        return (SIGUSR2);
    return (84);
}

void co_to_p2(GAME *game)
{
    my_printf("my_pid:  %d\n", getpid());
    my_printf("waiting for enemy connection...\n\n");
    reception();
    pause();
    game->co = true;
    my_printf("enemy connected\n\n");
}

void co_to_p1(GAME *game, pid_t pid)
{
    if (invitation(pid) == SIGUSR2) {
        game->co = true;
        my_printf("my_pid:  %d\n", getpid());
        my_printf("successfully connected\n\n");
    }
}
