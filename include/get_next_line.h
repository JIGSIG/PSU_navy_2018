/*
** EPITECH PROJECT, 2019
** get_next_line
** File description:
** header
*/

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef READ_SIZE
#define READ_SIZE (100000)
#endif

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char *get_next_line(int fd);
char *allocation(char *L, char *buff, int *cpt, int size_L);

#endif
