/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** process
*/

#include "mysh.h"

char *putstr_fd(int fd, char *str)
{
    int len;

    if (str == NULL)
        return (NULL);
    len = my_strlen(str);
    write(fd, str, len);
    return (str);
}

void child_process(pid_t childID, mysh_t *exe)
{
    int can_i;

    if (childID == 0) {
        if (exe->mysh->builtin == false) {
            can_i = check_access(exe);
            do_it(can_i, exe);
        } exit (EXIT_SUCCESS);
    }
}

void parent_process(pid_t childID, mysh_t *exe)
{
    pid_t endID;
    int status;

    while (1) {
        endID = waitpid(childID, &status, WNOHANG | WUNTRACED);
        if (endID == -1) {
            perror("waitpid error");
            exit(EXIT_FAILURE);
        } else if (endID == childID) {
            end_status(exe, status);
            break;
        }
    }
}
