/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** create my.h
*/

#ifndef MY_H
#define MY_H
#define _POSIX_SOURCE
#define _GNU_SOURCE
#define _POSIX_C_SOURCE
#define _XOPEN_SOURCE
#define FAIL (84)

#include <stdarg.h>
#include <unistd.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/wait.h>

void    my_putchar(char);
int    my_isneg(int);
int    my_putnbr(int);
void    my_swap(int * , int *);
int    my_putstr(char const *);
int    my_strlen(char const *);
int    my_getnbr(char const *);
void    my_sort_int_array(int *, int);
int    my_compute_power_rec(int, int);
int    my_compute_square_root(int);
int    my_is_prime(int);
int    my_find_prime_sup(int);
char    *my_strcpy(char *, char const *);
char    *my_strncpy (char *, char const *, int);
char    *my_revstr(char *);
char    *my_strstr (char *, char const *);
int    my_strcmp (char const *, char const *);
int    my_strncmp (char const *, char const *, int);
char    *my_strupcase(char *);
char    *my_strlowcase(char *);
char    *my_strcapitalize(char *);
int    my_str_isalpha(char const *);
int    my_str_isnum(char const *);
int    my_str_islower(char const *);
int    my_str_isupper(char const *);
int    my_str_isprintable(char const *);
int    my_showstr(char const *);
int    my_showmem(char const *, int);
char    *my_strcat(char *, char const *);
char    *my_strncat(char *, char const *, int);
void my_printf(const char *format, ...);
int    disp_stdarg(const char *format, va_list ap);
int    sum_stdarg(int i, int nb, ...);
void dectooct(unsigned int nb);
void dectobighex(unsigned int nb);
void dectohex(unsigned int nb);
void dectobin(unsigned int nb);
void my_format(char *str);
void format1(const char *format, va_list ap);
void format2(const char *format, va_list ap);
void format3(const char *format, va_list ap);
void format4(const char *format, va_list ap);
void format_all(const char *format, va_list ap);
char *my_itoa(int num, int base);
char *my_int_to_string(int num, char *str, int base, bool isneg);
int nb_words(char *str);
char *cleaned_str(char *str);
char **word_array(char *str, int nb_of_words);

#endif
