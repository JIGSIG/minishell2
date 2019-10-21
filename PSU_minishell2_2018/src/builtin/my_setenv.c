/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** setenv
*/

#include "mysh.h"

char **add_env(mysh_t *exe)
{
    int i;
    int size;
    char **env;

    for (i = 0; exe->envp[i] != NULL; i++);
    size = i + 1;
    env = malloc(sizeof(**env) * (size));
    for (i = 0; i < size - 1; i++)
        env[i] = malloc(sizeof(*env) * my_strlen(exe->envp[i]));
    for (i = 0; i < (size - 1); i++)
        env[i] = exe->envp[i];
    size = my_strlen(exe->mysh->arg[1]) + 1 + my_strlen(exe->mysh->arg[2]);
    env[i] = malloc(sizeof(*env) * size);
    env[i] = my_strcat(env[i], exe->mysh->arg[1]);
    env[i] = my_strcat(env[i], "=");
    env[i] = my_strcat(env[i], exe->mysh->arg[2]);
    env[++i] = NULL;
    return (env);
}

void change_value(mysh_t *exe, char *variable)
{
    int i;
    int j;
    char *new;

    for (i = 0; my_strcmp(exe->envp[i], variable) != 0; i++);
    if ((my_strlen(exe->mysh->arg[1]) + my_strlen(exe->mysh->arg[2]) + 1)
        >= 3000)
        return;
    new = malloc(sizeof(*new) * 3000);
    for (j = 0; exe->envp[i][j] != 61; j++)
        new[j] = exe->envp[i][j];
    new = my_strcat(new, "=");
    new = my_strcat(new, exe->mysh->arg[2]);
    exe->envp[i] = new;
}

int error_setenv(mysh_t *exe)
{
    int i;

    for (i = 1; exe->mysh->arg[i] != NULL; i++) {
        if (exe->mysh->arg[i] == NULL
            || my_str_isalpha(exe->mysh->arg[i]) != 0) {
            putstr_fd(1, "setenv: Variable name must contain ");
            putstr_fd(1, "alphanumeric characters.\n");
            return (84);
        }
    } return (0);
}

int builtin_setenv(mysh_t *exe)
{
    char *variable;

    variable = search_env(exe, exe->mysh->arg[1]);
    if (error_setenv(exe) != 0)
        return (-1);
    if (variable == NULL)
        exe->envp = add_env(exe);
    else
        if (my_strcmp(exe->mysh->arg[3], "0") != 0)
            change_value(exe, variable);
    return (0);
}
