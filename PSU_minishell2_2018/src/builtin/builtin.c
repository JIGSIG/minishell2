/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** execute
*/

#include "mysh.h"

void check_exit(mysh_t *exe)
{
    if (exe->mysh->arg != NULL
        && my_strcmp(*exe->mysh->arg, "exit") == 0)
        exit (0);
}

void check_cd(mysh_t *exe)
{
    if (exe->mysh->arg != NULL
        && my_strcmp(*exe->mysh->arg, "cd") == 0) {
        builtin_cd(exe);
        exe->mysh->builtin = true;
    }
}

void check_setenv(mysh_t *exe)
{
    if (exe->mysh->arg != NULL
        && my_strcmp(*exe->mysh->arg, "setenv") == 0) {
        builtin_setenv(exe);
        exe->mysh->builtin = true;
    }
}

void check_unsetenv(mysh_t *exe)
{
    if (exe->mysh->arg != NULL
        && my_strcmp(*exe->mysh->arg, "unsetenv") == 0) {
        builtin_unsetenv(exe);
        exe->mysh->builtin = true;
    }
}

void check_semicolon(mysh_t *exe, char *redir)
{
    if (redir == NULL || my_strcmp(redir, ";") == 0)
        builtin_semicolon(exe);
}
