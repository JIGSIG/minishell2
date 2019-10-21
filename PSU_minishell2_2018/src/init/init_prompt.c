/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** main file
*/

#include "mysh.h"

int count_slash(char *path)
{
    int i;
    int nb;

    i = -1;
    nb = 0;
    while (path[++i])
        if (path[i] == '/')
            nb++;
    return (nb);
}

char *fill_dir(char *path, int len1, int i)
{
    char *dir;
    int j;
    int nb;

    j = 0;
    nb = count_slash(path);
    dir = malloc(sizeof(char) * (len1 - i));
    if (nb == 2) {
        dir[0] = '~';
        dir[1] = 0;
    } else {
        while (path[++i] != 0)
            dir[j++] = path[i];
    } return (dir);
}

char *fill_prompt(char *dir, int len2)
{
    char *prmt;

    prmt = malloc(sizeof(char) * len2);
    prmt = my_strcpy(prmt, "[seanshell@sean ");
    if (prmt != NULL) {
        prmt = my_strcat(prmt, dir);
        prmt = my_strcat(prmt, "]$ ");
    } return (prmt);
}
