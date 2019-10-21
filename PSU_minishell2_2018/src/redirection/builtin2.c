/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** execute
*/

#include "mysh.h"

void check_write_in_file(mysh_t *exe, char *redir)
{
    if (redir != NULL && my_strcmp(redir, ">") == 0)
        builtin_write_in_file(exe);
}

void check_write_at_end_of_file(mysh_t *exe, char *redir)
{
    if (redir != NULL && my_strcmp(redir, ">>") == 0)
        builtin_write_at_end_of_file(exe);
}

void check_read_from_file(mysh_t *exe, char *redir)
{
    if (redir != NULL && my_strcmp(redir, "<") == 0)
        builtin_read_from_file(exe);
}

void check_read_here_document(mysh_t *exe, char *redir)
{
    if (redir != NULL && my_strcmp(redir, "<<") == 0)
        builtin_read_here_document(exe);
}

void check_pipe(mysh_t *exe, char *redir)
{
    if (redir != NULL && my_strcmp(redir, "|") == 0)
        builtin_pipe(exe);
}
