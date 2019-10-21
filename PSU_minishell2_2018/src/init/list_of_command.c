/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** main file
*/

#include "mysh.h"

bool is_redir(char c)
{
    int i;
    char redirs[5];

    redirs[0] = '<';
    redirs[1] = '>';
    redirs[2] = 59;
    redirs[3] = '|';
    redirs[4] = '\0';
    if (c == '\0')
        return (false);
    for (i = 0; redirs[i] != '\0'; i++)
        if (c == redirs[i])
            return (true);
    return (false);
}

minish *null_list(void)
{
    minish *new;

    new = malloc(sizeof(*new));
    if (new == NULL)
        return (NULL);
    new->arg = NULL;
    new->nb = 0;
    new->command = NULL;
    new->redir = NULL;
    new->bad_redir = false;
    new->no_redir = true;
    new->builtin = false;
    new->seg = false;
    new->next = NULL;
    return (new);
}

minish *create_list(char *command, char *redir)
{
    minish *new;

    new = null_list();
    if (new == NULL)
        return (NULL);
    if (command != NULL && *command != 0)
        new->command = cleaned_str(command);
    if (redir != NULL && *command != 0) {
        new->redir = to_redir(redir);
        new->no_redir = false;
    } return (new);
}

minish *add_to_list(minish *list, char *command, char *redir)
{
    minish *new;
    minish *tmp;

    if (list == NULL)
        return (NULL);
    tmp = list;
    new = create_list(command, redir);
    while (list->next != NULL)
        list = list->next;
    list->next = new;
    list = tmp;
    return (list);
}

minish *init_list_of_command(mysh_t *exe, char *all_command)
{
    int i;
    minish *new;
    char **redir_arr;
    int len;

    if (all_command == NULL)
        return (NULL);
    len = 2 * count_redir(remove_begin_end_redir(all_command)) + 1;
    redir_arr = cleaned_arr(all_command);
    new = create_list(redir_arr[0], redir_arr[1]);
    exe->len++;
    for (i = 2; i <= len; i += 2) {
        if ((i + 2) <= len)
            new = add_to_list(new, redir_arr[i], redir_arr[i + 1]);
        else
            new = add_to_list(new, redir_arr[i], NULL);
        exe->len++;
    } return (new);
}
