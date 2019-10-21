/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** my_cd
*/

#include "mysh.h"

void builtin_semicolon(mysh_t *exe)
{
    if (exe->mysh->command != NULL) {
        exe->mysh->arg = find_arg(exe->mysh->command, exe->mysh);
        execute(exe);
    } else if (exe->mysh->command == NULL && exe->mysh->next == NULL)
        display_prompt(exe);
}
