/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** unsetenv
*/

#include "mysh.h"

int error_setenv(mysh_t *exe);

char **remove_env(mysh_t *exe, char *variable)
{
    int i;
    int size;
    char **new;

    for (i = 0; exe->envp[i] != NULL; i++);
    size = i - 1;
    new = malloc(sizeof(char *) * i);
    for (i = 0; i < size; i++)
        new[i] = malloc(sizeof(*new) * my_strlen(exe->envp[i]));
    for (i = 0; my_strcmp(exe->envp[i], variable) != 0; i++)
        new[i] = exe->envp[i];
    while (exe->envp[++i] != NULL)
        new[i - 1] = exe->envp[i];
    return (new);
}

int builtin_unsetenv(mysh_t *exe)
{
    char *variable;

    if (error_setenv(exe) != 0)
        return (-1);
    variable = search_env(exe, exe->mysh->arg[1]);
    if (variable != NULL)
        exe->envp = remove_env(exe, variable);
    return (0);
}
