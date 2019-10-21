/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** my_cd
*/

#include "mysh.h"

char *find_path(mysh_t *exe)
{
    char *path;
    int len;

    len = my_strlen(find_value(search_env(exe, "PWD")));
    path = malloc(sizeof(char) * 2 * (len + 1));
    if (getcwd(path, 2 * (len + 1)) == NULL)
        perror("getcwd error");
    path[2 * (len)] = 0;
    if (path[0] == 0)
        return (NULL);
    return (path);
}

char *find_dir(char *value)
{
    char *dir;
    int i;
    int j;

    for (i = my_strlen(value); value[i] != '/'; i--);
    dir = malloc(sizeof(*dir) * my_strlen(value));
    j = 0;
    while (value[i] != '\0')
        dir[j++] = value[++i];
    return (dir);
}

void try_with_slash(char *line)
{
    char *new;
    int len;
    char old;

    new = line;
    len = my_strlen(line);
    old = new[len - 1];
    new[len - 1] = '/';
    if (chdir(new) == -1) {
        new[len - 1] = old;
        putstr_fd(1, line);
        putstr_fd(1, ": Not a directory.\n");
    }
}

void cd_maker(char *value, mysh_t *exe)
{
    char *path;
    char *dir;

    path = "";
    if (exe->mysh->nb < 2 || my_strcmp(exe->mysh->arg[1], "~") == 0
        || my_strcmp(exe->mysh->arg[1], "~/") == 0) {
        while (my_strcmp(path, value) != 0) {
            path = find_path(exe);
            chdir("..");
        } dir = find_dir(value);
        chdir(dir);
        free(dir);
        free(path);
    } else if (chdir(exe->mysh->arg[1]) == -1)
        try_with_slash(exe->mysh->arg[1]);
}

void builtin_cd(mysh_t *exe)
{
    char *value;

    if (exe->mysh->nb > 2)
        return;
    value = find_value(search_env(exe, "HOME"));
    if (value != NULL)
        cd_maker(value, exe);
    free(value);
}
