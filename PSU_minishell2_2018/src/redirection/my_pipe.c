/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** my_cd
*/

#include "mysh.h"

void execute_pipe(mysh_t *exe)
{
    int can_i;

    exe->mysh->builtin = false;
    check_exit(exe);
    check_cd(exe);
    check_setenv(exe);
    check_unsetenv(exe);
    if (exe->mysh->builtin == false) {
        can_i = check_access(exe);
        do_it(can_i, exe);
    }
}

void command1(int fd[], mysh_t *exe)
{
    close(fd[0]);
    dup2(fd[1], 1);
    exe->mysh->arg = find_arg(exe->mysh->command, exe->mysh);
    execute_pipe(exe);
}

void command2(int fd[], mysh_t *exe)
{
    close(fd[1]);
    dup2(fd[0], 0);
    exe->mysh->arg = find_arg(exe->mysh->next->command, exe->mysh->next);
    execute_pipe(exe);
}

void piping(mysh_t *exe)
{
    int fd[2];
    pid_t childID;
    int save0;
    int save1;

    save0 = dup(0);
    save1 = dup(1);
    pipe(fd);
    if ((childID = give_birth()) == 0)
        command1(fd, exe);
    else
        command2(fd, exe);
    dup2(save0, 0);
    dup2(save1, 1);
}

void builtin_pipe(mysh_t *exe)
{
    if (exe->mysh->command != NULL) {
        piping(exe);
    } else if (exe->mysh->command == NULL && exe->mysh->next == NULL)
        display_prompt(exe);
}
