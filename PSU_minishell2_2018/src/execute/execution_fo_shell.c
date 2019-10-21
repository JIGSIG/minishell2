/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** main file
*/

#include "mysh.h"

void execution_of_shell(mysh_t *exe, char *all_command)
{
    exe->mysh = init_list_of_command(exe, all_command);
    if (exe->mysh->bad_redir == false)
        lauch_execution(exe);
    else
        display_prompt(exe);
    free_list(exe->mysh);
    exe->len = 0;
}

void free_list(minish *mysh)
{
    minish *tmp;

    tmp = mysh;
    while (mysh) {
        mysh = mysh->next;
        free(mysh);
    } mysh = tmp;
    free (mysh);
}

void lauch_execution(mysh_t *exe)
{
    char *redir;

    while (exe->mysh != NULL) {
        redir = exe->mysh->redir;
        check_semicolon(exe, redir);
        check_write_in_file(exe, redir);
        check_write_at_end_of_file(exe, redir);
        check_read_from_file(exe, redir);
        check_read_here_document(exe, redir);
        check_pipe(exe, redir);
        exe->mysh = exe->mysh->next;
    }
}
