/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** process
*/

#include "mysh.h"

pid_t give_birth(void)
{
    pid_t childID;

    while ((childID = fork()) == -1 && errno == EAGAIN) {
        childID = fork();
    } if (childID == -1) {
        perror("fork error");
        exit(EXIT_FAILURE);
    } return (childID);
}

void do_it(int can_i, mysh_t *exe)
{
    if (can_i == 0) {
        if (execve(*exe->mysh->arg, exe->mysh->arg, exe->envp) == -1) {
            putstr_fd(1, exe->mysh->arg[0]);
            putstr_fd(1, ": Permission denied.\n");
        }
    } else if (can_i == 1) {
        do_exec(exe);
        display_prompt(exe);
    } else {
        putstr_fd(exe->fd, *exe->mysh->arg);
        putstr_fd(exe->fd, ": Command not found.\n");
    }
}

void end_status(mysh_t *exe, int status)
{
    int signo;

    if (WIFEXITED(status) && exe->mysh->next == NULL)
        display_prompt(exe);
    else if (WIFSIGNALED(status)) {
        signo = WTERMSIG(status);
        if (signo == SIGSEGV)
            putstr_fd(1, "Segmentation fault\n");
        if (signo == SIGFPE)
            putstr_fd(1, "Floating exception\n");
        display_prompt(exe);
    }
}
