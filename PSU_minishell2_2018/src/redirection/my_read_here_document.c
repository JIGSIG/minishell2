/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** my_cd
*/

#include "mysh.h"

void create_and_write_tmp(char *delimiter)
{
    int fd;
    char *line;
    int old;

    old = dup(1);
    fd = open("tmp_7326_47_463", O_WRONLY | O_CREAT, 0600);
    dup2(fd, 1);
    close(fd);
    putstr_fd(old, "> ");
    while ((line = get_next_line(0)) != NULL
        && my_strcmp(line, delimiter) != 0) {
        putstr_fd(1, line);
        putstr_fd(1, "\n");
        putstr_fd(old, "> ");
    } dup2(old, 1);
}

void remove_tmp(mysh_t *exe)
{
    int i;
    char **path;
    char **to_delete;

    i = -1;
    to_delete = malloc(sizeof(char *) * 3);
    to_delete[0] = "rm";
    to_delete[1] = "tmp_7326_47_463";
    to_delete[2] = NULL;
    path = find_path2(exe);
    while (path[++i] != NULL) {
        path[i] = my_strcat(path[i], "/");
        path[i] = my_strcat(path[i], "rm");
        if (execve(path[i], to_delete, exe->envp) != -1)
            perror(path[i]);
    }
}

void read_and_unlink_tmp(mysh_t *exe)
{
    int fd;
    int status;

    fd = open("tmp_7326_47_463", O_RDONLY, 0600);
    dup2(fd, 0);
    close(fd);
    if (fork() == 0)
        remove_tmp(exe);
    else
        wait(&status);
}

void builtin_read_here_document(mysh_t *exe)
{
    int old;
    char *delimiter;

    if (exe->mysh->command != NULL) {
        exe->mysh->arg = find_arg(exe->mysh->command, exe->mysh);
        if ((delimiter = exe->mysh->next->command) != NULL) {
            create_and_write_tmp(delimiter);
            old = dup(0);
            read_and_unlink_tmp(exe);
            execute(exe);
            dup2(old, 0);
            exe->mysh = exe->mysh->next;
        } display_prompt(exe);
    } else if (exe->mysh->command == NULL && exe->mysh->next == NULL)
        display_prompt(exe);
}
