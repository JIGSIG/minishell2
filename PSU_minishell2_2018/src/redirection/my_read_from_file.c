/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** my_cd
*/

#include "mysh.h"

void builtin_read_from_file(mysh_t *exe)
{
    int old;
    char *file_name;

    if (exe->mysh->command != NULL) {
        exe->mysh->arg = find_arg(exe->mysh->command, exe->mysh);
        if ((file_name = exe->mysh->next->command) != NULL) {
            old = dup(0);
            read_to_stdin(file_name, O_RDONLY);
            execute(exe);
            dup2(old, 0);
            exe->mysh = exe->mysh->next;
        } display_prompt(exe);
    } else if (exe->mysh->command == NULL && exe->mysh->next == NULL)
        display_prompt(exe);
}
