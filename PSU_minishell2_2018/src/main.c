/*
** EPITECH PROJECT, 2019
** mysh
** File description:
** main file
*/

#include "mysh.h"

char *to_redir(char *redir)
{
    int i;
    char *new;

    if (redir == NULL || *redir == 0)
        return (NULL);
    i = -1;
    new = malloc(sizeof(char) * (my_strlen(redir) + 1));
    new[0] = 0;
    while (redir[++i])
        new[i] = redir[i];
    new[i] = 0;
    return (new);
}

int check_arg(int ac, char **av)
{
    if (ac < 1)
        return (84);
    if (my_strcmp(av[0], "./mysh") != 0)
        return (84);
    return (0);
}

char **my_env(char *envp[])
{
    char **cpy;
    int i;
    int len;

    for (len = 0; envp[len] != NULL; len++);
    cpy = malloc(sizeof(char *) * len);
    for (i = 0; i < len; i++)
        cpy[i] = malloc(sizeof(char) * my_strlen(envp[i]));
    i = -1;
    while (envp[++i] != NULL)
        cpy[i] = envp[i];
    return (cpy);
}

int main(int ac, char **av, char **envp)
{
    mysh_t exe;

    exe.envp = envp;
    exe.len = 0;
    exe.fd = 1;
    exe.sigsegv = false;
    exe.sigfpe = false;
    check_arg(ac, av);
    minishell(&exe);
    return (0);
}
