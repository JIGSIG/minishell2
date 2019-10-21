/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** execute
*/

#include "mysh.h"

void stdout_to_write(char *fichier, int flags)
{
    int fd;

    fd = open(fichier, flags, 0600);
    dup2(fd, 1);
    close(fd);
}

void read_to_stdin(char *fichier, int flags)
{
    int fd;

    fd = open(fichier, flags, 0600);
    dup2(fd, 0);
    close(fd);
}
