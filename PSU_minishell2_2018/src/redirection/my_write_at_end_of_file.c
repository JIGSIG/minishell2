/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** my_cd
*/

#include "mysh.h"

void builtin_write_at_end_of_file(mysh_t *exe)
{
    int old;
    char *file_name;

    if (exe->mysh->command != NULL) {
        exe->mysh->arg = find_arg(exe->mysh->command, exe->mysh);
        while (exe->mysh->next->next
            && exe->mysh->next->redir != NULL
            && my_strcmp(exe->mysh->next->redir, ">") == 0) {
            exe->mysh = exe->mysh->next;
        } if ((file_name = exe->mysh->next->command) != NULL) {
            old = dup(1);
            stdout_to_write(file_name,  O_WRONLY | O_CREAT | O_APPEND);
            execute(exe);
            dup2(old, 1);
            exe->mysh = exe->mysh->next;
        } if (exe->mysh->redir == NULL)
            display_prompt(exe);
    } else if (exe->mysh->command == NULL && exe->mysh->next == NULL)
        display_prompt(exe);
}
